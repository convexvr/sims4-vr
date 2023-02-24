// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <stdio.h>
#include "MinHook.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "OpenVR-DirectMode.h"

extern "C"{
	__declspec(dllexport) void __cdecl init();
	__declspec(dllexport) float __cdecl get_float_value(int);
	__declspec(dllexport) int __cdecl set_follow(int);
	__declspec(dllexport) int __cdecl set_offset(float, float, float);
	__declspec(dllexport) int __cdecl set_origin(float, float, float);
	__declspec(dllexport) int __cdecl set_vr_active(int);
	__declspec(dllexport) int __cdecl set_position_scale(float);
	__declspec(dllexport) int __cdecl set_added_rotation(float);
	__declspec(dllexport) int __cdecl set_scale(float, float);
	__declspec(dllexport) int __cdecl set_struct_location(UINT64);
	__declspec(dllexport) int __cdecl update();
	__declspec(dllexport) uint64_t __cdecl get_button_value(int);
	

}

bool HookDirectX();
void SetupHMDMatrixes();

IDirect3D9Ex* SharingExDx9 = NULL;
IDirect3DDevice9Ex* SharingExDxDevice = NULL;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		vireio::debugf("Loaded dll");
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


//Surfaces used to move renderd images to the vr headset
HANDLE* pHandle = 0;
IDirect3DSurface9* pBackBuffer = NULL;
IDirect3DSurface9* pBackBufferDst = NULL;

int LastRequestedFrameType = 3;

IDirect3DSurface9* LastRenderTarget = NULL;
bool Fullscreen = false;
bool FullscreenDectionDone = false;

//Class that forwards images to the vr headset
OpenVRDirectMode* forwarder;


vr::VRControllerState_t LastRightHandState;
vr::VRControllerState_t LastLeftHandState;

int ScreenBufferSize = 0;
bool SimpleMono = false;
bool Vr_headset_init_fail = false;

void deal_with_vr_1(IDirect3DDevice9* pDevice) {

	if (!forwarder && !Vr_headset_init_fail) {
		IDirect3DDevice9* dx9ex;

		if (SUCCEEDED(pDevice->QueryInterface(__uuidof(IDirect3DDevice9), (void**)&dx9ex))) {
			forwarder = new OpenVRDirectMode();
			forwarder->Init((IDirect3DDevice9*)SharingExDxDevice);
			if (!forwarder->m_pHMD) {
				vireio::debugf("vr init failed, no headset pressent");
				Vr_headset_init_fail = true;
				forwarder = NULL;
			}

			SetupHMDMatrixes();
		}
		else {
			//vireio::debugf("Failed pDevice->QueryInterface (it needs IDirect3DDevice9Ex not IDirect3DDevice9)");//Nah i fixed that by provifing my own 9Ex
		}
	}

	if (forwarder) {


		//MABYE i should usse GetD3D9AdapterIndex and create the dx9 device with that... Might be more efficent.
		if (Fullscreen) {
			pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer);
		}
		else {
			//We asume that the last Render Target used before EndScene is the surface we are intrested in When not in flullscreen mode.
			if (!LastRenderTarget) {
				return;
			}
			pBackBuffer = LastRenderTarget;
		}

		D3DSURFACE_DESC desc;
		pBackBuffer->GetDesc(&desc);
		int NewScreenSize = desc.Width * desc.Height;
		int wid = desc.Width;
		if (!SimpleMono) {
			wid = desc.Width * 2;
		}
		if (pBackBufferDst == NULL) {
			SharingExDxDevice->CreateOffscreenPlainSurface(wid, desc.Height, desc.Format, desc.Pool, &pBackBufferDst, pHandle);
			ScreenBufferSize = NewScreenSize;
		}
		else if (NewScreenSize != ScreenBufferSize) {
			vireio::debugf("New Screen size: %i, %i", desc.Width, desc.Height);
			pBackBufferDst->Release();
			SharingExDxDevice->CreateOffscreenPlainSurface(wid, desc.Height, desc.Format, desc.Pool, &pBackBufferDst, pHandle);
		}

		if (LastRequestedFrameType == 3) {
			//TODO: zoom out the window so one can see everything when watching menues
		}

		if(LastRequestedFrameType == 0 || LastRequestedFrameType == 3){
			RECT rect;
			rect.left = desc.Width;
			rect.right = desc.Width*2;
			rect.top = 0;
			rect.bottom = desc.Height;
			D3DXLoadSurfaceFromSurface(pBackBufferDst, NULL, &rect, pBackBuffer, NULL, NULL, D3DX_DEFAULT, 0);
		}
		if(LastRequestedFrameType == 1 || LastRequestedFrameType == 3){
			
			RECT rect;
			rect.left = 0;
			rect.right = desc.Width;
			rect.top = 0;
			rect.bottom = desc.Height;
			D3DXLoadSurfaceFromSurface(pBackBufferDst, NULL, &rect, pBackBuffer, NULL, NULL, D3DX_DEFAULT, 0);
		}
		if (LastRequestedFrameType == 0) {
			LastRequestedFrameType = 1;
		}else{
			if (LastRequestedFrameType == 1) {
				LastRequestedFrameType = 0;
			}
		}

		forwarder->PrePresentEx(pBackBufferDst, LastRequestedFrameType);
	}
}

