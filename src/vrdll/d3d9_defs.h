typedef HRESULT(APIENTRY* IDirect3DDevice9_QueryInterface)(IDirect3DDevice9*, REFIID, void**);
IDirect3DDevice9_QueryInterface IDirect3DDevice9_QueryInterface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_QueryInterface_hook(IDirect3DDevice9* pDevice, REFIID riid, void** ppvObj){
   vireio::debugf("IDirect3DDevice9_QueryInterface: pDevice: %u, riid: %u, ppvObj: %u", pDevice, riid, ppvObj);
   return IDirect3DDevice9_QueryInterface_orig(pDevice, riid, ppvObj);
}
typedef ULONG(APIENTRY* IDirect3DDevice9_AddRef)(IDirect3DDevice9*);
IDirect3DDevice9_AddRef IDirect3DDevice9_AddRef_orig = 0;
ULONG APIENTRY IDirect3DDevice9_AddRef_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_AddRef: pDevice: %u", pDevice);
   return IDirect3DDevice9_AddRef_orig(pDevice);
}
typedef ULONG(APIENTRY* IDirect3DDevice9_Release)(IDirect3DDevice9*);
IDirect3DDevice9_Release IDirect3DDevice9_Release_orig = 0;
ULONG APIENTRY IDirect3DDevice9_Release_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_Release: pDevice: %u", pDevice);
   return IDirect3DDevice9_Release_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_TestCooperativeLevel)(IDirect3DDevice9*);
IDirect3DDevice9_TestCooperativeLevel IDirect3DDevice9_TestCooperativeLevel_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_TestCooperativeLevel_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_TestCooperativeLevel: pDevice: %u", pDevice);
   return IDirect3DDevice9_TestCooperativeLevel_orig(pDevice);
}
typedef UINT(APIENTRY* IDirect3DDevice9_GetAvailableTextureMem)(IDirect3DDevice9*);
IDirect3DDevice9_GetAvailableTextureMem IDirect3DDevice9_GetAvailableTextureMem_orig = 0;
UINT APIENTRY IDirect3DDevice9_GetAvailableTextureMem_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_GetAvailableTextureMem: pDevice: %u", pDevice);
   return IDirect3DDevice9_GetAvailableTextureMem_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_EvictManagedResources)(IDirect3DDevice9*);
IDirect3DDevice9_EvictManagedResources IDirect3DDevice9_EvictManagedResources_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_EvictManagedResources_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_EvictManagedResources: pDevice: %u", pDevice);
   return IDirect3DDevice9_EvictManagedResources_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetDirect3D)(IDirect3DDevice9*, IDirect3D9**);
IDirect3DDevice9_GetDirect3D IDirect3DDevice9_GetDirect3D_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetDirect3D_hook(IDirect3DDevice9* pDevice, IDirect3D9** ppD3D9){
   vireio::debugf("IDirect3DDevice9_GetDirect3D: pDevice: %u, ppD3D9: %u", pDevice, ppD3D9);
   return IDirect3DDevice9_GetDirect3D_orig(pDevice, ppD3D9);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetDeviceCaps)(IDirect3DDevice9*, D3DCAPS9*);
IDirect3DDevice9_GetDeviceCaps IDirect3DDevice9_GetDeviceCaps_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetDeviceCaps_hook(IDirect3DDevice9* pDevice, D3DCAPS9* pCaps){
   vireio::debugf("IDirect3DDevice9_GetDeviceCaps: pDevice: %u, pCaps: %u, pCaps->DeviceType: %u, pCaps->AdapterOrdinal: %u, pCaps->Caps: %u, pCaps->Caps2: %u, pCaps->Caps3: %u, pCaps->PresentationIntervals: %u, pCaps->CursorCaps: %u, pCaps->DevCaps: %u, pCaps->PrimitiveMiscCaps: %u, pCaps->RasterCaps: %u, pCaps->ZCmpCaps: %u, pCaps->SrcBlendCaps: %u, pCaps->DestBlendCaps: %u, pCaps->AlphaCmpCaps: %u, pCaps->ShadeCaps: %u, pCaps->TextureCaps: %u, pCaps->TextureFilterCaps: %u, pCaps->CubeTextureFilterCaps: %u, pCaps->VolumeTextureFilterCaps: %u, pCaps->TextureAddressCaps: %u, pCaps->VolumeTextureAddressCaps: %u, pCaps->LineCaps: %u, pCaps->MaxTextureWidth: %u, pCaps->MaxTextureHeight: %u, pCaps->MaxVolumeExtent: %u, pCaps->MaxTextureRepeat: %u, pCaps->MaxTextureAspectRatio: %u, pCaps->MaxAnisotropy: %u, pCaps->MaxVertexW: %f, pCaps->GuardBandLeft: %f, pCaps->GuardBandTop: %f, pCaps->GuardBandRight: %f, pCaps->GuardBandBottom: %f, pCaps->ExtentsAdjust: %f, pCaps->StencilCaps: %u, pCaps->FVFCaps: %u, pCaps->TextureOpCaps: %u, pCaps->MaxTextureBlendStages: %u, pCaps->MaxSimultaneousTextures: %u, pCaps->VertexProcessingCaps: %u, pCaps->MaxActiveLights: %u, pCaps->MaxUserClipPlanes: %u, pCaps->MaxVertexBlendMatrices: %u, pCaps->MaxVertexBlendMatrixIndex: %u, pCaps->MaxPointSize: %f, pCaps->MaxPrimitiveCount: %u, pCaps->MaxVertexIndex: %u, pCaps->MaxStreams: %u, pCaps->MaxStreamStride: %u, pCaps->VertexShaderVersion: %u, pCaps->MaxVertexShaderConst: %u, pCaps->PixelShaderVersion: %u, pCaps->PixelShader1xMaxValue: %f, pCaps->DevCaps2: %u, pCaps->MaxNpatchTessellationLevel: %f, pCaps->Reserved5: %u, pCaps->MasterAdapterOrdinal: %u, pCaps->AdapterOrdinalInGroup: %u, pCaps->NumberOfAdaptersInGroup: %u, pCaps->DeclTypes: %u, pCaps->NumSimultaneousRTs: %u, pCaps->StretchRectFilterCaps: %u, pCaps->VertexTextureFilterCaps: %u, pCaps->MaxVShaderInstructionsExecuted: %u, pCaps->MaxPShaderInstructionsExecuted: %u, pCaps->MaxVertexShader30InstructionSlots: %u, pCaps->MaxPixelShader30InstructionSlots: %u", pDevice, pCaps, (pCaps == NULL)?0:(pCaps->DeviceType), (pCaps == NULL)?0:(pCaps->AdapterOrdinal), (pCaps == NULL)?0:(pCaps->Caps), (pCaps == NULL)?0:(pCaps->Caps2), (pCaps == NULL)?0:(pCaps->Caps3), (pCaps == NULL)?0:(pCaps->PresentationIntervals), (pCaps == NULL)?0:(pCaps->CursorCaps), (pCaps == NULL)?0:(pCaps->DevCaps), (pCaps == NULL)?0:(pCaps->PrimitiveMiscCaps), (pCaps == NULL)?0:(pCaps->RasterCaps), (pCaps == NULL)?0:(pCaps->ZCmpCaps), (pCaps == NULL)?0:(pCaps->SrcBlendCaps), (pCaps == NULL)?0:(pCaps->DestBlendCaps), (pCaps == NULL)?0:(pCaps->AlphaCmpCaps), (pCaps == NULL)?0:(pCaps->ShadeCaps), (pCaps == NULL)?0:(pCaps->TextureCaps), (pCaps == NULL)?0:(pCaps->TextureFilterCaps), (pCaps == NULL)?0:(pCaps->CubeTextureFilterCaps), (pCaps == NULL)?0:(pCaps->VolumeTextureFilterCaps), (pCaps == NULL)?0:(pCaps->TextureAddressCaps), (pCaps == NULL)?0:(pCaps->VolumeTextureAddressCaps), (pCaps == NULL)?0:(pCaps->LineCaps), (pCaps == NULL)?0:(pCaps->MaxTextureWidth), (pCaps == NULL)?0:(pCaps->MaxTextureHeight), (pCaps == NULL)?0:(pCaps->MaxVolumeExtent), (pCaps == NULL)?0:(pCaps->MaxTextureRepeat), (pCaps == NULL)?0:(pCaps->MaxTextureAspectRatio), (pCaps == NULL)?0:(pCaps->MaxAnisotropy), (pCaps == NULL)?0:(pCaps->MaxVertexW), (pCaps == NULL)?0:(pCaps->GuardBandLeft), (pCaps == NULL)?0:(pCaps->GuardBandTop), (pCaps == NULL)?0:(pCaps->GuardBandRight), (pCaps == NULL)?0:(pCaps->GuardBandBottom), (pCaps == NULL)?0:(pCaps->ExtentsAdjust), (pCaps == NULL)?0:(pCaps->StencilCaps), (pCaps == NULL)?0:(pCaps->FVFCaps), (pCaps == NULL)?0:(pCaps->TextureOpCaps), (pCaps == NULL)?0:(pCaps->MaxTextureBlendStages), (pCaps == NULL)?0:(pCaps->MaxSimultaneousTextures), (pCaps == NULL)?0:(pCaps->VertexProcessingCaps), (pCaps == NULL)?0:(pCaps->MaxActiveLights), (pCaps == NULL)?0:(pCaps->MaxUserClipPlanes), (pCaps == NULL)?0:(pCaps->MaxVertexBlendMatrices), (pCaps == NULL)?0:(pCaps->MaxVertexBlendMatrixIndex), (pCaps == NULL)?0:(pCaps->MaxPointSize), (pCaps == NULL)?0:(pCaps->MaxPrimitiveCount), (pCaps == NULL)?0:(pCaps->MaxVertexIndex), (pCaps == NULL)?0:(pCaps->MaxStreams), (pCaps == NULL)?0:(pCaps->MaxStreamStride), (pCaps == NULL)?0:(pCaps->VertexShaderVersion), (pCaps == NULL)?0:(pCaps->MaxVertexShaderConst), (pCaps == NULL)?0:(pCaps->PixelShaderVersion), (pCaps == NULL)?0:(pCaps->PixelShader1xMaxValue), (pCaps == NULL)?0:(pCaps->DevCaps2), (pCaps == NULL)?0:(pCaps->MaxNpatchTessellationLevel), (pCaps == NULL)?0:(pCaps->Reserved5), (pCaps == NULL)?0:(pCaps->MasterAdapterOrdinal), (pCaps == NULL)?0:(pCaps->AdapterOrdinalInGroup), (pCaps == NULL)?0:(pCaps->NumberOfAdaptersInGroup), (pCaps == NULL)?0:(pCaps->DeclTypes), (pCaps == NULL)?0:(pCaps->NumSimultaneousRTs), (pCaps == NULL)?0:(pCaps->StretchRectFilterCaps), (pCaps == NULL)?0:(pCaps->VertexTextureFilterCaps), (pCaps == NULL)?0:(pCaps->MaxVShaderInstructionsExecuted), (pCaps == NULL)?0:(pCaps->MaxPShaderInstructionsExecuted), (pCaps == NULL)?0:(pCaps->MaxVertexShader30InstructionSlots), (pCaps == NULL)?0:(pCaps->MaxPixelShader30InstructionSlots));
   return IDirect3DDevice9_GetDeviceCaps_orig(pDevice, pCaps);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetDisplayMode)(IDirect3DDevice9*, UINT, D3DDISPLAYMODE*);
