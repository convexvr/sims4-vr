#include "pch.h"
#include "OpenVR-DirectMode.h"
#include <DirectXMath.h>

#pragma comment (lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")


/**
* Constructor.
***/
OpenVRDirectMode::OpenVRDirectMode()
{
	vireio::debugf("OpenVRDirectMode::OpenVRDirectMode()");
}

void OpenVRDirectMode::Init(IDirect3DDevice9* pActualDevice)
{
	vireio::debugf("OpenVRDirectMode::Init");

	if (initialized) {
		OutputDebugString(L"OpenVRDirectMode already Init'd\n");
		return;
	}

	m_pActualDevice = pActualDevice;


	UINT createDeviceFlags = 0;

#ifdef DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

#ifndef VR_DISABLED

	// Loading the SteamVR Runtime
	vr::EVRInitError eError = vr::VRInitError_None;

	vr::IVRSystem* pHMD = vr::VR_Init(&eError, vr::VRApplication_Scene);

	if (eError != vr::VRInitError_None)
	{
		OutputDebugString(L"[FAIL] Could not initialise OpenVR\n");
		return;
	}


	m_pHMD = vr::OpenVRInternal_ModuleContext().VRSystem();

	if (eError != vr::VRInitError_None)
	{
		return;
	}

	m_pHMD->GetRecommendedRenderTargetSize(&m_nRenderWidth, &m_nRenderHeight);

	float l_left = 0.0f, l_right = 0.0f, l_top = 0.0f, l_bottom = 0.0f;
	m_pHMD->GetProjectionRaw(vr::EVREye::Eye_Left, &l_left, &l_right, &l_top, &l_bottom);

	float r_left = 0.0f, r_right = 0.0f, r_top = 0.0f, r_bottom = 0.0f;
	m_pHMD->GetProjectionRaw(vr::EVREye::Eye_Right, &r_left, &r_right, &r_top, &r_bottom);

	float tanHalfFov[2];

	tanHalfFov[0] = max(-l_left, l_right, -r_left, r_right);
	tanHalfFov[1] = max(-l_top, l_bottom, -r_top, r_bottom);

	m_sTextureBounds[0].uMin = 0.5f + 0.5f * l_left / tanHalfFov[0];
	m_sTextureBounds[0].uMax = 0.5f + 0.5f * l_right / tanHalfFov[0];
	m_sTextureBounds[0].vMin = 0.5f - 0.5f * l_bottom / tanHalfFov[1];
	m_sTextureBounds[0].vMax = 0.5f - 0.5f * l_top / tanHalfFov[1];

	m_sTextureBounds[1].uMin = 0.5f + 0.5f * r_left / tanHalfFov[0];
	m_sTextureBounds[1].uMax = 0.5f + 0.5f * r_right / tanHalfFov[0];
	m_sTextureBounds[1].vMin = 0.5f - 0.5f * r_bottom / tanHalfFov[1];
	m_sTextureBounds[1].vMax = 0.5f - 0.5f * r_top / tanHalfFov[1];

	m_nRenderWidth = m_nRenderWidth / max(m_sTextureBounds[0].uMax - m_sTextureBounds[0].uMin, m_sTextureBounds[1].uMax - m_sTextureBounds[1].uMin);
	m_nRenderHeight = m_nRenderHeight / max(m_sTextureBounds[0].vMax - m_sTextureBounds[0].vMin, m_sTextureBounds[1].vMax - m_sTextureBounds[1].vMin);

	m_nAspect = tanHalfFov[0] / tanHalfFov[1];
	m_nFov = 2.0f * atan(tanHalfFov[1]) * 360 / (3.14159265358979323846 * 2);

	if (!vr::VRCompositor())
	{
		OutputDebugString(L"ERROR: No VRCompositor\n");
		return;
	}

#endif

	// CREATE DEVICE AND SWAP CHAIN
	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE, // the first thing to try, if failed, go to the next
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		//D3D_FEATURE_LEVEL_11_1, // texture size and others..
		D3D_FEATURE_LEVEL_11_0, // texture size and others..
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	IDXGIFactory* DXGIFactory;
	IDXGIAdapter* Adapter;
	if (FAILED(CreateDXGIFactory1(__uuidof(IDXGIFactory), (void**)(&DXGIFactory))))
	{
		vireio::debugf("FAILED TO CREATE DXGIFactory");
		return;
	}

	if (FAILED(DXGIFactory->EnumAdapters(0, &Adapter)))
	{
		vireio::debugf("FAILED TO EnumAdapters");
		return;
	}

	HRESULT errorCode;
	for (unsigned i = 0; i < numDriverTypes; ++i)
	{
		errorCode = D3D11CreateDevice(NULL, driverTypes[i], NULL, createDeviceFlags,
			featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &pDevice, &featureLevel, &pImmediateContext);

		if (SUCCEEDED(errorCode))
		{
			break;
		}
	}

	if (FAILED(errorCode))
	{
		vireio::debugf("FAILED TO CREATE DEVICE AND SWAP CHAIN: %x", errorCode);
		return;
	}

	HRESULT result;

	// CREATE DEPTH STENCIL
	ID3D11Texture2D* pDepthStencil = NULL;
	D3D11_TEXTURE2D_DESC descDepth;
	ZeroMemory(&descDepth, sizeof(descDepth));
	descDepth.Width = m_nRenderWidth;// swapDesc.BufferDesc.Width;
	descDepth.Height = m_nRenderHeight;// swapDesc.BufferDesc.Height;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D32_FLOAT_S8X24_UINT;

	// DXGI_FORMAT_D32_FLOAT_S8X24_UINT
	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D11_USAGE_DEFAULT;
	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;
	result = pDevice->CreateTexture2D(&descDepth, NULL, &pDepthStencil);
	if (FAILED(result))
	{
		vireio::debugf("FAILED TO CREATE pDevice->CreateTexture2D: %x", result);
		return;
	}


	D3D11_DEPTH_STENCIL_DESC dsDesc;
	ZeroMemory(&dsDesc, sizeof(dsDesc));
	// Depth test parameters
	dsDesc.DepthEnable = true;
	dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	dsDesc.DepthFunc = D3D11_COMPARISON_LESS;

	// Stencil test parameters
	dsDesc.StencilEnable = true;
	dsDesc.StencilReadMask = 0xFF;
	dsDesc.StencilWriteMask = 0xFF;

	// Stencil operations if pixel is front-facing
	dsDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	dsDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Stencil operations if pixel is back-facing
	dsDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	dsDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	dsDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// Create depth stencil state
	result = pDevice->CreateDepthStencilState(&dsDesc, &pDSState);
	if (FAILED(result))
	{
		vireio::debugf("FAILED TO CREATE CreateDepthStencilState: %x", errorCode);
		return;
	}

	// Bind depth stencil state
	pImmediateContext->OMSetDepthStencilState(pDSState, 1);

	D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
	ZeroMemory(&descDSV, sizeof(descDSV));
	descDSV.Format = descDepth.Format;// DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
	descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	//descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
	descDSV.Texture2D.MipSlice = 0;

	// Create the depth stencil view
	result = pDevice->CreateDepthStencilView(pDepthStencil, // Depth stencil texture
		&descDSV, // Depth stencil desc
		&pDepthStencilView);  // [out] Depth stencil view

	if (FAILED(result))
	{
		vireio::debugf("FAILED TO CREATE CreateDepthStencilView: %x", errorCode);
		return;
	}

	//VIEWPORT CREATION
	dx11viewport.Width = static_cast<float>(m_nRenderWidth);
	dx11viewport.Height = static_cast<float>(m_nRenderHeight);
	dx11viewport.TopLeftX = 0;
	dx11viewport.TopLeftY = 0;
	dx11viewport.MinDepth = 0.0f;
	dx11viewport.MaxDepth = 1.0f;

	// BIND VIEWPORT
	pImmediateContext->RSSetViewports(1, &dx11viewport);

	if (!vr::VRCompositor())
	{
		vireio::debugf("Compositor initialization failed. \n");
		return;
	}

	// 
	// Initialize the surface queues
	//
	SURFACE_QUEUE_DESC  desc = { 0 };
	desc.Width = m_nRenderWidth;
	desc.Height = m_nRenderHeight;
	desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	desc.NumSurfaces = 4;
	desc.MetaDataSize = 0;
	desc.Flags = SURFACE_QUEUE_FLAG_SINGLE_THREADED;

	HRESULT hr = E_NOTIMPL;

	vireio::debugf("before CreateSurfaceQueue %i %i %x %x \n", m_nRenderWidth, m_nRenderHeight, m_pActualDevice, g_11to9Queue);

	if (FAILED(hr = CreateSurfaceQueue(&desc, m_pActualDevice, &g_11to9Queue)))
	{
		
		vireio::debugf("CreateSurfaceQueue failed with code: %x. \n", hr);
		return;
	}

	// Clone the queue
	SURFACE_QUEUE_CLONE_DESC CloneDesc = { 0 };
	CloneDesc.MetaDataSize = 0;
	CloneDesc.Flags = SURFACE_QUEUE_FLAG_SINGLE_THREADED;
	if (FAILED(hr = g_11to9Queue->Clone(&CloneDesc, &g_9to11Queue)))
	{
		vireio::debugf("g_ABQueue->Clone failed. \n");
		return;
	}



	if (FAILED(hr = g_11to9Queue->OpenProducer(pDevice, &g_9Producer)))
	{
		vireio::debugf("g_BAQueue->OpenProducer failed. \n");
		return;
	}

	if (FAILED(hr = g_9to11Queue->OpenConsumer(pDevice, &g_11Consumer)))
	{
		vireio::debugf("g_ABQueue->OpenConsumer failed. \n");
		return;
	}

	if (FAILED(hr = g_9to11Queue->OpenProducer(m_pActualDevice, &g_11Producer)))
	{
		vireio::debugf("g_ABQueue->OpenProducer failed. \n");
		return;
	}

	if (FAILED(hr = g_11to9Queue->OpenConsumer(m_pActualDevice, &g_9Consumer)))
	{
		vireio::debugf("g_BAQueue->OpenConsumer failed. \n");
		return;
	}

	initialized = true;
}