void deal_with_vr_2() {
	if (forwarder) {


		vr::TrackedDeviceIndex_t controlerid = forwarder->GetControllerIndex(vr::TrackedControllerRole_RightHand);
		if (!controlerid) {

			vireio::debugf("right controller");
			if (forwarder->GetControllerState(controlerid, &LastRightHandState)) {

				if(LastRightHandState.ulButtonTouched != 0){
					vireio::debugf("button pressed %llu", LastRightHandState.ulButtonPressed);
				}
				else {

					vireio::debugf("no right buttons ");
				}
				//uint64_t RightHandButtons = RightHandState.ulButtonPressed;
				//vr::VRControllerAxis_t * RightHandAxis = RightHandState.rAxis.;
			}

		}
		else {
			//vireio::debugf("no right controller");
		}
		// Process SteamVR controller state
		for (vr::TrackedDeviceIndex_t unDevice = 1; unDevice < vr::k_unMaxTrackedDeviceCount; unDevice++)
		{
			vr::VRControllerState_t state;
			if (forwarder->m_pHMD->GetControllerState(unDevice, &state, sizeof(state)))
			{
				LastRightHandState.rAxis->x = state.rAxis->x;
				LastRightHandState.rAxis->y = state.rAxis->y;
				LastRightHandState.ulButtonTouched = state.ulButtonTouched;
				LastRightHandState.ulButtonPressed = state.ulButtonPressed;
				uint64_t zero = 0;
				if (LastRightHandState.ulButtonTouched != zero) {
					vireio::debugf("button pressed %i, %llu", unDevice, LastRightHandState.ulButtonPressed);
				}
				else {
					//LastRightHandState.
					//vireio::debugf("no right buttons %i ", unDevice);
				}
				if(LastRightHandState.rAxis->x > 0.1){
					vireio::debugf("x: %f y: %f", LastRightHandState.rAxis->x, LastRightHandState.rAxis->y);
				}
			}
			else {
				break;
			}
		}

		vr::TrackedDeviceIndex_t controleridl = forwarder->GetControllerIndex(vr::TrackedControllerRole_LeftHand);
		if (!controleridl) {

			if (forwarder->GetControllerState(controleridl, &LastLeftHandState)) {
				//uint64_t RightHandButtons = RightHandState.ulButtonPressed;
				//vr::VRControllerAxis_t * RightHandAxis = RightHandState.rAxis.;
			}

		}


		forwarder->PostPresentEx(pBackBufferDst, LastRequestedFrameType);
	}
}

#include "python_exports.h"

typedef HRESULT(APIENTRY* IDirect3DDevice9_BeginScene)(IDirect3DDevice9*);
IDirect3DDevice9_BeginScene IDirect3DDevice9_BeginScene_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_BeginScene_hook(IDirect3DDevice9* pDevice) {
	//vireio::debugf("IDirect3DDevice9_BeginScene_hook");
	return IDirect3DDevice9_BeginScene_orig(pDevice);
}

