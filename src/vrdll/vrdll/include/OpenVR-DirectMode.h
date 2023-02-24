/********************************************************************
Vireio Perception: Open-Source Stereoscopic 3D Driver
Copyright (C) 2012 Andres Hernandez

File <OculusRiftView.h> and
Class <OculusRiftView> :
Copyright (C) 2012 Andres Hernandez

Vireio Perception Version History:
v1.0.0 2012 by Andres Hernandez
v1.0.X 2013 by John Hicks, Neil Schneider
v1.1.x 2013 by Primary Coding Author: Chris Drain
Team Support: John Hicks, Phil Larkson, Neil Schneider
v2.0.x 2013 by Denis Reischl, Neil Schneider, Joshua Brown

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/

#ifndef OPENVRDIRECTMODE_H_INCLUDED
#define OPENVRDIRECTMODE_H_INCLUDED

#include <d3d9.h>
#include <d3dx9.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <d3dx9.h>

#include "openvr.h"

#include "SurfaceQueue.h"
#include "Util.h"

struct ID3D11Device;
struct ID3D11DeviceContext;
struct ID3D11DepthStencilView;
struct ID3D11DepthStencilState;
struct ISurfaceQueue;
struct ISurfaceConsumer;

class DX9ExDebugWindow;

/**
* OpenVR Direct Mode render class.
*/


class OpenVRDirectMode
{
public:
	OpenVRDirectMode();
	virtual ~OpenVRDirectMode();

	virtual void Init(IDirect3DDevice9* pActualDevice);

	virtual void PrePresentEx(IDirect3DSurface9* pDirect3DSurface9, int type);
	virtual void PostPresentEx(IDirect3DSurface9* pDirect3DSurface9, int type);
	virtual void GetViewParameters(uint32_t* w, uint32_t* h, float* aspect, float* fov );
	virtual vr::TrackedDeviceIndex_t GetControllerIndex(vr::ETrackedControllerRole role);
	virtual vr::TrackedDevicePose_t* GetDevicePose(vr::TrackedDeviceIndex_t unDeviceIndex);
	virtual bool GetControllerState(vr::TrackedDeviceIndex_t unControllerDeviceIndex, vr::VRControllerState_t* state);
	virtual bool PollNextEvent(vr::VREvent_t* pEvent, uint32_t uncbVREvent);

	vr::IVRSystem* m_pHMD;

	vr::IVRRenderModels* m_pRenderModels;
	vr::TrackedDevicePose_t m_rTrackedDevicePose[vr::k_unMaxTrackedDeviceCount];
private:
	IDirect3DDevice9* m_pActualDevice;


	ID3D11Device*			pDevice;
	ID3D11DeviceContext*	pImmediateContext;
	ID3D11DepthStencilView* pDepthStencilView;
	ID3D11DepthStencilState * pDSState;

	ISurfaceQueue*			g_9to11Queue;
	ISurfaceQueue*			g_11to9Queue;

    ISurfaceConsumer*		g_9Consumer;
    ISurfaceProducer*		g_9Producer;
    ISurfaceConsumer*		g_11Consumer;
    ISurfaceProducer*		g_11Producer;

	D3D_DRIVER_TYPE			driverType;
	D3D_FEATURE_LEVEL		featureLevel;
	D3D11_VIEWPORT			dx11viewport;

	uint32_t m_nRenderWidth;
	uint32_t m_nRenderHeight;
	float m_nAspect;
	float m_nFov;
	vr::VRTextureBounds_t m_sTextureBounds[2];

	int count;

	
	
	int m_iTrackedControllerCount;
	int m_iTrackedControllerCount_Last;
	int m_iValidPoseCount;
	int m_iValidPoseCount_Last;

	bool initialized;

	std::string m_strPoseClasses;                            // what classes we saw poses for this frame
	char m_rDevClassChar[vr::k_unMaxTrackedDeviceCount];   // for each device, a character representing its class
};

#endif //OPENVRDIRECTMODE_H_INCLUDED