IDirect3DDevice9_GetDisplayMode IDirect3DDevice9_GetDisplayMode_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetDisplayMode_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, D3DDISPLAYMODE* pMode){
   vireio::debugf("IDirect3DDevice9_GetDisplayMode: pDevice: %u, iSwapChain: %u, pMode: %u, pMode->Width: %u, pMode->Height: %u, pMode->RefreshRate: %u, pMode->Format: %u", pDevice, iSwapChain, pMode, (pMode == NULL)?0:(pMode->Width), (pMode == NULL)?0:(pMode->Height), (pMode == NULL)?0:(pMode->RefreshRate), (pMode == NULL)?0:(pMode->Format));
   return IDirect3DDevice9_GetDisplayMode_orig(pDevice, iSwapChain, pMode);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetCreationParameters)(IDirect3DDevice9*, D3DDEVICE_CREATION_PARAMETERS*);
IDirect3DDevice9_GetCreationParameters IDirect3DDevice9_GetCreationParameters_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetCreationParameters_hook(IDirect3DDevice9* pDevice, D3DDEVICE_CREATION_PARAMETERS* pParameters){
   vireio::debugf("IDirect3DDevice9_GetCreationParameters: pDevice: %u, pParameters: %u, pParameters->AdapterOrdinal: %u, pParameters->DeviceType: %u, pParameters->hFocusWindow: %u, pParameters->BehaviorFlags: %u", pDevice, pParameters, (pParameters == NULL)?0:(pParameters->AdapterOrdinal), (pParameters == NULL)?0:(pParameters->DeviceType), (pParameters == NULL)?0:(pParameters->hFocusWindow), (pParameters == NULL)?0:(pParameters->BehaviorFlags));
   return IDirect3DDevice9_GetCreationParameters_orig(pDevice, pParameters);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetCursorProperties)(IDirect3DDevice9*, UINT, UINT, IDirect3DSurface9*);
IDirect3DDevice9_SetCursorProperties IDirect3DDevice9_SetCursorProperties_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetCursorProperties_hook(IDirect3DDevice9* pDevice, UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap){
   vireio::debugf("IDirect3DDevice9_SetCursorProperties: pDevice: %u, XHotSpot: %u, YHotSpot: %u, pCursorBitmap: %u", pDevice, XHotSpot, YHotSpot, pCursorBitmap);
   return IDirect3DDevice9_SetCursorProperties_orig(pDevice, XHotSpot, YHotSpot, pCursorBitmap);
}
typedef void(APIENTRY* IDirect3DDevice9_SetCursorPosition)(IDirect3DDevice9*, int, int, DWORD);
IDirect3DDevice9_SetCursorPosition IDirect3DDevice9_SetCursorPosition_orig = 0;
void APIENTRY IDirect3DDevice9_SetCursorPosition_hook(IDirect3DDevice9* pDevice, int X, int Y, DWORD Flags){
   vireio::debugf("IDirect3DDevice9_SetCursorPosition: pDevice: %u, X: %u, Y: %u, Flags: %u", pDevice, X, Y, Flags);
   return IDirect3DDevice9_SetCursorPosition_orig(pDevice, X, Y, Flags);
}
typedef BOOL(APIENTRY* IDirect3DDevice9_ShowCursor)(IDirect3DDevice9*, BOOL);
IDirect3DDevice9_ShowCursor IDirect3DDevice9_ShowCursor_orig = 0;
BOOL APIENTRY IDirect3DDevice9_ShowCursor_hook(IDirect3DDevice9* pDevice, BOOL bShow){
   vireio::debugf("IDirect3DDevice9_ShowCursor: pDevice: %u, bShow: %u", pDevice, bShow);
   return IDirect3DDevice9_ShowCursor_orig(pDevice, bShow);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateAdditionalSwapChain)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*, IDirect3DSwapChain9**);
IDirect3DDevice9_CreateAdditionalSwapChain IDirect3DDevice9_CreateAdditionalSwapChain_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateAdditionalSwapChain_hook(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain){
   vireio::debugf("IDirect3DDevice9_CreateAdditionalSwapChain: pDevice: %u, pPresentationParameters: %u, pPresentationParameters->BackBufferWidth: %u, pPresentationParameters->BackBufferHeight: %u, pPresentationParameters->BackBufferFormat: %u, pPresentationParameters->BackBufferCount: %u, pPresentationParameters->MultiSampleType: %u, pPresentationParameters->MultiSampleQuality: %u, pPresentationParameters->SwapEffect: %u, pPresentationParameters->hDeviceWindow: %u, pPresentationParameters->Windowed: %u, pPresentationParameters->EnableAutoDepthStencil: %u, pPresentationParameters->AutoDepthStencilFormat: %u, pPresentationParameters->Flags: %u, pPresentationParameters->FullScreen_RefreshRateInHz: %u, pPresentationParameters->PresentationInterval: %u, pSwapChain: %u", pDevice, pPresentationParameters, (pPresentationParameters == NULL)?0:(pPresentationParameters->BackBufferWidth), (pPresentationParameters == NULL)?0:(pPresentationParameters->BackBufferHeight), (pPresentationParameters == NULL)?0:(pPresentationParameters->BackBufferFormat), (pPresentationParameters == NULL)?0:(pPresentationParameters->BackBufferCount), (pPresentationParameters == NULL)?0:(pPresentationParameters->MultiSampleType), (pPresentationParameters == NULL)?0:(pPresentationParameters->MultiSampleQuality), (pPresentationParameters == NULL)?0:(pPresentationParameters->SwapEffect), (pPresentationParameters == NULL)?0:(pPresentationParameters->hDeviceWindow), (pPresentationParameters == NULL)?0:(pPresentationParameters->Windowed), (pPresentationParameters == NULL)?0:(pPresentationParameters->EnableAutoDepthStencil), (pPresentationParameters == NULL)?0:(pPresentationParameters->AutoDepthStencilFormat), (pPresentationParameters == NULL)?0:(pPresentationParameters->Flags), (pPresentationParameters == NULL)?0:(pPresentationParameters->FullScreen_RefreshRateInHz), (pPresentationParameters == NULL)?0:(pPresentationParameters->PresentationInterval), pSwapChain);
   return IDirect3DDevice9_CreateAdditionalSwapChain_orig(pDevice, pPresentationParameters, pSwapChain);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetSwapChain)(IDirect3DDevice9*, UINT, IDirect3DSwapChain9**);
IDirect3DDevice9_GetSwapChain IDirect3DDevice9_GetSwapChain_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetSwapChain_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, IDirect3DSwapChain9** pSwapChain){
   vireio::debugf("IDirect3DDevice9_GetSwapChain: pDevice: %u, iSwapChain: %u, pSwapChain: %u", pDevice, iSwapChain, pSwapChain);
   return IDirect3DDevice9_GetSwapChain_orig(pDevice, iSwapChain, pSwapChain);
}
typedef UINT(APIENTRY* IDirect3DDevice9_GetNumberOfSwapChains)(IDirect3DDevice9*);
IDirect3DDevice9_GetNumberOfSwapChains IDirect3DDevice9_GetNumberOfSwapChains_orig = 0;
UINT APIENTRY IDirect3DDevice9_GetNumberOfSwapChains_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_GetNumberOfSwapChains: pDevice: %u", pDevice);
   return IDirect3DDevice9_GetNumberOfSwapChains_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_Reset)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