typedef HRESULT(APIENTRY* IDirect3DDevice9_EndScene)(IDirect3DDevice9*);
IDirect3DDevice9_EndScene IDirect3DDevice9_EndScene_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_EndScene_hook(IDirect3DDevice9* pDevice) {
	//vireio::debugf("IDirect3DDevice9_EndScene_hook");

	if(!Fullscreen){
		deal_with_vr_1(pDevice);
	}
	HRESULT ret = IDirect3DDevice9_EndScene_orig(pDevice);
	if (!Fullscreen) {
		deal_with_vr_2();
	}
	return ret;
}


typedef HRESULT(APIENTRY* IDirect3DDevice9_SetRenderTarget)(IDirect3DDevice9*, DWORD, IDirect3DSurface9*);
IDirect3DDevice9_SetRenderTarget  IDirect3DDevice9_SetRenderTarget_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetRenderTarget_hook(IDirect3DDevice9* pDevice, DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget) {
	//We track the last set render target, as that is what we take the image from when the sceneEnds
	LastRenderTarget = pRenderTarget;
	return IDirect3DDevice9_SetRenderTarget_orig(pDevice, RenderTargetIndex, pRenderTarget);
}


typedef HRESULT(APIENTRY* IDirect3DDevice9_SetTransform)(IDirect3DDevice9*, D3DTRANSFORMSTATETYPE, CONST D3DMATRIX*);
IDirect3DDevice9_SetTransform IDirect3DDevice9_SetTransform_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetTransform_hook(IDirect3DDevice9* pDevice, D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix) {
	//vireio::debugf("IDirect3DDevice9_SetTransform_hook: %i, %i", State, pMatrix);
	return IDirect3DDevice9_SetTransform_orig(pDevice, State, pMatrix);
}


//#include "../d3d9_defs.h"
UINT64 LastVertex_Shader = 0;