OpenVRDirectMode::~OpenVRDirectMode()
{
	vireio::debugf("OpenVRDirectMode::~OpenVRDirectMode()");
}

void OpenVRDirectMode::PrePresentEx(IDirect3DSurface9* pDirect3DSurface9, int type)
{
	bool SimpleMono = false;
	if (!vr::VRCompositor())
	{
		vireio::debugf("ERROR: No VRCompositor\n");
		return;
	}
	else
	{
		//We dont use this we get poses at other place
		if (type == 1 || type == 3) {
			vr::VRCompositor()->WaitGetPoses(m_rTrackedDevicePose, vr::k_unMaxTrackedDeviceCount, NULL, 0);
		}
	}

	// Flush the BA queue
	UINT surfaces = 0;
	UINT size = sizeof(int);

	D3DSURFACE_DESC desc;
	pDirect3DSurface9->GetDesc(&desc);

	IDirect3DTexture9* pTexture9Left;
	IDirect3DTexture9* pTexture9Right;
	REFIID                  surfaceID9 = __uuidof(IDirect3DTexture9);
	HRESULT hr = g_9Consumer->Dequeue(surfaceID9, (void**)&pTexture9Left, NULL, NULL, 0);
	if (FAILED(hr))
	{
		vireio::debugf("g_9Consumer->Dequeue(surfaceID9, (void**)&pTexture9Left, NULL, NULL, 0); failed %.8x. \n", hr);
		return;
	}

	// Get the top level surface from the texture
	IDirect3DSurface9* pSurface9;
	pTexture9Left->GetSurfaceLevel(0, &pSurface9);

	// Present with D3D9
	RECT rect;
	rect.left = 0;
	rect.right = desc.Width / 2;
	if (SimpleMono) {
		rect.right = desc.Width;
	}
	rect.top = 0;
	rect.bottom = desc.Height;
	hr = m_pActualDevice->StretchRect(pDirect3DSurface9, &rect, pSurface9, NULL, D3DTEXF_NONE);

	pSurface9->Release();

	// Produce Surface
	hr = g_11Producer->Enqueue(pTexture9Left, NULL, NULL, 0);
	pTexture9Left->Release();

	hr = g_9Consumer->Dequeue(surfaceID9, (void**)&pTexture9Right, NULL, NULL, 0);
	if (FAILED(hr))
	{
		vireio::debugf("g_9Consumer->Dequeue(surfaceID9, (void**)&pTexture9Right, NULL, NULL, 500); failed %.8x. \n", hr);
		return;
	}

	// Get the top level surface from the texture
	pTexture9Right->GetSurfaceLevel(0, &pSurface9);

	// Present with D3D9
	rect.left = (desc.Width / 2);
	if (SimpleMono) {
		rect.left = 0;
	}
	rect.right = desc.Width;
	rect.top = 0;
	rect.bottom = desc.Height;
	m_pActualDevice->StretchRect(pDirect3DSurface9, &rect, pSurface9, NULL, D3DTEXF_NONE);

	pSurface9->Release();

	// Produce Surface
	hr = g_11Producer->Enqueue(pTexture9Right, NULL, NULL, 0);
	pTexture9Right->Release();
}