IDirect3DDevice9_Reset IDirect3DDevice9_Reset_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_Reset_hook(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters){
   vireio::debugf("IDirect3DDevice9_Reset: pDevice: %u, pPresentationParameters: %u, pPresentationParameters->BackBufferWidth: %u, pPresentationParameters->BackBufferHeight: %u, pPresentationParameters->BackBufferFormat: %u, pPresentationParameters->BackBufferCount: %u, pPresentationParameters->MultiSampleType: %u, pPresentationParameters->MultiSampleQuality: %u, pPresentationParameters->SwapEffect: %u, pPresentationParameters->hDeviceWindow: %u, pPresentationParameters->Windowed: %u, pPresentationParameters->EnableAutoDepthStencil: %u, pPresentationParameters->AutoDepthStencilFormat: %u, pPresentationParameters->Flags: %u, pPresentationParameters->FullScreen_RefreshRateInHz: %u, pPresentationParameters->PresentationInterval: %u", pDevice, pPresentationParameters, (pPresentationParameters == NULL)?0:(pPresentationParameters->BackBufferWidth), (pPresentationParameters == NULL)?0:(pPresentationParameters->BackBufferHeight), (pPresentationParameters == NULL)?0:(pPresentationParameters->BackBufferFormat), (pPresentationParameters == NULL)?0:(pPresentationParameters->BackBufferCount), (pPresentationParameters == NULL)?0:(pPresentationParameters->MultiSampleType), (pPresentationParameters == NULL)?0:(pPresentationParameters->MultiSampleQuality), (pPresentationParameters == NULL)?0:(pPresentationParameters->SwapEffect), (pPresentationParameters == NULL)?0:(pPresentationParameters->hDeviceWindow), (pPresentationParameters == NULL)?0:(pPresentationParameters->Windowed), (pPresentationParameters == NULL)?0:(pPresentationParameters->EnableAutoDepthStencil), (pPresentationParameters == NULL)?0:(pPresentationParameters->AutoDepthStencilFormat), (pPresentationParameters == NULL)?0:(pPresentationParameters->Flags), (pPresentationParameters == NULL)?0:(pPresentationParameters->FullScreen_RefreshRateInHz), (pPresentationParameters == NULL)?0:(pPresentationParameters->PresentationInterval));
   return IDirect3DDevice9_Reset_orig(pDevice, pPresentationParameters);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_Present)(IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
IDirect3DDevice9_Present IDirect3DDevice9_Present_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_Present_hook(IDirect3DDevice9* pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion){
   vireio::debugf("IDirect3DDevice9_Present: pDevice: %u, pSourceRect: %u, pDestRect: %u, hDestWindowOverride: %u, pDirtyRegion: %u", pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
   return IDirect3DDevice9_Present_orig(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetBackBuffer)(IDirect3DDevice9*, UINT, UINT, D3DBACKBUFFER_TYPE, IDirect3DSurface9**);
IDirect3DDevice9_GetBackBuffer IDirect3DDevice9_GetBackBuffer_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetBackBuffer_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer){
   vireio::debugf("IDirect3DDevice9_GetBackBuffer: pDevice: %u, iSwapChain: %u, iBackBuffer: %u, Type: %u, ppBackBuffer: %u", pDevice, iSwapChain, iBackBuffer, Type, ppBackBuffer);
   return IDirect3DDevice9_GetBackBuffer_orig(pDevice, iSwapChain, iBackBuffer, Type, ppBackBuffer);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetRasterStatus)(IDirect3DDevice9*, UINT, D3DRASTER_STATUS*);
IDirect3DDevice9_GetRasterStatus IDirect3DDevice9_GetRasterStatus_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetRasterStatus_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus){
   vireio::debugf("IDirect3DDevice9_GetRasterStatus: pDevice: %u, iSwapChain: %u, pRasterStatus: %u, pRasterStatus->InVBlank: %u, pRasterStatus->ScanLine: %u", pDevice, iSwapChain, pRasterStatus, (pRasterStatus == NULL)?0:(pRasterStatus->InVBlank), (pRasterStatus == NULL)?0:(pRasterStatus->ScanLine));
   return IDirect3DDevice9_GetRasterStatus_orig(pDevice, iSwapChain, pRasterStatus);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetDialogBoxMode)(IDirect3DDevice9*, BOOL);
IDirect3DDevice9_SetDialogBoxMode IDirect3DDevice9_SetDialogBoxMode_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetDialogBoxMode_hook(IDirect3DDevice9* pDevice, BOOL bEnableDialogs){
   vireio::debugf("IDirect3DDevice9_SetDialogBoxMode: pDevice: %u, bEnableDialogs: %u", pDevice, bEnableDialogs);
   return IDirect3DDevice9_SetDialogBoxMode_orig(pDevice, bEnableDialogs);
}
typedef void(APIENTRY* IDirect3DDevice9_SetGammaRamp)(IDirect3DDevice9*, UINT, DWORD, CONST D3DGAMMARAMP*);
IDirect3DDevice9_SetGammaRamp IDirect3DDevice9_SetGammaRamp_orig = 0;
void APIENTRY IDirect3DDevice9_SetGammaRamp_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp){
   vireio::debugf("IDirect3DDevice9_SetGammaRamp: pDevice: %u, iSwapChain: %u, Flags: %u, pRamp: %u", pDevice, iSwapChain, Flags, pRamp);
   return IDirect3DDevice9_SetGammaRamp_orig(pDevice, iSwapChain, Flags, pRamp);
}
typedef void(APIENTRY* IDirect3DDevice9_GetGammaRamp)(IDirect3DDevice9*, UINT, D3DGAMMARAMP*);
IDirect3DDevice9_GetGammaRamp IDirect3DDevice9_GetGammaRamp_orig = 0;
void APIENTRY IDirect3DDevice9_GetGammaRamp_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, D3DGAMMARAMP* pRamp){
   vireio::debugf("IDirect3DDevice9_GetGammaRamp: pDevice: %u, iSwapChain: %u, pRamp: %u", pDevice, iSwapChain, pRamp);
   return IDirect3DDevice9_GetGammaRamp_orig(pDevice, iSwapChain, pRamp);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateTexture)(IDirect3DDevice9*, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DTexture9**, HANDLE*);
IDirect3DDevice9_CreateTexture IDirect3DDevice9_CreateTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateTexture_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateTexture: pDevice: %u, Width: %u, Height: %u, Levels: %u, Usage: %u, Format: %u, Pool: %u, ppTexture: %u, pSharedHandle: %u", pDevice, Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
   return IDirect3DDevice9_CreateTexture_orig(pDevice, Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateVolumeTexture)(IDirect3DDevice9*, UINT, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DVolumeTexture9**, HANDLE*);
IDirect3DDevice9_CreateVolumeTexture IDirect3DDevice9_CreateVolumeTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateVolumeTexture_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateVolumeTexture: pDevice: %u, Width: %u, Height: %u, Depth: %u, Levels: %u, Usage: %u, Format: %u, Pool: %u, ppVolumeTexture: %u, pSharedHandle: %u", pDevice, Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
   return IDirect3DDevice9_CreateVolumeTexture_orig(pDevice, Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateCubeTexture)(IDirect3DDevice9*, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DCubeTexture9**, HANDLE*);
IDirect3DDevice9_CreateCubeTexture IDirect3DDevice9_CreateCubeTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateCubeTexture_hook(IDirect3DDevice9* pDevice, UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateCubeTexture: pDevice: %u, EdgeLength: %u, Levels: %u, Usage: %u, Format: %u, Pool: %u, ppCubeTexture: %u, pSharedHandle: %u", pDevice, EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
   return IDirect3DDevice9_CreateCubeTexture_orig(pDevice, EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateVertexBuffer)(IDirect3DDevice9*, UINT, DWORD, DWORD, D3DPOOL, IDirect3DVertexBuffer9**, HANDLE*);
IDirect3DDevice9_CreateVertexBuffer IDirect3DDevice9_CreateVertexBuffer_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateVertexBuffer_hook(IDirect3DDevice9* pDevice, UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateVertexBuffer: pDevice: %u, Length: %u, Usage: %u, FVF: %u, Pool: %u, ppVertexBuffer: %u, pSharedHandle: %u", pDevice, Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
   return IDirect3DDevice9_CreateVertexBuffer_orig(pDevice, Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateIndexBuffer)(IDirect3DDevice9*, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DIndexBuffer9**, HANDLE*);
IDirect3DDevice9_CreateIndexBuffer IDirect3DDevice9_CreateIndexBuffer_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateIndexBuffer_hook(IDirect3DDevice9* pDevice, UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateIndexBuffer: pDevice: %u, Length: %u, Usage: %u, Format: %u, Pool: %u, ppIndexBuffer: %u, pSharedHandle: %u", pDevice, Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
   return IDirect3DDevice9_CreateIndexBuffer_orig(pDevice, Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateRenderTarget)(IDirect3DDevice9*, UINT, UINT, D3DFORMAT, D3DMULTISAMPLE_TYPE, DWORD, BOOL, IDirect3DSurface9**, HANDLE*);
IDirect3DDevice9_CreateRenderTarget IDirect3DDevice9_CreateRenderTarget_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateRenderTarget_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateRenderTarget: pDevice: %u, Width: %u, Height: %u, Format: %u, MultiSample: %u, MultisampleQuality: %u, Lockable: %u, ppSurface: %u, pSharedHandle: %u", pDevice, Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
   return IDirect3DDevice9_CreateRenderTarget_orig(pDevice, Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateDepthStencilSurface)(IDirect3DDevice9*, UINT, UINT, D3DFORMAT, D3DMULTISAMPLE_TYPE, DWORD, BOOL, IDirect3DSurface9**, HANDLE*);
IDirect3DDevice9_CreateDepthStencilSurface IDirect3DDevice9_CreateDepthStencilSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateDepthStencilSurface_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateDepthStencilSurface: pDevice: %u, Width: %u, Height: %u, Format: %u, MultiSample: %u, MultisampleQuality: %u, Discard: %u, ppSurface: %u, pSharedHandle: %u", pDevice, Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
   return IDirect3DDevice9_CreateDepthStencilSurface_orig(pDevice, Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_UpdateSurface)(IDirect3DDevice9*, IDirect3DSurface9*, CONST RECT*, IDirect3DSurface9*, CONST POINT*);
IDirect3DDevice9_UpdateSurface IDirect3DDevice9_UpdateSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_UpdateSurface_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint){
   vireio::debugf("IDirect3DDevice9_UpdateSurface: pDevice: %u, pSourceSurface: %u, pSourceRect: %u, pDestinationSurface: %u, pDestPoint: %u", pDevice, pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
   return IDirect3DDevice9_UpdateSurface_orig(pDevice, pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_UpdateTexture)(IDirect3DDevice9*, IDirect3DBaseTexture9*, IDirect3DBaseTexture9*);
IDirect3DDevice9_UpdateTexture IDirect3DDevice9_UpdateTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_UpdateTexture_hook(IDirect3DDevice9* pDevice, IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture){
   vireio::debugf("IDirect3DDevice9_UpdateTexture: pDevice: %u, pSourceTexture: %u, pDestinationTexture: %u", pDevice, pSourceTexture, pDestinationTexture);
   return IDirect3DDevice9_UpdateTexture_orig(pDevice, pSourceTexture, pDestinationTexture);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetRenderTargetData)(IDirect3DDevice9*, IDirect3DSurface9*, IDirect3DSurface9*);
IDirect3DDevice9_GetRenderTargetData IDirect3DDevice9_GetRenderTargetData_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetRenderTargetData_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface){
   vireio::debugf("IDirect3DDevice9_GetRenderTargetData: pDevice: %u, pRenderTarget: %u, pDestSurface: %u", pDevice, pRenderTarget, pDestSurface);
   return IDirect3DDevice9_GetRenderTargetData_orig(pDevice, pRenderTarget, pDestSurface);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetFrontBufferData)(IDirect3DDevice9*, UINT, IDirect3DSurface9*);
IDirect3DDevice9_GetFrontBufferData IDirect3DDevice9_GetFrontBufferData_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetFrontBufferData_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, IDirect3DSurface9* pDestSurface){
   vireio::debugf("IDirect3DDevice9_GetFrontBufferData: pDevice: %u, iSwapChain: %u, pDestSurface: %u", pDevice, iSwapChain, pDestSurface);
   return IDirect3DDevice9_GetFrontBufferData_orig(pDevice, iSwapChain, pDestSurface);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_StretchRect)(IDirect3DDevice9*, IDirect3DSurface9*, CONST RECT*, IDirect3DSurface9*, CONST RECT*, D3DTEXTUREFILTERTYPE);
IDirect3DDevice9_StretchRect IDirect3DDevice9_StretchRect_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_StretchRect_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter){
   vireio::debugf("IDirect3DDevice9_StretchRect: pDevice: %u, pSourceSurface: %u, pSourceRect: %u, pDestSurface: %u, pDestRect: %u, Filter: %u", pDevice, pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
   return IDirect3DDevice9_StretchRect_orig(pDevice, pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_ColorFill)(IDirect3DDevice9*, IDirect3DSurface9*, CONST RECT*, D3DCOLOR);
IDirect3DDevice9_ColorFill IDirect3DDevice9_ColorFill_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_ColorFill_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color){
   vireio::debugf("IDirect3DDevice9_ColorFill: pDevice: %u, pSurface: %u, pRect: %u, color: %u", pDevice, pSurface, pRect, color);
   return IDirect3DDevice9_ColorFill_orig(pDevice, pSurface, pRect, color);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateOffscreenPlainSurface)(IDirect3DDevice9*, UINT, UINT, D3DFORMAT, D3DPOOL, IDirect3DSurface9**, HANDLE*);
IDirect3DDevice9_CreateOffscreenPlainSurface IDirect3DDevice9_CreateOffscreenPlainSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateOffscreenPlainSurface_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateOffscreenPlainSurface: pDevice: %u, Width: %u, Height: %u, Format: %u, Pool: %u, ppSurface: %u, pSharedHandle: %u", pDevice, Width, Height, Format, Pool, ppSurface, pSharedHandle);
   return IDirect3DDevice9_CreateOffscreenPlainSurface_orig(pDevice, Width, Height, Format, Pool, ppSurface, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetRenderTarget)(IDirect3DDevice9*, DWORD, IDirect3DSurface9*);
IDirect3DDevice9_SetRenderTarget IDirect3DDevice9_SetRenderTarget_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetRenderTarget_hook(IDirect3DDevice9* pDevice, DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget){
   vireio::debugf("IDirect3DDevice9_SetRenderTarget: pDevice: %u, RenderTargetIndex: %u, pRenderTarget: %u", pDevice, RenderTargetIndex, pRenderTarget);
   return IDirect3DDevice9_SetRenderTarget_orig(pDevice, RenderTargetIndex, pRenderTarget);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetRenderTarget)(IDirect3DDevice9*, DWORD, IDirect3DSurface9**);
IDirect3DDevice9_GetRenderTarget IDirect3DDevice9_GetRenderTarget_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetRenderTarget_hook(IDirect3DDevice9* pDevice, DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget){
   vireio::debugf("IDirect3DDevice9_GetRenderTarget: pDevice: %u, RenderTargetIndex: %u, ppRenderTarget: %u", pDevice, RenderTargetIndex, ppRenderTarget);
   return IDirect3DDevice9_GetRenderTarget_orig(pDevice, RenderTargetIndex, ppRenderTarget);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetDepthStencilSurface)(IDirect3DDevice9*, IDirect3DSurface9*);
IDirect3DDevice9_SetDepthStencilSurface IDirect3DDevice9_SetDepthStencilSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetDepthStencilSurface_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pNewZStencil){
   vireio::debugf("IDirect3DDevice9_SetDepthStencilSurface: pDevice: %u, pNewZStencil: %u", pDevice, pNewZStencil);
   return IDirect3DDevice9_SetDepthStencilSurface_orig(pDevice, pNewZStencil);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetDepthStencilSurface)(IDirect3DDevice9*, IDirect3DSurface9**);
IDirect3DDevice9_GetDepthStencilSurface IDirect3DDevice9_GetDepthStencilSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetDepthStencilSurface_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9** ppZStencilSurface){
   vireio::debugf("IDirect3DDevice9_GetDepthStencilSurface: pDevice: %u, ppZStencilSurface: %u", pDevice, ppZStencilSurface);
   return IDirect3DDevice9_GetDepthStencilSurface_orig(pDevice, ppZStencilSurface);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_BeginScene)(IDirect3DDevice9*);