/*
typedef HRESULT(APIENTRY* IDirect3DDevice9_EndScene)(IDirect3DDevice9*);
IDirect3DDevice9_EndScene IDirect3DDevice9_EndScene_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_EndScene_hook(IDirect3DDevice9* pDevice) {
	vireio::debugf("IDirect3DDevice9_EndScene: pDevice: %u", pDevice);

	D3DMATRIX mat;

	//IDirect3DDevice9_SetTransform_orig(pDevice, D3DTRANSFORMSTATETYPE::D3DTS_VIEW, &mat);

	D3DMATRIX mat2;

	D3DMATRIX* pMatrix = &mat;
	IDirect3DDevice9_GetTransform_orig(pDevice, D3DTRANSFORMSTATETYPE::D3DTS_PROJECTION, pMatrix);
	vireio::debugf("Executed function");
	//D3DMATRIX* pMatrix = &mat;
	vireio::debugf("IDirect3DDevice9_GetTransform: pDevice: %u, pMatrix: %u, pMatrix->_11: %f, pMatrix->_12: %f, pMatrix->_13: %f, pMatrix->_14: %f, pMatrix->_21: %f, pMatrix->_22: %f, pMatrix->_23: %f, pMatrix->_24: %f, pMatrix->_31: %f, pMatrix->_32: %f, pMatrix->_33: %f, pMatrix->_34: %f, pMatrix->_41: %f, pMatrix->_42: %f, pMatrix->_43: %f, pMatrix->_44: %f", pDevice, pMatrix, (pMatrix == NULL) ? 0 : (pMatrix->_11), (pMatrix == NULL) ? 0 : (pMatrix->_12), (pMatrix == NULL) ? 0 : (pMatrix->_13), (pMatrix == NULL) ? 0 : (pMatrix->_14), (pMatrix == NULL) ? 0 : (pMatrix->_21), (pMatrix == NULL) ? 0 : (pMatrix->_22), (pMatrix == NULL) ? 0 : (pMatrix->_23), (pMatrix == NULL) ? 0 : (pMatrix->_24), (pMatrix == NULL) ? 0 : (pMatrix->_31), (pMatrix == NULL) ? 0 : (pMatrix->_32), (pMatrix == NULL) ? 0 : (pMatrix->_33), (pMatrix == NULL) ? 0 : (pMatrix->_34), (pMatrix == NULL) ? 0 : (pMatrix->_41), (pMatrix == NULL) ? 0 : (pMatrix->_42), (pMatrix == NULL) ? 0 : (pMatrix->_43), (pMatrix == NULL) ? 0 : (pMatrix->_44));


	return IDirect3DDevice9_EndScene_orig(pDevice);
}

typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexShaderConstantF)(IDirect3DDevice9*, UINT, CONST float*, UINT);
IDirect3DDevice9_SetVertexShaderConstantF IDirect3DDevice9_SetVertexShaderConstantF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexShaderConstantF_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) {
	vireio::debugf("	CurrentShader: %u", pDevice, LastVertex_Shader);
	vireio::debugf("IDirect3DDevice9_SetVertexShaderConstantF_hook: pDevice: %u, StartRegister: %u, pConstantData: %u, Vector4fCount: %u", pDevice, StartRegister, pConstantData, Vector4fCount);
	int i = 0;
	while (i < Vector4fCount) {
		vireio::debugf("	%i: %f,", StartRegister+i, pConstantData[i]);
		i++;
	}
	return IDirect3DDevice9_SetVertexShaderConstantF_orig(pDevice, StartRegister, pConstantData, Vector4fCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPixelShaderConstantF)(IDirect3DDevice9*, UINT, CONST float*, UINT);
IDirect3DDevice9_SetPixelShaderConstantF IDirect3DDevice9_SetPixelShaderConstantF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPixelShaderConstantF_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) {
	vireio::debugf("IDirect3DDevice9_SetPixelShaderConstantF_hook: pDevice: %u, StartRegister: %u, pConstantData: %u, Vector4fCount: %u", pDevice, StartRegister, pConstantData, Vector4fCount);
	int i = 0;
	while (i < Vector4fCount) {
		vireio::debugf("	%i: %f,", StartRegister + i, pConstantData[i]);
		i++;
	}
	return IDirect3DDevice9_SetPixelShaderConstantF_orig(pDevice, StartRegister, pConstantData, Vector4fCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexShader)(IDirect3DDevice9*, IDirect3DVertexShader9*);
IDirect3DDevice9_SetVertexShader IDirect3DDevice9_SetVertexShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexShader_hook(IDirect3DDevice9* pDevice, IDirect3DVertexShader9* pShader) {
	LastVertex_Shader = (UINT64)pShader;
	vireio::debugf("IDirect3DDevice9_SetVertexShader_hook: pDevice: %u, pShader: %u", pDevice, pShader);
	return IDirect3DDevice9_SetVertexShader_orig(pDevice, pShader);
}
*/