void OpenVRDirectMode::PostPresentEx(IDirect3DSurface9* pDirect3DSurface9, int type)
{
	REFIID    surfaceID11 = __uuidof(ID3D11Texture2D);

	ID3D11Texture2D* pSurface11Left;
	ID3D11Texture2D* pSurface11Right;
	HRESULT hr = g_11Consumer->Dequeue(surfaceID11, (void**)&pSurface11Left, NULL, NULL, 0);
	if (FAILED(hr))
	{
		vireio::debugf("g_11Consumer->Dequeue(surfaceID11, (void**)&pSurface11Left, NULL, NULL, 0); failed: %u. \n", hr);
		return;
	}

	hr = g_11Consumer->Dequeue(surfaceID11, (void**)&pSurface11Right, NULL, NULL, 0);
	if (FAILED(hr))
	{
		vireio::debugf("g_11Consumer->Dequeue(surfaceID11, (void**)&pSurface11Right, NULL, NULL, 0); failed: %u. \n", hr);
		return;
	}

	// there's a surface ready to use
	vr::Texture_t leftEyeTexture = { pSurface11Left, vr::TextureType_DirectX, vr::ColorSpace_Auto };
	vr::EVRCompositorError error;

	if (type == 3 || type == 0) {
		error = vr::VRCompositor()->Submit(vr::Eye_Left, &leftEyeTexture, &m_sTextureBounds[0]);//29 jan added , vr::Submit_FrameDiscontinuty due to stero interlacing but it did not seam to do anything

		if (error != vr::EVRCompositorError::VRCompositorError_None)
		{
			vireio::debugf("EVRCompositorError: %u. \n", error);
		}
	}
	vr::Texture_t rightEyeTexture = { pSurface11Right, vr::TextureType_DirectX, vr::ColorSpace_Auto };
	if (type == 3 || type == 1) {
		error = vr::VRCompositor()->Submit(vr::Eye_Right, &rightEyeTexture, &m_sTextureBounds[1]);

		if (error != vr::EVRCompositorError::VRCompositorError_None)
		{
			vireio::debugf("EVRCompositorError: %u. \n", error);
		}
	}

	g_9Producer->Enqueue(pSurface11Left, NULL, NULL, 0);
	pSurface11Left->Release();

	g_9Producer->Enqueue(pSurface11Right, NULL, NULL, 0);
	pSurface11Right->Release();
	if (type == 0 || type == 3) {
		vr::VRCompositor()->PostPresentHandoff();
	}
}

void OpenVRDirectMode::GetViewParameters(uint32_t* w, uint32_t* h, float* aspect, float* fov) {
	*w = m_nRenderWidth;
	*h = m_nRenderHeight;
	*aspect = m_nAspect;
	*fov = m_nFov;
}

vr::TrackedDeviceIndex_t OpenVRDirectMode::GetControllerIndex(vr::ETrackedControllerRole role) {
	return vr::VRSystem()->GetTrackedDeviceIndexForControllerRole(role);
}

vr::TrackedDevicePose_t* OpenVRDirectMode::GetDevicePose(vr::TrackedDeviceIndex_t unDeviceIndex) {
	return &m_rTrackedDevicePose[unDeviceIndex];
}

bool OpenVRDirectMode::GetControllerState(vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* pControllerState) {
	return vr::VRSystem()->GetControllerState(unControllerDeviceIndex, pControllerState, sizeof(*pControllerState));
}

bool OpenVRDirectMode::PollNextEvent(vr::VREvent_t* pEvent, uint32_t uncbVREvent) {
	return vr::VRSystem()->PollNextEvent(pEvent, uncbVREvent);
}