IDirect3DDevice9_BeginScene IDirect3DDevice9_BeginScene_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_BeginScene_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_BeginScene: pDevice: %u", pDevice);
   return IDirect3DDevice9_BeginScene_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_Clear)(IDirect3DDevice9*, DWORD, CONST D3DRECT*, DWORD, D3DCOLOR, float, DWORD);
IDirect3DDevice9_Clear IDirect3DDevice9_Clear_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_Clear_hook(IDirect3DDevice9* pDevice, DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil){
   vireio::debugf("IDirect3DDevice9_Clear: pDevice: %u, Count: %u, pRects: %u, pRects->x1: %u, pRects->y1: %u, pRects->x2: %u, pRects->y2: %u, Flags: %u, Color: %u, Z: %u, Stencil: %u", pDevice, Count, pRects, (pRects == NULL)?0:(pRects->x1), (pRects == NULL)?0:(pRects->y1), (pRects == NULL)?0:(pRects->x2), (pRects == NULL)?0:(pRects->y2), Flags, Color, Z, Stencil);
   return IDirect3DDevice9_Clear_orig(pDevice, Count, pRects, Flags, Color, Z, Stencil);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetTransform)(IDirect3DDevice9*, D3DTRANSFORMSTATETYPE, CONST D3DMATRIX*);
IDirect3DDevice9_SetTransform IDirect3DDevice9_SetTransform_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetTransform_hook(IDirect3DDevice9* pDevice, D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix){
   vireio::debugf("IDirect3DDevice9_SetTransform: pDevice: %u, State: %u, pMatrix: %u, pMatrix->_11: %f, pMatrix->_12: %f, pMatrix->_13: %f, pMatrix->_14: %f, pMatrix->_21: %f, pMatrix->_22: %f, pMatrix->_23: %f, pMatrix->_24: %f, pMatrix->_31: %f, pMatrix->_32: %f, pMatrix->_33: %f, pMatrix->_34: %f, pMatrix->_41: %f, pMatrix->_42: %f, pMatrix->_43: %f, pMatrix->_44: %f", pDevice, State, pMatrix, (pMatrix == NULL)?0:(pMatrix->_11), (pMatrix == NULL)?0:(pMatrix->_12), (pMatrix == NULL)?0:(pMatrix->_13), (pMatrix == NULL)?0:(pMatrix->_14), (pMatrix == NULL)?0:(pMatrix->_21), (pMatrix == NULL)?0:(pMatrix->_22), (pMatrix == NULL)?0:(pMatrix->_23), (pMatrix == NULL)?0:(pMatrix->_24), (pMatrix == NULL)?0:(pMatrix->_31), (pMatrix == NULL)?0:(pMatrix->_32), (pMatrix == NULL)?0:(pMatrix->_33), (pMatrix == NULL)?0:(pMatrix->_34), (pMatrix == NULL)?0:(pMatrix->_41), (pMatrix == NULL)?0:(pMatrix->_42), (pMatrix == NULL)?0:(pMatrix->_43), (pMatrix == NULL)?0:(pMatrix->_44));
   return IDirect3DDevice9_SetTransform_orig(pDevice, State, pMatrix);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetTransform)(IDirect3DDevice9*, D3DTRANSFORMSTATETYPE, D3DMATRIX*);
IDirect3DDevice9_GetTransform IDirect3DDevice9_GetTransform_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetTransform_hook(IDirect3DDevice9* pDevice, D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix){
   vireio::debugf("IDirect3DDevice9_GetTransform: pDevice: %u, State: %u, pMatrix: %u, pMatrix->_11: %f, pMatrix->_12: %f, pMatrix->_13: %f, pMatrix->_14: %f, pMatrix->_21: %f, pMatrix->_22: %f, pMatrix->_23: %f, pMatrix->_24: %f, pMatrix->_31: %f, pMatrix->_32: %f, pMatrix->_33: %f, pMatrix->_34: %f, pMatrix->_41: %f, pMatrix->_42: %f, pMatrix->_43: %f, pMatrix->_44: %f", pDevice, State, pMatrix, (pMatrix == NULL)?0:(pMatrix->_11), (pMatrix == NULL)?0:(pMatrix->_12), (pMatrix == NULL)?0:(pMatrix->_13), (pMatrix == NULL)?0:(pMatrix->_14), (pMatrix == NULL)?0:(pMatrix->_21), (pMatrix == NULL)?0:(pMatrix->_22), (pMatrix == NULL)?0:(pMatrix->_23), (pMatrix == NULL)?0:(pMatrix->_24), (pMatrix == NULL)?0:(pMatrix->_31), (pMatrix == NULL)?0:(pMatrix->_32), (pMatrix == NULL)?0:(pMatrix->_33), (pMatrix == NULL)?0:(pMatrix->_34), (pMatrix == NULL)?0:(pMatrix->_41), (pMatrix == NULL)?0:(pMatrix->_42), (pMatrix == NULL)?0:(pMatrix->_43), (pMatrix == NULL)?0:(pMatrix->_44));
   return IDirect3DDevice9_GetTransform_orig(pDevice, State, pMatrix);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_MultiplyTransform)(IDirect3DDevice9*, D3DTRANSFORMSTATETYPE, CONST D3DMATRIX*);
IDirect3DDevice9_MultiplyTransform IDirect3DDevice9_MultiplyTransform_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_MultiplyTransform_hook(IDirect3DDevice9* pDevice, D3DTRANSFORMSTATETYPE arg1, CONST D3DMATRIX* arg2){
   vireio::debugf("IDirect3DDevice9_MultiplyTransform: pDevice: %u, arg1: %u, arg2: %u, arg2->_11: %f, arg2->_12: %f, arg2->_13: %f, arg2->_14: %f, arg2->_21: %f, arg2->_22: %f, arg2->_23: %f, arg2->_24: %f, arg2->_31: %f, arg2->_32: %f, arg2->_33: %f, arg2->_34: %f, arg2->_41: %f, arg2->_42: %f, arg2->_43: %f, arg2->_44: %f", pDevice, arg1, arg2, (arg2 == NULL)?0:(arg2->_11), (arg2 == NULL)?0:(arg2->_12), (arg2 == NULL)?0:(arg2->_13), (arg2 == NULL)?0:(arg2->_14), (arg2 == NULL)?0:(arg2->_21), (arg2 == NULL)?0:(arg2->_22), (arg2 == NULL)?0:(arg2->_23), (arg2 == NULL)?0:(arg2->_24), (arg2 == NULL)?0:(arg2->_31), (arg2 == NULL)?0:(arg2->_32), (arg2 == NULL)?0:(arg2->_33), (arg2 == NULL)?0:(arg2->_34), (arg2 == NULL)?0:(arg2->_41), (arg2 == NULL)?0:(arg2->_42), (arg2 == NULL)?0:(arg2->_43), (arg2 == NULL)?0:(arg2->_44));
   return IDirect3DDevice9_MultiplyTransform_orig(pDevice, arg1, arg2);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetViewport)(IDirect3DDevice9*, CONST D3DVIEWPORT9*);
IDirect3DDevice9_SetViewport IDirect3DDevice9_SetViewport_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetViewport_hook(IDirect3DDevice9* pDevice, CONST D3DVIEWPORT9* pViewport){
   vireio::debugf("IDirect3DDevice9_SetViewport: pDevice: %u, pViewport: %u, pViewport->X: %u, pViewport->Y: %u, pViewport->Width: %u, pViewport->Height: %u, pViewport->MinZ: %f, pViewport->MaxZ: %f", pDevice, pViewport, (pViewport == NULL)?0:(pViewport->X), (pViewport == NULL)?0:(pViewport->Y), (pViewport == NULL)?0:(pViewport->Width), (pViewport == NULL)?0:(pViewport->Height), (pViewport == NULL)?0:(pViewport->MinZ), (pViewport == NULL)?0:(pViewport->MaxZ));
   return IDirect3DDevice9_SetViewport_orig(pDevice, pViewport);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetViewport)(IDirect3DDevice9*, D3DVIEWPORT9*);