typedef HRESULT(APIENTRY* IDirect3DDevice9_Present) (IDirect3DDevice9*, RECT*, RECT*, HWND, RGNDATA*);
IDirect3DDevice9_Present IDirect3DDevice9_Present_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_Present_hook(IDirect3DDevice9* pDevice, RECT* pSourceRect, RECT* pDestRect, HWND hDestWindowOverride, RGNDATA* pDirtyRegion) {

	//Catching Present does not seam nececary the EndScene thing works well enogh
	if(Fullscreen){
		deal_with_vr_1(pDevice);
	}
	HRESULT ret = IDirect3DDevice9_Present_orig(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
	if (Fullscreen) {
		deal_with_vr_2();
	}

	//Do this after so that we dont get pressent and EndScen on the same first frame... Does not really matter
	if (!FullscreenDectionDone) {
		Fullscreen = true;
		FullscreenDectionDone = true;
	}

	return ret;
}

//LEgacy from garys mod to search for new textures
bool searching = false;
IDirect3DSurface9* surface;
/*
typedef HRESULT(APIENTRY* IDirect3DDevice_CreateTexture) (IDirect3DDevice9*, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DTexture9**, HANDLE*);
IDirect3DDevice_CreateTexture IDirect3DDevice_CreateTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice_CreateTexture_hook(IDirect3DDevice9* pDevice, UINT w, UINT h, UINT levels, DWORD usage, D3DFORMAT format, D3DPOOL pool, IDirect3DTexture9** tex, HANDLE* shared_handle) {
	HRESULT res = IDirect3DDevice_CreateTexture_orig(pDevice, w, h, levels, usage, format, pool, tex, shared_handle);

	if (!surface && searching) {
		if (FAILED(res))
			return res;

		IDirect3DTexture9* reference = *tex;

		if (FAILED(reference->GetSurfaceLevel(0, &surface)))
			return res;

		searching = false;
	}

	return res;
};
*/



typedef HMODULE(WINAPI* LoadLibraryW_)(LPCSTR name);
LoadLibraryW_ LoadLibraryW_orig = 0;

HMODULE WINAPI LoadLibraryW_hook(LPCSTR name) {
	vireio::debugf("LoadLibraryW_hook(%ls)", name);
	return LoadLibraryW_orig(name);
}

typedef FARPROC(WINAPI* GetProcAddress_)(HMODULE hModule, LPCSTR lpProcName);
GetProcAddress_ GetProcAddress_orig = 0;

FARPROC WINAPI GetProcAddress_hook(HMODULE hModule, LPCSTR lpProcName) {
	vireio::debugf("GetProcAddress_hook(%i, %s)", hModule, lpProcName);
	return GetProcAddress_orig(hModule, lpProcName);
}

//To deal with the fake "window" that the SharingExDx9 needs
LRESULT WINAPI MsgProcs(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
bool HookDirectX() {



	
	if (MH_Initialize() != MH_OK) {
		MessageBoxA(NULL, "Failed to initialize MinHook", "Error", MB_OK);
		return false;
	}
	

	//Create fake window that SharingExDx9 needs.
	HMODULE mod = GetModuleHandle(L"does_not_matter");//seams to work
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProcs, 0L, 0L,
		mod, NULL, NULL, NULL, NULL,
		L"D3DHook", NULL
	};
	// Register the window class
	RegisterClassEx(&wc);
	HWND window = CreateWindow(L"D3DHook", L"Hooking...",
		WS_OVERLAPPEDWINDOW , 100, 100, 300, 300,
		NULL, NULL, wc.hInstance, NULL);
	
	if (!window) {
		MessageBoxA(NULL, "Failed to create window", "Error", MB_OK);
		return false;
	}
	

	HRESULT res = Direct3DCreate9Ex(D3D_SDK_VERSION, &SharingExDx9);

	if (FAILED(res)) {
		vireio::debugf("Failed to create SharingExDx9");
		return false;
	}
	
	vireio::debugf("Created SharingExDx9");

	D3DPRESENT_PARAMETERS params;
	ZeroMemory(&params, sizeof(params));
	params.Windowed = TRUE;
	params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	params.BackBufferFormat = D3DFMT_UNKNOWN;
	params.EnableAutoDepthStencil = TRUE;
	params.AutoDepthStencilFormat = D3DFMT_D16;

	
	res = SharingExDx9->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&params,NULL, &SharingExDxDevice);

	if (FAILED(res)) {
		vireio::debugf("failed to create SharingExDxDevice");
		DestroyWindow(window);
		return false;
	}
	vireio::debugf("Created SharingExDxDevice");

#if defined _M_X64
	DWORD64* dVtable_alt = (DWORD64*)*(DWORD64*)SharingExDx9;
	DWORD64* dVtable = (DWORD64*)SharingExDxDevice;
	dVtable = (DWORD64*)dVtable[0];
#elif defined _M_IX86
	//DWORD* dVtable = (DWORD*)device;
	//dVtable = (DWORD*)dVtable[0]; // == *d3ddev
#endif
	/*
	if (MH_CreateHook(&LoadLibraryW, &LoadLibraryW_hook, reinterpret_cast<void**>(&LoadLibraryW_orig)) != MH_OK) {
		MessageBoxA(NULL, "Failed to create LoadLibraryW hook", "Error", MB_OK);
		return false;
	}

	if (MH_CreateHook(&GetProcAddress, &GetProcAddress_hook, reinterpret_cast<void**>(&GetProcAddress_orig)) != MH_OK) {
		MessageBoxA(NULL, "Failed to create GetProcAddress hook", "Error", MB_OK);
		return false;
	}

	if (MH_CreateHook((DWORD_PTR*)dVtable[23], &IDirect3DDevice_CreateTexture_hook, reinterpret_cast<void**>(&IDirect3DDevice_CreateTexture_orig)) != MH_OK) {
		MessageBoxA(NULL, "Failed to create CreateTexture hook", "Error", MB_OK);
		return false;
	}
	

	*/

	vireio::debugf("Hooking directX functions");
	
	
	if (MH_CreateHook((DWORD_PTR*)dVtable[17], &IDirect3DDevice9_Present_hook, reinterpret_cast<void**>(&IDirect3DDevice9_Present_orig)) != MH_OK) {
		MessageBoxA(NULL, "Failed to create Present hook", "Error", MB_OK);
		return false;
	}

	if (MH_CreateHook((DWORD_PTR*)dVtable[37], &IDirect3DDevice9_SetRenderTarget_hook, reinterpret_cast<void**>(&IDirect3DDevice9_SetRenderTarget_orig)) != MH_OK) {
		MessageBoxA(NULL, "Failed to create IDirect3DDevice9_SetRenderTarget hook", "Error", MB_OK);
		return false;
	}

	if (MH_CreateHook((DWORD_PTR*)dVtable[41], &IDirect3DDevice9_BeginScene_hook, reinterpret_cast<void**>(&IDirect3DDevice9_BeginScene_orig)) != MH_OK) {
		MessageBoxA(NULL, "Failed to create IDirect3DDevice9_BeginScene hook", "Error", MB_OK);
		return false;
	}

	if (MH_CreateHook((DWORD_PTR*)dVtable[42], &IDirect3DDevice9_EndScene_hook, reinterpret_cast<void**>(&IDirect3DDevice9_EndScene_orig)) != MH_OK) {
		MessageBoxA(NULL, "Failed to create IDirect3DDevice9_EndScene hook", "Error", MB_OK);
		return false;
	}
	
	if (MH_CreateHook((DWORD_PTR*)dVtable[44], &IDirect3DDevice9_SetTransform_hook, reinterpret_cast<void**>(&IDirect3DDevice9_SetTransform_orig)) != MH_OK) {
		MessageBoxA(NULL, "Failed to create IDirect3DDevice9_SetTransform hook", "Error", MB_OK);
		return false;
	}
	
//#include "../d3d9_injects.h"


	vireio::debugf("Enabeling directX hooking functions");
	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
		MessageBoxA(NULL, "Failed to enable hooks", "Error", MB_OK);
		return NULL;
	}

	return true;
}


_declspec(dllexport) void __cdecl  init() {
    FILE* fp;

    fopen_s(&fp, "C:\\s4\\output.txt", "a");
    if (fp) {
        fputs("init\n", fp);
		fclose(fp);
    }

	bool OK = HookDirectX();


	/*
	// View Matrix
	D3DXMATRIX m_matView;

	// Projection Matrix
	D3DXMATRIX m_matProj;

	// Projection Matrix
	D3DXMATRIX m_matWorld;

	D3DXVECTOR3 vEyePt(0.0f, 0.0f, 1.0f);
	D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vUpVec(0.0f, -1.0f, 0.0f);
	D3DXMatrixLookAtLH(&m_matView, &vEyePt, &vLookatPt, &vUpVec);

	/// Set a Projection Matrix for the Heading Gauge
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4, 1.0f, 0.0f, 1.0f);
	*/

	
	if(OK){
		vireio::debugf("Hooked");
	}
	else {
		vireio::debugf("Hooking failed");
	}
}