IDirect3DDevice9_GetViewport IDirect3DDevice9_GetViewport_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetViewport_hook(IDirect3DDevice9* pDevice, D3DVIEWPORT9* pViewport){
   vireio::debugf("IDirect3DDevice9_GetViewport: pDevice: %u, pViewport: %u, pViewport->X: %u, pViewport->Y: %u, pViewport->Width: %u, pViewport->Height: %u, pViewport->MinZ: %f, pViewport->MaxZ: %f", pDevice, pViewport, (pViewport == NULL)?0:(pViewport->X), (pViewport == NULL)?0:(pViewport->Y), (pViewport == NULL)?0:(pViewport->Width), (pViewport == NULL)?0:(pViewport->Height), (pViewport == NULL)?0:(pViewport->MinZ), (pViewport == NULL)?0:(pViewport->MaxZ));
   return IDirect3DDevice9_GetViewport_orig(pDevice, pViewport);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetMaterial)(IDirect3DDevice9*, CONST D3DMATERIAL9*);
IDirect3DDevice9_SetMaterial IDirect3DDevice9_SetMaterial_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetMaterial_hook(IDirect3DDevice9* pDevice, CONST D3DMATERIAL9* pMaterial){
   vireio::debugf("IDirect3DDevice9_SetMaterial: pDevice: %u, pMaterial: %u, pMaterial->Power: %f", pDevice, pMaterial, (pMaterial == NULL)?0:(pMaterial->Power));
   return IDirect3DDevice9_SetMaterial_orig(pDevice, pMaterial);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetMaterial)(IDirect3DDevice9*, D3DMATERIAL9*);
IDirect3DDevice9_GetMaterial IDirect3DDevice9_GetMaterial_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetMaterial_hook(IDirect3DDevice9* pDevice, D3DMATERIAL9* pMaterial){
   vireio::debugf("IDirect3DDevice9_GetMaterial: pDevice: %u, pMaterial: %u, pMaterial->Power: %f", pDevice, pMaterial, (pMaterial == NULL)?0:(pMaterial->Power));
   return IDirect3DDevice9_GetMaterial_orig(pDevice, pMaterial);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetLight)(IDirect3DDevice9*, DWORD, CONST D3DLIGHT9*);
IDirect3DDevice9_SetLight IDirect3DDevice9_SetLight_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetLight_hook(IDirect3DDevice9* pDevice, DWORD Index, CONST D3DLIGHT9* arg2){
   vireio::debugf("IDirect3DDevice9_SetLight: pDevice: %u, Index: %u, arg2: %u, arg2->Type: %u, arg2->Range: %f, arg2->Falloff: %f, arg2->Attenuation0: %f, arg2->Attenuation1: %f, arg2->Attenuation2: %f, arg2->Theta: %f, arg2->Phi: %f", pDevice, Index, arg2, (arg2 == NULL)?0:(arg2->Type), (arg2 == NULL)?0:(arg2->Range), (arg2 == NULL)?0:(arg2->Falloff), (arg2 == NULL)?0:(arg2->Attenuation0), (arg2 == NULL)?0:(arg2->Attenuation1), (arg2 == NULL)?0:(arg2->Attenuation2), (arg2 == NULL)?0:(arg2->Theta), (arg2 == NULL)?0:(arg2->Phi));
   return IDirect3DDevice9_SetLight_orig(pDevice, Index, arg2);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetLight)(IDirect3DDevice9*, DWORD, D3DLIGHT9*);
IDirect3DDevice9_GetLight IDirect3DDevice9_GetLight_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetLight_hook(IDirect3DDevice9* pDevice, DWORD Index, D3DLIGHT9* arg2){
   vireio::debugf("IDirect3DDevice9_GetLight: pDevice: %u, Index: %u, arg2: %u, arg2->Type: %u, arg2->Range: %f, arg2->Falloff: %f, arg2->Attenuation0: %f, arg2->Attenuation1: %f, arg2->Attenuation2: %f, arg2->Theta: %f, arg2->Phi: %f", pDevice, Index, arg2, (arg2 == NULL)?0:(arg2->Type), (arg2 == NULL)?0:(arg2->Range), (arg2 == NULL)?0:(arg2->Falloff), (arg2 == NULL)?0:(arg2->Attenuation0), (arg2 == NULL)?0:(arg2->Attenuation1), (arg2 == NULL)?0:(arg2->Attenuation2), (arg2 == NULL)?0:(arg2->Theta), (arg2 == NULL)?0:(arg2->Phi));
   return IDirect3DDevice9_GetLight_orig(pDevice, Index, arg2);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_LightEnable)(IDirect3DDevice9*, DWORD, BOOL);
IDirect3DDevice9_LightEnable IDirect3DDevice9_LightEnable_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_LightEnable_hook(IDirect3DDevice9* pDevice, DWORD Index, BOOL Enable){
   vireio::debugf("IDirect3DDevice9_LightEnable: pDevice: %u, Index: %u, Enable: %u", pDevice, Index, Enable);
   return IDirect3DDevice9_LightEnable_orig(pDevice, Index, Enable);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetLightEnable)(IDirect3DDevice9*, DWORD, BOOL*);
IDirect3DDevice9_GetLightEnable IDirect3DDevice9_GetLightEnable_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetLightEnable_hook(IDirect3DDevice9* pDevice, DWORD Index, BOOL* pEnable){
   vireio::debugf("IDirect3DDevice9_GetLightEnable: pDevice: %u, Index: %u, pEnable: %u", pDevice, Index, pEnable);
   return IDirect3DDevice9_GetLightEnable_orig(pDevice, Index, pEnable);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetClipPlane)(IDirect3DDevice9*, DWORD, CONST float*);
IDirect3DDevice9_SetClipPlane IDirect3DDevice9_SetClipPlane_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetClipPlane_hook(IDirect3DDevice9* pDevice, DWORD Index, CONST float* pPlane){
   vireio::debugf("IDirect3DDevice9_SetClipPlane: pDevice: %u, Index: %u, pPlane: %u", pDevice, Index, pPlane);
   return IDirect3DDevice9_SetClipPlane_orig(pDevice, Index, pPlane);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetClipPlane)(IDirect3DDevice9*, DWORD, float*);
IDirect3DDevice9_GetClipPlane IDirect3DDevice9_GetClipPlane_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetClipPlane_hook(IDirect3DDevice9* pDevice, DWORD Index, float* pPlane){
   vireio::debugf("IDirect3DDevice9_GetClipPlane: pDevice: %u, Index: %u, pPlane: %u", pDevice, Index, pPlane);
   return IDirect3DDevice9_GetClipPlane_orig(pDevice, Index, pPlane);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetRenderState)(IDirect3DDevice9*, D3DRENDERSTATETYPE, DWORD);
IDirect3DDevice9_SetRenderState IDirect3DDevice9_SetRenderState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetRenderState_hook(IDirect3DDevice9* pDevice, D3DRENDERSTATETYPE State, DWORD Value){
   vireio::debugf("IDirect3DDevice9_SetRenderState: pDevice: %u, State: %u, Value: %u", pDevice, State, Value);
   return IDirect3DDevice9_SetRenderState_orig(pDevice, State, Value);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetRenderState)(IDirect3DDevice9*, D3DRENDERSTATETYPE, DWORD*);
IDirect3DDevice9_GetRenderState IDirect3DDevice9_GetRenderState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetRenderState_hook(IDirect3DDevice9* pDevice, D3DRENDERSTATETYPE State, DWORD* pValue){
   vireio::debugf("IDirect3DDevice9_GetRenderState: pDevice: %u, State: %u, pValue: %u", pDevice, State, pValue);
   return IDirect3DDevice9_GetRenderState_orig(pDevice, State, pValue);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateStateBlock)(IDirect3DDevice9*, D3DSTATEBLOCKTYPE, IDirect3DStateBlock9**);
IDirect3DDevice9_CreateStateBlock IDirect3DDevice9_CreateStateBlock_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateStateBlock_hook(IDirect3DDevice9* pDevice, D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB){
   vireio::debugf("IDirect3DDevice9_CreateStateBlock: pDevice: %u, Type: %u, ppSB: %u", pDevice, Type, ppSB);
   return IDirect3DDevice9_CreateStateBlock_orig(pDevice, Type, ppSB);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_BeginStateBlock)(IDirect3DDevice9*);
IDirect3DDevice9_BeginStateBlock IDirect3DDevice9_BeginStateBlock_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_BeginStateBlock_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_BeginStateBlock: pDevice: %u", pDevice);
   return IDirect3DDevice9_BeginStateBlock_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_EndStateBlock)(IDirect3DDevice9*, IDirect3DStateBlock9**);
IDirect3DDevice9_EndStateBlock IDirect3DDevice9_EndStateBlock_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_EndStateBlock_hook(IDirect3DDevice9* pDevice, IDirect3DStateBlock9** ppSB){
   vireio::debugf("IDirect3DDevice9_EndStateBlock: pDevice: %u, ppSB: %u", pDevice, ppSB);
   return IDirect3DDevice9_EndStateBlock_orig(pDevice, ppSB);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetClipStatus)(IDirect3DDevice9*, CONST D3DCLIPSTATUS9*);
IDirect3DDevice9_SetClipStatus IDirect3DDevice9_SetClipStatus_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetClipStatus_hook(IDirect3DDevice9* pDevice, CONST D3DCLIPSTATUS9* pClipStatus){
   vireio::debugf("IDirect3DDevice9_SetClipStatus: pDevice: %u, pClipStatus: %u, pClipStatus->ClipUnion: %u, pClipStatus->ClipIntersection: %u", pDevice, pClipStatus, (pClipStatus == NULL)?0:(pClipStatus->ClipUnion), (pClipStatus == NULL)?0:(pClipStatus->ClipIntersection));
   return IDirect3DDevice9_SetClipStatus_orig(pDevice, pClipStatus);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetClipStatus)(IDirect3DDevice9*, D3DCLIPSTATUS9*);
IDirect3DDevice9_GetClipStatus IDirect3DDevice9_GetClipStatus_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetClipStatus_hook(IDirect3DDevice9* pDevice, D3DCLIPSTATUS9* pClipStatus){
   vireio::debugf("IDirect3DDevice9_GetClipStatus: pDevice: %u, pClipStatus: %u, pClipStatus->ClipUnion: %u, pClipStatus->ClipIntersection: %u", pDevice, pClipStatus, (pClipStatus == NULL)?0:(pClipStatus->ClipUnion), (pClipStatus == NULL)?0:(pClipStatus->ClipIntersection));
   return IDirect3DDevice9_GetClipStatus_orig(pDevice, pClipStatus);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetTexture)(IDirect3DDevice9*, DWORD, IDirect3DBaseTexture9**);
IDirect3DDevice9_GetTexture IDirect3DDevice9_GetTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetTexture_hook(IDirect3DDevice9* pDevice, DWORD Stage, IDirect3DBaseTexture9** ppTexture){
   vireio::debugf("IDirect3DDevice9_GetTexture: pDevice: %u, Stage: %u, ppTexture: %u", pDevice, Stage, ppTexture);
   return IDirect3DDevice9_GetTexture_orig(pDevice, Stage, ppTexture);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetTexture)(IDirect3DDevice9*, DWORD, IDirect3DBaseTexture9*);
IDirect3DDevice9_SetTexture IDirect3DDevice9_SetTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetTexture_hook(IDirect3DDevice9* pDevice, DWORD Stage, IDirect3DBaseTexture9* pTexture){
   vireio::debugf("IDirect3DDevice9_SetTexture: pDevice: %u, Stage: %u, pTexture: %u", pDevice, Stage, pTexture);
   return IDirect3DDevice9_SetTexture_orig(pDevice, Stage, pTexture);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetTextureStageState)(IDirect3DDevice9*, DWORD, D3DTEXTURESTAGESTATETYPE, DWORD*);
IDirect3DDevice9_GetTextureStageState IDirect3DDevice9_GetTextureStageState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetTextureStageState_hook(IDirect3DDevice9* pDevice, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue){
   vireio::debugf("IDirect3DDevice9_GetTextureStageState: pDevice: %u, Stage: %u, Type: %u, pValue: %u", pDevice, Stage, Type, pValue);
   return IDirect3DDevice9_GetTextureStageState_orig(pDevice, Stage, Type, pValue);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetTextureStageState)(IDirect3DDevice9*, DWORD, D3DTEXTURESTAGESTATETYPE, DWORD);
IDirect3DDevice9_SetTextureStageState IDirect3DDevice9_SetTextureStageState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetTextureStageState_hook(IDirect3DDevice9* pDevice, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value){
   vireio::debugf("IDirect3DDevice9_SetTextureStageState: pDevice: %u, Stage: %u, Type: %u, Value: %u", pDevice, Stage, Type, Value);
   return IDirect3DDevice9_SetTextureStageState_orig(pDevice, Stage, Type, Value);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetSamplerState)(IDirect3DDevice9*, DWORD, D3DSAMPLERSTATETYPE, DWORD*);
IDirect3DDevice9_GetSamplerState IDirect3DDevice9_GetSamplerState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetSamplerState_hook(IDirect3DDevice9* pDevice, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue){
   vireio::debugf("IDirect3DDevice9_GetSamplerState: pDevice: %u, Sampler: %u, Type: %u, pValue: %u", pDevice, Sampler, Type, pValue);
   return IDirect3DDevice9_GetSamplerState_orig(pDevice, Sampler, Type, pValue);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetSamplerState)(IDirect3DDevice9*, DWORD, D3DSAMPLERSTATETYPE, DWORD);
IDirect3DDevice9_SetSamplerState IDirect3DDevice9_SetSamplerState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetSamplerState_hook(IDirect3DDevice9* pDevice, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value){
   vireio::debugf("IDirect3DDevice9_SetSamplerState: pDevice: %u, Sampler: %u, Type: %u, Value: %u", pDevice, Sampler, Type, Value);
   return IDirect3DDevice9_SetSamplerState_orig(pDevice, Sampler, Type, Value);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_ValidateDevice)(IDirect3DDevice9*, DWORD*);
IDirect3DDevice9_ValidateDevice IDirect3DDevice9_ValidateDevice_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_ValidateDevice_hook(IDirect3DDevice9* pDevice, DWORD* pNumPasses){
   vireio::debugf("IDirect3DDevice9_ValidateDevice: pDevice: %u, pNumPasses: %u", pDevice, pNumPasses);
   return IDirect3DDevice9_ValidateDevice_orig(pDevice, pNumPasses);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPaletteEntries)(IDirect3DDevice9*, UINT, CONST PALETTEENTRY*);
IDirect3DDevice9_SetPaletteEntries IDirect3DDevice9_SetPaletteEntries_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPaletteEntries_hook(IDirect3DDevice9* pDevice, UINT PaletteNumber, CONST PALETTEENTRY* pEntries){
   vireio::debugf("IDirect3DDevice9_SetPaletteEntries: pDevice: %u, PaletteNumber: %u, pEntries: %u", pDevice, PaletteNumber, pEntries);
   return IDirect3DDevice9_SetPaletteEntries_orig(pDevice, PaletteNumber, pEntries);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPaletteEntries)(IDirect3DDevice9*, UINT, PALETTEENTRY*);
IDirect3DDevice9_GetPaletteEntries IDirect3DDevice9_GetPaletteEntries_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPaletteEntries_hook(IDirect3DDevice9* pDevice, UINT PaletteNumber, PALETTEENTRY* pEntries){
   vireio::debugf("IDirect3DDevice9_GetPaletteEntries: pDevice: %u, PaletteNumber: %u, pEntries: %u", pDevice, PaletteNumber, pEntries);
   return IDirect3DDevice9_GetPaletteEntries_orig(pDevice, PaletteNumber, pEntries);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetCurrentTexturePalette)(IDirect3DDevice9*, UINT);
IDirect3DDevice9_SetCurrentTexturePalette IDirect3DDevice9_SetCurrentTexturePalette_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetCurrentTexturePalette_hook(IDirect3DDevice9* pDevice, UINT PaletteNumber){
   vireio::debugf("IDirect3DDevice9_SetCurrentTexturePalette: pDevice: %u, PaletteNumber: %u", pDevice, PaletteNumber);
   return IDirect3DDevice9_SetCurrentTexturePalette_orig(pDevice, PaletteNumber);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetCurrentTexturePalette)(IDirect3DDevice9*, UINT*);
IDirect3DDevice9_GetCurrentTexturePalette IDirect3DDevice9_GetCurrentTexturePalette_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetCurrentTexturePalette_hook(IDirect3DDevice9* pDevice, UINT* PaletteNumber){
   vireio::debugf("IDirect3DDevice9_GetCurrentTexturePalette: pDevice: %u, PaletteNumber: %u", pDevice, PaletteNumber);
   return IDirect3DDevice9_GetCurrentTexturePalette_orig(pDevice, PaletteNumber);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetScissorRect)(IDirect3DDevice9*, CONST RECT*);
IDirect3DDevice9_SetScissorRect IDirect3DDevice9_SetScissorRect_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetScissorRect_hook(IDirect3DDevice9* pDevice, CONST RECT* pRect){
   vireio::debugf("IDirect3DDevice9_SetScissorRect: pDevice: %u, pRect: %u", pDevice, pRect);
   return IDirect3DDevice9_SetScissorRect_orig(pDevice, pRect);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetScissorRect)(IDirect3DDevice9*, RECT*);
IDirect3DDevice9_GetScissorRect IDirect3DDevice9_GetScissorRect_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetScissorRect_hook(IDirect3DDevice9* pDevice, RECT* pRect){
   vireio::debugf("IDirect3DDevice9_GetScissorRect: pDevice: %u, pRect: %u", pDevice, pRect);
   return IDirect3DDevice9_GetScissorRect_orig(pDevice, pRect);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetSoftwareVertexProcessing)(IDirect3DDevice9*, BOOL);
IDirect3DDevice9_SetSoftwareVertexProcessing IDirect3DDevice9_SetSoftwareVertexProcessing_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetSoftwareVertexProcessing_hook(IDirect3DDevice9* pDevice, BOOL bSoftware){
   vireio::debugf("IDirect3DDevice9_SetSoftwareVertexProcessing: pDevice: %u, bSoftware: %u", pDevice, bSoftware);
   return IDirect3DDevice9_SetSoftwareVertexProcessing_orig(pDevice, bSoftware);
}
typedef BOOL(APIENTRY* IDirect3DDevice9_GetSoftwareVertexProcessing)(IDirect3DDevice9*);
IDirect3DDevice9_GetSoftwareVertexProcessing IDirect3DDevice9_GetSoftwareVertexProcessing_orig = 0;
BOOL APIENTRY IDirect3DDevice9_GetSoftwareVertexProcessing_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_GetSoftwareVertexProcessing: pDevice: %u", pDevice);
   return IDirect3DDevice9_GetSoftwareVertexProcessing_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetNPatchMode)(IDirect3DDevice9*, float);
IDirect3DDevice9_SetNPatchMode IDirect3DDevice9_SetNPatchMode_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetNPatchMode_hook(IDirect3DDevice9* pDevice, float nSegments){
   vireio::debugf("IDirect3DDevice9_SetNPatchMode: pDevice: %u, nSegments: %u", pDevice, nSegments);
   return IDirect3DDevice9_SetNPatchMode_orig(pDevice, nSegments);
}
typedef float(APIENTRY* IDirect3DDevice9_GetNPatchMode)(IDirect3DDevice9*);
IDirect3DDevice9_GetNPatchMode IDirect3DDevice9_GetNPatchMode_orig = 0;
float APIENTRY IDirect3DDevice9_GetNPatchMode_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_GetNPatchMode: pDevice: %u", pDevice);
   return IDirect3DDevice9_GetNPatchMode_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawPrimitive)(IDirect3DDevice9*, D3DPRIMITIVETYPE, UINT, UINT);
IDirect3DDevice9_DrawPrimitive IDirect3DDevice9_DrawPrimitive_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawPrimitive_hook(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount){
   vireio::debugf("IDirect3DDevice9_DrawPrimitive: pDevice: %u, PrimitiveType: %u, StartVertex: %u, PrimitiveCount: %u", pDevice, PrimitiveType, StartVertex, PrimitiveCount);
   return IDirect3DDevice9_DrawPrimitive_orig(pDevice, PrimitiveType, StartVertex, PrimitiveCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawIndexedPrimitive)(IDirect3DDevice9*, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);
IDirect3DDevice9_DrawIndexedPrimitive IDirect3DDevice9_DrawIndexedPrimitive_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawIndexedPrimitive_hook(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE arg1, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount){
   vireio::debugf("IDirect3DDevice9_DrawIndexedPrimitive: pDevice: %u, arg1: %u, BaseVertexIndex: %u, MinVertexIndex: %u, NumVertices: %u, startIndex: %u, primCount: %u", pDevice, arg1, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
   return IDirect3DDevice9_DrawIndexedPrimitive_orig(pDevice, arg1, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawPrimitiveUP)(IDirect3DDevice9*, D3DPRIMITIVETYPE, UINT, CONST void*, UINT);
IDirect3DDevice9_DrawPrimitiveUP IDirect3DDevice9_DrawPrimitiveUP_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawPrimitiveUP_hook(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride){
   vireio::debugf("IDirect3DDevice9_DrawPrimitiveUP: pDevice: %u, PrimitiveType: %u, PrimitiveCount: %u, pVertexStreamZeroData: %u, VertexStreamZeroStride: %u", pDevice, PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
   return IDirect3DDevice9_DrawPrimitiveUP_orig(pDevice, PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawIndexedPrimitiveUP)(IDirect3DDevice9*, D3DPRIMITIVETYPE, UINT, UINT, UINT, CONST void*, D3DFORMAT, CONST void*, UINT);
IDirect3DDevice9_DrawIndexedPrimitiveUP IDirect3DDevice9_DrawIndexedPrimitiveUP_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawIndexedPrimitiveUP_hook(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride){
   vireio::debugf("IDirect3DDevice9_DrawIndexedPrimitiveUP: pDevice: %u, PrimitiveType: %u, MinVertexIndex: %u, NumVertices: %u, PrimitiveCount: %u, pIndexData: %u, IndexDataFormat: %u, pVertexStreamZeroData: %u, VertexStreamZeroStride: %u", pDevice, PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
   return IDirect3DDevice9_DrawIndexedPrimitiveUP_orig(pDevice, PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_ProcessVertices)(IDirect3DDevice9*, UINT, UINT, UINT, IDirect3DVertexBuffer9*, IDirect3DVertexDeclaration9*, DWORD);
IDirect3DDevice9_ProcessVertices IDirect3DDevice9_ProcessVertices_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_ProcessVertices_hook(IDirect3DDevice9* pDevice, UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags){
   vireio::debugf("IDirect3DDevice9_ProcessVertices: pDevice: %u, SrcStartIndex: %u, DestIndex: %u, VertexCount: %u, pDestBuffer: %u, pVertexDecl: %u, Flags: %u", pDevice, SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
   return IDirect3DDevice9_ProcessVertices_orig(pDevice, SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateVertexDeclaration)(IDirect3DDevice9*, CONST D3DVERTEXELEMENT9*, IDirect3DVertexDeclaration9**);
IDirect3DDevice9_CreateVertexDeclaration IDirect3DDevice9_CreateVertexDeclaration_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateVertexDeclaration_hook(IDirect3DDevice9* pDevice, CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl){
   vireio::debugf("IDirect3DDevice9_CreateVertexDeclaration: pDevice: %u, pVertexElements: %u, ppDecl: %u", pDevice, pVertexElements, ppDecl);
   return IDirect3DDevice9_CreateVertexDeclaration_orig(pDevice, pVertexElements, ppDecl);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexDeclaration)(IDirect3DDevice9*, IDirect3DVertexDeclaration9*);
IDirect3DDevice9_SetVertexDeclaration IDirect3DDevice9_SetVertexDeclaration_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexDeclaration_hook(IDirect3DDevice9* pDevice, IDirect3DVertexDeclaration9* pDecl){
   vireio::debugf("IDirect3DDevice9_SetVertexDeclaration: pDevice: %u, pDecl: %u", pDevice, pDecl);
   return IDirect3DDevice9_SetVertexDeclaration_orig(pDevice, pDecl);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexDeclaration)(IDirect3DDevice9*, IDirect3DVertexDeclaration9**);
IDirect3DDevice9_GetVertexDeclaration IDirect3DDevice9_GetVertexDeclaration_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexDeclaration_hook(IDirect3DDevice9* pDevice, IDirect3DVertexDeclaration9** ppDecl){
   vireio::debugf("IDirect3DDevice9_GetVertexDeclaration: pDevice: %u, ppDecl: %u", pDevice, ppDecl);
   return IDirect3DDevice9_GetVertexDeclaration_orig(pDevice, ppDecl);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetFVF)(IDirect3DDevice9*, DWORD);
IDirect3DDevice9_SetFVF IDirect3DDevice9_SetFVF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetFVF_hook(IDirect3DDevice9* pDevice, DWORD FVF){
   vireio::debugf("IDirect3DDevice9_SetFVF: pDevice: %u, FVF: %u", pDevice, FVF);
   return IDirect3DDevice9_SetFVF_orig(pDevice, FVF);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetFVF)(IDirect3DDevice9*, DWORD*);
IDirect3DDevice9_GetFVF IDirect3DDevice9_GetFVF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetFVF_hook(IDirect3DDevice9* pDevice, DWORD* pFVF){
   vireio::debugf("IDirect3DDevice9_GetFVF: pDevice: %u, pFVF: %u", pDevice, pFVF);
   return IDirect3DDevice9_GetFVF_orig(pDevice, pFVF);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateVertexShader)(IDirect3DDevice9*, CONST DWORD*, IDirect3DVertexShader9**);
IDirect3DDevice9_CreateVertexShader IDirect3DDevice9_CreateVertexShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateVertexShader_hook(IDirect3DDevice9* pDevice, CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader){
   vireio::debugf("IDirect3DDevice9_CreateVertexShader: pDevice: %u, pFunction: %u, ppShader: %u", pDevice, pFunction, ppShader);
   return IDirect3DDevice9_CreateVertexShader_orig(pDevice, pFunction, ppShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexShader)(IDirect3DDevice9*, IDirect3DVertexShader9**);
IDirect3DDevice9_GetVertexShader IDirect3DDevice9_GetVertexShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexShader_hook(IDirect3DDevice9* pDevice, IDirect3DVertexShader9** ppShader){
   vireio::debugf("IDirect3DDevice9_GetVertexShader: pDevice: %u, ppShader: %u", pDevice, ppShader);
   return IDirect3DDevice9_GetVertexShader_orig(pDevice, ppShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexShaderConstantF)(IDirect3DDevice9*, UINT, float*, UINT);
IDirect3DDevice9_GetVertexShaderConstantF IDirect3DDevice9_GetVertexShaderConstantF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexShaderConstantF_hook(IDirect3DDevice9* pDevice, UINT StartRegister, float* pConstantData, UINT Vector4fCount){
   vireio::debugf("IDirect3DDevice9_GetVertexShaderConstantF: pDevice: %u, StartRegister: %u, pConstantData: %u, Vector4fCount: %u", pDevice, StartRegister, pConstantData, Vector4fCount);
   return IDirect3DDevice9_GetVertexShaderConstantF_orig(pDevice, StartRegister, pConstantData, Vector4fCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexShaderConstantI)(IDirect3DDevice9*, UINT, CONST int*, UINT);
IDirect3DDevice9_SetVertexShaderConstantI IDirect3DDevice9_SetVertexShaderConstantI_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexShaderConstantI_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount){
   vireio::debugf("IDirect3DDevice9_SetVertexShaderConstantI: pDevice: %u, StartRegister: %u, pConstantData: %u, Vector4iCount: %u", pDevice, StartRegister, pConstantData, Vector4iCount);
   return IDirect3DDevice9_SetVertexShaderConstantI_orig(pDevice, StartRegister, pConstantData, Vector4iCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexShaderConstantI)(IDirect3DDevice9*, UINT, int*, UINT);
IDirect3DDevice9_GetVertexShaderConstantI IDirect3DDevice9_GetVertexShaderConstantI_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexShaderConstantI_hook(IDirect3DDevice9* pDevice, UINT StartRegister, int* pConstantData, UINT Vector4iCount){
   vireio::debugf("IDirect3DDevice9_GetVertexShaderConstantI: pDevice: %u, StartRegister: %u, pConstantData: %u, Vector4iCount: %u", pDevice, StartRegister, pConstantData, Vector4iCount);
   return IDirect3DDevice9_GetVertexShaderConstantI_orig(pDevice, StartRegister, pConstantData, Vector4iCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexShaderConstantB)(IDirect3DDevice9*, UINT, CONST BOOL*, UINT );
IDirect3DDevice9_SetVertexShaderConstantB IDirect3DDevice9_SetVertexShaderConstantB_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexShaderConstantB_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount){
   vireio::debugf("IDirect3DDevice9_SetVertexShaderConstantB: pDevice: %u, StartRegister: %u, pConstantData: %u, BoolCount: %u", pDevice, StartRegister, pConstantData, BoolCount);
   return IDirect3DDevice9_SetVertexShaderConstantB_orig(pDevice, StartRegister, pConstantData, BoolCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexShaderConstantB)(IDirect3DDevice9*, UINT, BOOL*, UINT);
IDirect3DDevice9_GetVertexShaderConstantB IDirect3DDevice9_GetVertexShaderConstantB_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexShaderConstantB_hook(IDirect3DDevice9* pDevice, UINT StartRegister, BOOL* pConstantData, UINT BoolCount){
   vireio::debugf("IDirect3DDevice9_GetVertexShaderConstantB: pDevice: %u, StartRegister: %u, pConstantData: %u, BoolCount: %u", pDevice, StartRegister, pConstantData, BoolCount);
   return IDirect3DDevice9_GetVertexShaderConstantB_orig(pDevice, StartRegister, pConstantData, BoolCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetStreamSource)(IDirect3DDevice9*, UINT, IDirect3DVertexBuffer9*, UINT, UINT);
IDirect3DDevice9_SetStreamSource IDirect3DDevice9_SetStreamSource_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetStreamSource_hook(IDirect3DDevice9* pDevice, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride){
   vireio::debugf("IDirect3DDevice9_SetStreamSource: pDevice: %u, StreamNumber: %u, pStreamData: %u, OffsetInBytes: %u, Stride: %u", pDevice, StreamNumber, pStreamData, OffsetInBytes, Stride);
   return IDirect3DDevice9_SetStreamSource_orig(pDevice, StreamNumber, pStreamData, OffsetInBytes, Stride);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetStreamSource)(IDirect3DDevice9*, UINT, IDirect3DVertexBuffer9**, UINT*, UINT*);
IDirect3DDevice9_GetStreamSource IDirect3DDevice9_GetStreamSource_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetStreamSource_hook(IDirect3DDevice9* pDevice, UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride){
   vireio::debugf("IDirect3DDevice9_GetStreamSource: pDevice: %u, StreamNumber: %u, ppStreamData: %u, pOffsetInBytes: %u, pStride: %u", pDevice, StreamNumber, ppStreamData, pOffsetInBytes, pStride);
   return IDirect3DDevice9_GetStreamSource_orig(pDevice, StreamNumber, ppStreamData, pOffsetInBytes, pStride);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetStreamSourceFreq)(IDirect3DDevice9*, UINT, UINT);
IDirect3DDevice9_SetStreamSourceFreq IDirect3DDevice9_SetStreamSourceFreq_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetStreamSourceFreq_hook(IDirect3DDevice9* pDevice, UINT StreamNumber, UINT Setting){
   vireio::debugf("IDirect3DDevice9_SetStreamSourceFreq: pDevice: %u, StreamNumber: %u, Setting: %u", pDevice, StreamNumber, Setting);
   return IDirect3DDevice9_SetStreamSourceFreq_orig(pDevice, StreamNumber, Setting);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetStreamSourceFreq)(IDirect3DDevice9*, UINT, UINT*);
IDirect3DDevice9_GetStreamSourceFreq IDirect3DDevice9_GetStreamSourceFreq_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetStreamSourceFreq_hook(IDirect3DDevice9* pDevice, UINT StreamNumber, UINT* pSetting){
   vireio::debugf("IDirect3DDevice9_GetStreamSourceFreq: pDevice: %u, StreamNumber: %u, pSetting: %u", pDevice, StreamNumber, pSetting);
   return IDirect3DDevice9_GetStreamSourceFreq_orig(pDevice, StreamNumber, pSetting);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetIndices)(IDirect3DDevice9*, IDirect3DIndexBuffer9*);
IDirect3DDevice9_SetIndices IDirect3DDevice9_SetIndices_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetIndices_hook(IDirect3DDevice9* pDevice, IDirect3DIndexBuffer9* pIndexData){
   vireio::debugf("IDirect3DDevice9_SetIndices: pDevice: %u, pIndexData: %u", pDevice, pIndexData);
   return IDirect3DDevice9_SetIndices_orig(pDevice, pIndexData);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetIndices)(IDirect3DDevice9*, IDirect3DIndexBuffer9**);
IDirect3DDevice9_GetIndices IDirect3DDevice9_GetIndices_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetIndices_hook(IDirect3DDevice9* pDevice, IDirect3DIndexBuffer9** ppIndexData){
   vireio::debugf("IDirect3DDevice9_GetIndices: pDevice: %u, ppIndexData: %u", pDevice, ppIndexData);
   return IDirect3DDevice9_GetIndices_orig(pDevice, ppIndexData);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreatePixelShader)(IDirect3DDevice9*, CONST DWORD*, IDirect3DPixelShader9**);
IDirect3DDevice9_CreatePixelShader IDirect3DDevice9_CreatePixelShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreatePixelShader_hook(IDirect3DDevice9* pDevice, CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader){
   vireio::debugf("IDirect3DDevice9_CreatePixelShader: pDevice: %u, pFunction: %u, ppShader: %u", pDevice, pFunction, ppShader);
   return IDirect3DDevice9_CreatePixelShader_orig(pDevice, pFunction, ppShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPixelShader)(IDirect3DDevice9*, IDirect3DPixelShader9*);
IDirect3DDevice9_SetPixelShader IDirect3DDevice9_SetPixelShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPixelShader_hook(IDirect3DDevice9* pDevice, IDirect3DPixelShader9* pShader){
   vireio::debugf("IDirect3DDevice9_SetPixelShader: pDevice: %u, pShader: %u", pDevice, pShader);
   return IDirect3DDevice9_SetPixelShader_orig(pDevice, pShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPixelShader)(IDirect3DDevice9*, IDirect3DPixelShader9**);
IDirect3DDevice9_GetPixelShader IDirect3DDevice9_GetPixelShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPixelShader_hook(IDirect3DDevice9* pDevice, IDirect3DPixelShader9** ppShader){
   vireio::debugf("IDirect3DDevice9_GetPixelShader: pDevice: %u, ppShader: %u", pDevice, ppShader);
   return IDirect3DDevice9_GetPixelShader_orig(pDevice, ppShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPixelShaderConstantF)(IDirect3DDevice9*, UINT, float*, UINT);
IDirect3DDevice9_GetPixelShaderConstantF IDirect3DDevice9_GetPixelShaderConstantF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPixelShaderConstantF_hook(IDirect3DDevice9* pDevice, UINT StartRegister, float* pConstantData, UINT Vector4fCount){
   vireio::debugf("IDirect3DDevice9_GetPixelShaderConstantF: pDevice: %u, StartRegister: %u, pConstantData: %u, Vector4fCount: %u", pDevice, StartRegister, pConstantData, Vector4fCount);
   return IDirect3DDevice9_GetPixelShaderConstantF_orig(pDevice, StartRegister, pConstantData, Vector4fCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPixelShaderConstantI)(IDirect3DDevice9*, UINT, CONST int*, UINT);
IDirect3DDevice9_SetPixelShaderConstantI IDirect3DDevice9_SetPixelShaderConstantI_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPixelShaderConstantI_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount){
   vireio::debugf("IDirect3DDevice9_SetPixelShaderConstantI: pDevice: %u, StartRegister: %u, pConstantData: %u, Vector4iCount: %u", pDevice, StartRegister, pConstantData, Vector4iCount);
   return IDirect3DDevice9_SetPixelShaderConstantI_orig(pDevice, StartRegister, pConstantData, Vector4iCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPixelShaderConstantI)(IDirect3DDevice9*, UINT, int*, UINT);
IDirect3DDevice9_GetPixelShaderConstantI IDirect3DDevice9_GetPixelShaderConstantI_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPixelShaderConstantI_hook(IDirect3DDevice9* pDevice, UINT StartRegister, int* pConstantData, UINT Vector4iCount){
   vireio::debugf("IDirect3DDevice9_GetPixelShaderConstantI: pDevice: %u, StartRegister: %u, pConstantData: %u, Vector4iCount: %u", pDevice, StartRegister, pConstantData, Vector4iCount);
   return IDirect3DDevice9_GetPixelShaderConstantI_orig(pDevice, StartRegister, pConstantData, Vector4iCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPixelShaderConstantB)(IDirect3DDevice9*, UINT, CONST BOOL*, UINT );
IDirect3DDevice9_SetPixelShaderConstantB IDirect3DDevice9_SetPixelShaderConstantB_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPixelShaderConstantB_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount){
   vireio::debugf("IDirect3DDevice9_SetPixelShaderConstantB: pDevice: %u, StartRegister: %u, pConstantData: %u, BoolCount: %u", pDevice, StartRegister, pConstantData, BoolCount);
   return IDirect3DDevice9_SetPixelShaderConstantB_orig(pDevice, StartRegister, pConstantData, BoolCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPixelShaderConstantB)(IDirect3DDevice9*, UINT, BOOL*, UINT);
IDirect3DDevice9_GetPixelShaderConstantB IDirect3DDevice9_GetPixelShaderConstantB_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPixelShaderConstantB_hook(IDirect3DDevice9* pDevice, UINT StartRegister, BOOL* pConstantData, UINT BoolCount){
   vireio::debugf("IDirect3DDevice9_GetPixelShaderConstantB: pDevice: %u, StartRegister: %u, pConstantData: %u, BoolCount: %u", pDevice, StartRegister, pConstantData, BoolCount);
   return IDirect3DDevice9_GetPixelShaderConstantB_orig(pDevice, StartRegister, pConstantData, BoolCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawRectPatch)(IDirect3DDevice9*, UINT, CONST float*, CONST D3DRECTPATCH_INFO*);
IDirect3DDevice9_DrawRectPatch IDirect3DDevice9_DrawRectPatch_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawRectPatch_hook(IDirect3DDevice9* pDevice, UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo){
   vireio::debugf("IDirect3DDevice9_DrawRectPatch: pDevice: %u, Handle: %u, pNumSegs: %u, pRectPatchInfo: %u, pRectPatchInfo->StartVertexOffsetWidth: %u, pRectPatchInfo->StartVertexOffsetHeight: %u, pRectPatchInfo->Width: %u, pRectPatchInfo->Height: %u, pRectPatchInfo->Stride: %u, pRectPatchInfo->Basis: %u, pRectPatchInfo->Degree: %u", pDevice, Handle, pNumSegs, pRectPatchInfo, (pRectPatchInfo == NULL)?0:(pRectPatchInfo->StartVertexOffsetWidth), (pRectPatchInfo == NULL)?0:(pRectPatchInfo->StartVertexOffsetHeight), (pRectPatchInfo == NULL)?0:(pRectPatchInfo->Width), (pRectPatchInfo == NULL)?0:(pRectPatchInfo->Height), (pRectPatchInfo == NULL)?0:(pRectPatchInfo->Stride), (pRectPatchInfo == NULL)?0:(pRectPatchInfo->Basis), (pRectPatchInfo == NULL)?0:(pRectPatchInfo->Degree));
   return IDirect3DDevice9_DrawRectPatch_orig(pDevice, Handle, pNumSegs, pRectPatchInfo);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawTriPatch)(IDirect3DDevice9*, UINT, CONST float*, CONST D3DTRIPATCH_INFO*);
IDirect3DDevice9_DrawTriPatch IDirect3DDevice9_DrawTriPatch_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawTriPatch_hook(IDirect3DDevice9* pDevice, UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo){
   vireio::debugf("IDirect3DDevice9_DrawTriPatch: pDevice: %u, Handle: %u, pNumSegs: %u, pTriPatchInfo: %u, pTriPatchInfo->StartVertexOffset: %u, pTriPatchInfo->NumVertices: %u, pTriPatchInfo->Basis: %u, pTriPatchInfo->Degree: %u", pDevice, Handle, pNumSegs, pTriPatchInfo, (pTriPatchInfo == NULL)?0:(pTriPatchInfo->StartVertexOffset), (pTriPatchInfo == NULL)?0:(pTriPatchInfo->NumVertices), (pTriPatchInfo == NULL)?0:(pTriPatchInfo->Basis), (pTriPatchInfo == NULL)?0:(pTriPatchInfo->Degree));
   return IDirect3DDevice9_DrawTriPatch_orig(pDevice, Handle, pNumSegs, pTriPatchInfo);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DeletePatch)(IDirect3DDevice9*, UINT);
IDirect3DDevice9_DeletePatch IDirect3DDevice9_DeletePatch_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DeletePatch_hook(IDirect3DDevice9* pDevice, UINT Handle){
   vireio::debugf("IDirect3DDevice9_DeletePatch: pDevice: %u, Handle: %u", pDevice, Handle);
   return IDirect3DDevice9_DeletePatch_orig(pDevice, Handle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateQuery)(IDirect3DDevice9*, D3DQUERYTYPE, IDirect3DQuery9**);
IDirect3DDevice9_CreateQuery IDirect3DDevice9_CreateQuery_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateQuery_hook(IDirect3DDevice9* pDevice, D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery){
   vireio::debugf("IDirect3DDevice9_CreateQuery: pDevice: %u, Type: %u, ppQuery: %u", pDevice, Type, ppQuery);
   return IDirect3DDevice9_CreateQuery_orig(pDevice, Type, ppQuery);
}
