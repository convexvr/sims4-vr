typedef HRESULT(APIENTRY* IDirect3DDevice9_QueryInterface)(IDirect3DDevice9*, REFIID, void**);
IDirect3DDevice9_QueryInterface IDirect3DDevice9_QueryInterface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_QueryInterface_hook(IDirect3DDevice9* pDevice, REFIID riid, void** ppvObj){
   vireio::debugf("IDirect3DDevice9_QueryInterface_hook: pDevice: %i, riid: %i, ppvObj: %i", pDevice, riid, ppvObj);
   return IDirect3DDevice9_QueryInterface_orig(pDevice, riid, ppvObj);
}
typedef ULONG(APIENTRY* IDirect3DDevice9_AddRef)(IDirect3DDevice9*);
IDirect3DDevice9_AddRef IDirect3DDevice9_AddRef_orig = 0;
ULONG APIENTRY IDirect3DDevice9_AddRef_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_AddRef_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_AddRef_orig(pDevice);
}
typedef ULONG(APIENTRY* IDirect3DDevice9_Release)(IDirect3DDevice9*);
IDirect3DDevice9_Release IDirect3DDevice9_Release_orig = 0;
ULONG APIENTRY IDirect3DDevice9_Release_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_Release_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_Release_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_TestCooperativeLevel)(IDirect3DDevice9*);
IDirect3DDevice9_TestCooperativeLevel IDirect3DDevice9_TestCooperativeLevel_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_TestCooperativeLevel_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_TestCooperativeLevel_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_TestCooperativeLevel_orig(pDevice);
}
typedef UINT(APIENTRY* IDirect3DDevice9_GetAvailableTextureMem)(IDirect3DDevice9*);
IDirect3DDevice9_GetAvailableTextureMem IDirect3DDevice9_GetAvailableTextureMem_orig = 0;
UINT APIENTRY IDirect3DDevice9_GetAvailableTextureMem_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_GetAvailableTextureMem_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_GetAvailableTextureMem_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_EvictManagedResources)(IDirect3DDevice9*);
IDirect3DDevice9_EvictManagedResources IDirect3DDevice9_EvictManagedResources_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_EvictManagedResources_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_EvictManagedResources_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_EvictManagedResources_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetDirect3D)(IDirect3DDevice9*, IDirect3D9**);
IDirect3DDevice9_GetDirect3D IDirect3DDevice9_GetDirect3D_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetDirect3D_hook(IDirect3DDevice9* pDevice, IDirect3D9** ppD3D9){
   vireio::debugf("IDirect3DDevice9_GetDirect3D_hook: pDevice: %i, ppD3D9: %i", pDevice, ppD3D9);
   return IDirect3DDevice9_GetDirect3D_orig(pDevice, ppD3D9);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetDeviceCaps)(IDirect3DDevice9*, D3DCAPS9*);
IDirect3DDevice9_GetDeviceCaps IDirect3DDevice9_GetDeviceCaps_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetDeviceCaps_hook(IDirect3DDevice9* pDevice, D3DCAPS9* pCaps){
   vireio::debugf("IDirect3DDevice9_GetDeviceCaps_hook: pDevice: %i, pCaps->DeviceType: %i, pCaps->AdapterOrdinal: %i, pCaps->Caps: %i, pCaps->Caps2: %i, pCaps->Caps3: %i, pCaps->PresentationIntervals: %i, pCaps->CursorCaps: %i, pCaps->DevCaps: %i, pCaps->PrimitiveMiscCaps: %i, pCaps->RasterCaps: %i, pCaps->ZCmpCaps: %i, pCaps->SrcBlendCaps: %i, pCaps->DestBlendCaps: %i, pCaps->AlphaCmpCaps: %i, pCaps->ShadeCaps: %i, pCaps->TextureCaps: %i, pCaps->TextureFilterCaps: %i, pCaps->CubeTextureFilterCaps: %i, pCaps->VolumeTextureFilterCaps: %i, pCaps->TextureAddressCaps: %i, pCaps->VolumeTextureAddressCaps: %i, pCaps->LineCaps: %i, pCaps->MaxTextureHeight: %i, pCaps->MaxVolumeExtent: %i, pCaps->MaxTextureRepeat: %i, pCaps->MaxTextureAspectRatio: %i, pCaps->MaxAnisotropy: %i, pCaps->MaxVertexW: %i, pCaps->GuardBandLeft: %i, pCaps->GuardBandTop: %i, pCaps->GuardBandRight: %i, pCaps->GuardBandBottom: %i, pCaps->ExtentsAdjust: %i, pCaps->StencilCaps: %i, pCaps->FVFCaps: %i, pCaps->TextureOpCaps: %i, pCaps->MaxTextureBlendStages: %i, pCaps->MaxSimultaneousTextures: %i, pCaps->VertexProcessingCaps: %i, pCaps->MaxActiveLights: %i, pCaps->MaxUserClipPlanes: %i, pCaps->MaxVertexBlendMatrices: %i, pCaps->MaxVertexBlendMatrixIndex: %i, pCaps->MaxPointSize: %i, pCaps->MaxPrimitiveCount: %i, pCaps->MaxVertexIndex: %i, pCaps->MaxStreams: %i, pCaps->MaxStreamStride: %i, pCaps->VertexShaderVersion: %i, pCaps->MaxVertexShaderConst: %i, pCaps->PixelShaderVersion: %i, pCaps->PixelShader1xMaxValue: %i, pCaps->DevCaps2: %i, pCaps->MaxNpatchTessellationLevel: %i, pCaps->Reserved5: %i, pCaps->MasterAdapterOrdinal: %i, pCaps->AdapterOrdinalInGroup: %i, pCaps->NumberOfAdaptersInGroup: %i, pCaps->DeclTypes: %i, pCaps->NumSimultaneousRTs: %i, pCaps->StretchRectFilterCaps: %i, pCaps->VS20Caps: %i, pCaps->PS20Caps: %i, pCaps->VertexTextureFilterCaps: %i, pCaps->MaxVShaderInstructionsExecuted: %i, pCaps->MaxPShaderInstructionsExecuted: %i, pCaps->MaxVertexShader30InstructionSlots: %i, pCaps->MaxPixelShader30InstructionSlots: %i", pDevice, pCaps);
   return IDirect3DDevice9_GetDeviceCaps_orig(pDevice, pCaps);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetDisplayMode)(IDirect3DDevice9*, UINT, D3DDISPLAYMODE*);
IDirect3DDevice9_GetDisplayMode IDirect3DDevice9_GetDisplayMode_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetDisplayMode_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, D3DDISPLAYMODE* pMode){
   vireio::debugf("IDirect3DDevice9_GetDisplayMode_hook: pDevice: %i, iSwapChain: %i, pMode->Width: %i, pMode->Height: %i, pMode->RefreshRate: %i, pMode->Format: %i", pDevice, iSwapChain, pMode);
   return IDirect3DDevice9_GetDisplayMode_orig(pDevice, iSwapChain, pMode);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetCreationParameters)(IDirect3DDevice9*, D3DDEVICE_CREATION_PARAMETERS*);
IDirect3DDevice9_GetCreationParameters IDirect3DDevice9_GetCreationParameters_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetCreationParameters_hook(IDirect3DDevice9* pDevice, D3DDEVICE_CREATION_PARAMETERS* pParameters){
   vireio::debugf("IDirect3DDevice9_GetCreationParameters_hook: pDevice: %i, pParameters->AdapterOrdinal: %i, pParameters->DeviceType: %i, pParameters->hFocusWindow: %i, pParameters->BehaviorFlags: %i", pDevice, pParameters);
   return IDirect3DDevice9_GetCreationParameters_orig(pDevice, pParameters);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetCursorProperties)(IDirect3DDevice9*, UINT, UINT, IDirect3DSurface9*);
IDirect3DDevice9_SetCursorProperties IDirect3DDevice9_SetCursorProperties_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetCursorProperties_hook(IDirect3DDevice9* pDevice, UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap){
   vireio::debugf("IDirect3DDevice9_SetCursorProperties_hook: pDevice: %i, XHotSpot: %i, YHotSpot: %i, pCursorBitmap: %i", pDevice, XHotSpot, YHotSpot, pCursorBitmap);
   return IDirect3DDevice9_SetCursorProperties_orig(pDevice, XHotSpot, YHotSpot, pCursorBitmap);
}
typedef void(APIENTRY* IDirect3DDevice9_SetCursorPosition)(IDirect3DDevice9*, int, int, DWORD);
IDirect3DDevice9_SetCursorPosition IDirect3DDevice9_SetCursorPosition_orig = 0;
void APIENTRY IDirect3DDevice9_SetCursorPosition_hook(IDirect3DDevice9* pDevice, int X, int Y, DWORD Flags){
   vireio::debugf("IDirect3DDevice9_SetCursorPosition_hook: pDevice: %i, X: %i, Y: %i, Flags: %i", pDevice, X, Y, Flags);
   return IDirect3DDevice9_SetCursorPosition_orig(pDevice, X, Y, Flags);
}
typedef BOOL(APIENTRY* IDirect3DDevice9_ShowCursor)(IDirect3DDevice9*, BOOL);
IDirect3DDevice9_ShowCursor IDirect3DDevice9_ShowCursor_orig = 0;
BOOL APIENTRY IDirect3DDevice9_ShowCursor_hook(IDirect3DDevice9* pDevice, BOOL bShow){
   vireio::debugf("IDirect3DDevice9_ShowCursor_hook: pDevice: %i, bShow: %i", pDevice, bShow);
   return IDirect3DDevice9_ShowCursor_orig(pDevice, bShow);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateAdditionalSwapChain)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*, IDirect3DSwapChain9**);
IDirect3DDevice9_CreateAdditionalSwapChain IDirect3DDevice9_CreateAdditionalSwapChain_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateAdditionalSwapChain_hook(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain){
   vireio::debugf("IDirect3DDevice9_CreateAdditionalSwapChain_hook: pDevice: %i, pPresentationParameters->BackBufferWidth: %i, pPresentationParameters->BackBufferHeight: %i, pPresentationParameters->BackBufferFormat: %i, pPresentationParameters->BackBufferCount: %i, pPresentationParameters->MultiSampleType: %i, pPresentationParameters->MultiSampleQuality: %i, pPresentationParameters->SwapEffect: %i, pPresentationParameters->hDeviceWindow: %i, pPresentationParameters->Windowed: %i, pPresentationParameters->EnableAutoDepthStencil: %i, pPresentationParameters->AutoDepthStencilFormat: %i, pPresentationParameters->Flags: %i, pPresentationParameters->FullScreen_RefreshRateInHz: %i, pPresentationParameters->PresentationInterval: %i, pSwapChain: %i", pDevice, pPresentationParameters, pSwapChain);
   return IDirect3DDevice9_CreateAdditionalSwapChain_orig(pDevice, pPresentationParameters, pSwapChain);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetSwapChain)(IDirect3DDevice9*, UINT, IDirect3DSwapChain9**);
IDirect3DDevice9_GetSwapChain IDirect3DDevice9_GetSwapChain_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetSwapChain_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, IDirect3DSwapChain9** pSwapChain){
   vireio::debugf("IDirect3DDevice9_GetSwapChain_hook: pDevice: %i, iSwapChain: %i, pSwapChain: %i", pDevice, iSwapChain, pSwapChain);
   return IDirect3DDevice9_GetSwapChain_orig(pDevice, iSwapChain, pSwapChain);
}
typedef UINT(APIENTRY* IDirect3DDevice9_GetNumberOfSwapChains)(IDirect3DDevice9*);
IDirect3DDevice9_GetNumberOfSwapChains IDirect3DDevice9_GetNumberOfSwapChains_orig = 0;
UINT APIENTRY IDirect3DDevice9_GetNumberOfSwapChains_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_GetNumberOfSwapChains_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_GetNumberOfSwapChains_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_Reset)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
IDirect3DDevice9_Reset IDirect3DDevice9_Reset_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_Reset_hook(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters){
   vireio::debugf("IDirect3DDevice9_Reset_hook: pDevice: %i, pPresentationParameters->BackBufferWidth: %i, pPresentationParameters->BackBufferHeight: %i, pPresentationParameters->BackBufferFormat: %i, pPresentationParameters->BackBufferCount: %i, pPresentationParameters->MultiSampleType: %i, pPresentationParameters->MultiSampleQuality: %i, pPresentationParameters->SwapEffect: %i, pPresentationParameters->hDeviceWindow: %i, pPresentationParameters->Windowed: %i, pPresentationParameters->EnableAutoDepthStencil: %i, pPresentationParameters->AutoDepthStencilFormat: %i, pPresentationParameters->Flags: %i, pPresentationParameters->FullScreen_RefreshRateInHz: %i, pPresentationParameters->PresentationInterval: %i", pDevice, pPresentationParameters);
   return IDirect3DDevice9_Reset_orig(pDevice, pPresentationParameters);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_Present)(IDirect3DDevice9*, CONST RECT*, CONST RECT*, HWND, CONST RGNDATA*);
IDirect3DDevice9_Present IDirect3DDevice9_Present_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_Present_hook(IDirect3DDevice9* pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion){
   vireio::debugf("IDirect3DDevice9_Present_hook: pDevice: %i, pSourceRect: %i, pDestRect: %i, hDestWindowOverride: %i, pDirtyRegion: %i", pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
   return IDirect3DDevice9_Present_orig(pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetBackBuffer)(IDirect3DDevice9*, UINT, UINT, D3DBACKBUFFER_TYPE, IDirect3DSurface9**);
IDirect3DDevice9_GetBackBuffer IDirect3DDevice9_GetBackBuffer_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetBackBuffer_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer){
   vireio::debugf("IDirect3DDevice9_GetBackBuffer_hook: pDevice: %i, iSwapChain: %i, iBackBuffer: %i, Type: %i, ppBackBuffer: %i", pDevice, iSwapChain, iBackBuffer, Type, ppBackBuffer);
   return IDirect3DDevice9_GetBackBuffer_orig(pDevice, iSwapChain, iBackBuffer, Type, ppBackBuffer);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetRasterStatus)(IDirect3DDevice9*, UINT, D3DRASTER_STATUS*);
IDirect3DDevice9_GetRasterStatus IDirect3DDevice9_GetRasterStatus_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetRasterStatus_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus){
   vireio::debugf("IDirect3DDevice9_GetRasterStatus_hook: pDevice: %i, iSwapChain: %i, pRasterStatus->InVBlank: %i, pRasterStatus->ScanLine: %i", pDevice, iSwapChain, pRasterStatus);
   return IDirect3DDevice9_GetRasterStatus_orig(pDevice, iSwapChain, pRasterStatus);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetDialogBoxMode)(IDirect3DDevice9*, BOOL);
IDirect3DDevice9_SetDialogBoxMode IDirect3DDevice9_SetDialogBoxMode_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetDialogBoxMode_hook(IDirect3DDevice9* pDevice, BOOL bEnableDialogs){
   vireio::debugf("IDirect3DDevice9_SetDialogBoxMode_hook: pDevice: %i, bEnableDialogs: %i", pDevice, bEnableDialogs);
   return IDirect3DDevice9_SetDialogBoxMode_orig(pDevice, bEnableDialogs);
}
typedef void(APIENTRY* IDirect3DDevice9_SetGammaRamp)(IDirect3DDevice9*, UINT, DWORD, CONST D3DGAMMARAMP*);
IDirect3DDevice9_SetGammaRamp IDirect3DDevice9_SetGammaRamp_orig = 0;
void APIENTRY IDirect3DDevice9_SetGammaRamp_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp){
   vireio::debugf("IDirect3DDevice9_SetGammaRamp_hook: pDevice: %i, iSwapChain: %i, Flags: %i, pRamp: %i", pDevice, iSwapChain, Flags, pRamp);
   return IDirect3DDevice9_SetGammaRamp_orig(pDevice, iSwapChain, Flags, pRamp);
}
typedef void(APIENTRY* IDirect3DDevice9_GetGammaRamp)(IDirect3DDevice9*, UINT, D3DGAMMARAMP*);
IDirect3DDevice9_GetGammaRamp IDirect3DDevice9_GetGammaRamp_orig = 0;
void APIENTRY IDirect3DDevice9_GetGammaRamp_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, D3DGAMMARAMP* pRamp){
   vireio::debugf("IDirect3DDevice9_GetGammaRamp_hook: pDevice: %i, iSwapChain: %i, pRamp->red[256]: %i, pRamp->green[256]: %i, pRamp->blue[256]: %i", pDevice, iSwapChain, pRamp);
   return IDirect3DDevice9_GetGammaRamp_orig(pDevice, iSwapChain, pRamp);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateTexture)(IDirect3DDevice9*, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DTexture9**, HANDLE*);
IDirect3DDevice9_CreateTexture IDirect3DDevice9_CreateTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateTexture_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateTexture_hook: pDevice: %i, Width: %i, Height: %i, Levels: %i, Usage: %i, Format: %i, Pool: %i, ppTexture: %i, pSharedHandle: %i", pDevice, Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
   return IDirect3DDevice9_CreateTexture_orig(pDevice, Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateVolumeTexture)(IDirect3DDevice9*, UINT, UINT, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DVolumeTexture9**, HANDLE*);
IDirect3DDevice9_CreateVolumeTexture IDirect3DDevice9_CreateVolumeTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateVolumeTexture_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateVolumeTexture_hook: pDevice: %i, Width: %i, Height: %i, Depth: %i, Levels: %i, Usage: %i, Format: %i, Pool: %i, ppVolumeTexture: %i, pSharedHandle: %i", pDevice, Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
   return IDirect3DDevice9_CreateVolumeTexture_orig(pDevice, Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateCubeTexture)(IDirect3DDevice9*, UINT, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DCubeTexture9**, HANDLE*);
IDirect3DDevice9_CreateCubeTexture IDirect3DDevice9_CreateCubeTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateCubeTexture_hook(IDirect3DDevice9* pDevice, UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateCubeTexture_hook: pDevice: %i, EdgeLength: %i, Levels: %i, Usage: %i, Format: %i, Pool: %i, ppCubeTexture: %i, pSharedHandle: %i", pDevice, EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
   return IDirect3DDevice9_CreateCubeTexture_orig(pDevice, EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateVertexBuffer)(IDirect3DDevice9*, UINT, DWORD, DWORD, D3DPOOL, IDirect3DVertexBuffer9**, HANDLE*);
IDirect3DDevice9_CreateVertexBuffer IDirect3DDevice9_CreateVertexBuffer_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateVertexBuffer_hook(IDirect3DDevice9* pDevice, UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateVertexBuffer_hook: pDevice: %i, Length: %i, Usage: %i, FVF: %i, Pool: %i, ppVertexBuffer: %i, pSharedHandle: %i", pDevice, Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
   return IDirect3DDevice9_CreateVertexBuffer_orig(pDevice, Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateIndexBuffer)(IDirect3DDevice9*, UINT, DWORD, D3DFORMAT, D3DPOOL, IDirect3DIndexBuffer9**, HANDLE*);
IDirect3DDevice9_CreateIndexBuffer IDirect3DDevice9_CreateIndexBuffer_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateIndexBuffer_hook(IDirect3DDevice9* pDevice, UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateIndexBuffer_hook: pDevice: %i, Length: %i, Usage: %i, Format: %i, Pool: %i, ppIndexBuffer: %i, pSharedHandle: %i", pDevice, Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
   return IDirect3DDevice9_CreateIndexBuffer_orig(pDevice, Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateRenderTarget)(IDirect3DDevice9*, UINT, UINT, D3DFORMAT, D3DMULTISAMPLE_TYPE, DWORD, BOOL, IDirect3DSurface9**, HANDLE*);
IDirect3DDevice9_CreateRenderTarget IDirect3DDevice9_CreateRenderTarget_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateRenderTarget_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateRenderTarget_hook: pDevice: %i, Width: %i, Height: %i, Format: %i, MultiSample: %i, MultisampleQuality: %i, Lockable: %i, ppSurface: %i, pSharedHandle: %i", pDevice, Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
   return IDirect3DDevice9_CreateRenderTarget_orig(pDevice, Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateDepthStencilSurface)(IDirect3DDevice9*, UINT, UINT, D3DFORMAT, D3DMULTISAMPLE_TYPE, DWORD, BOOL, IDirect3DSurface9**, HANDLE*);
IDirect3DDevice9_CreateDepthStencilSurface IDirect3DDevice9_CreateDepthStencilSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateDepthStencilSurface_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateDepthStencilSurface_hook: pDevice: %i, Width: %i, Height: %i, Format: %i, MultiSample: %i, MultisampleQuality: %i, Discard: %i, ppSurface: %i, pSharedHandle: %i", pDevice, Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
   return IDirect3DDevice9_CreateDepthStencilSurface_orig(pDevice, Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_UpdateSurface)(IDirect3DDevice9*, IDirect3DSurface9*, CONST RECT*, IDirect3DSurface9*, CONST POINT*);
IDirect3DDevice9_UpdateSurface IDirect3DDevice9_UpdateSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_UpdateSurface_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint){
   vireio::debugf("IDirect3DDevice9_UpdateSurface_hook: pDevice: %i, pSourceSurface: %i, pSourceRect: %i, pDestinationSurface: %i, pDestPoint: %i", pDevice, pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
   return IDirect3DDevice9_UpdateSurface_orig(pDevice, pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_UpdateTexture)(IDirect3DDevice9*, IDirect3DBaseTexture9*, IDirect3DBaseTexture9*);
IDirect3DDevice9_UpdateTexture IDirect3DDevice9_UpdateTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_UpdateTexture_hook(IDirect3DDevice9* pDevice, IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture){
   vireio::debugf("IDirect3DDevice9_UpdateTexture_hook: pDevice: %i, pSourceTexture: %i, pDestinationTexture: %i", pDevice, pSourceTexture, pDestinationTexture);
   return IDirect3DDevice9_UpdateTexture_orig(pDevice, pSourceTexture, pDestinationTexture);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetRenderTargetData)(IDirect3DDevice9*, IDirect3DSurface9*, IDirect3DSurface9*);
IDirect3DDevice9_GetRenderTargetData IDirect3DDevice9_GetRenderTargetData_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetRenderTargetData_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface){
   vireio::debugf("IDirect3DDevice9_GetRenderTargetData_hook: pDevice: %i, pRenderTarget: %i, pDestSurface: %i", pDevice, pRenderTarget, pDestSurface);
   return IDirect3DDevice9_GetRenderTargetData_orig(pDevice, pRenderTarget, pDestSurface);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetFrontBufferData)(IDirect3DDevice9*, UINT, IDirect3DSurface9*);
IDirect3DDevice9_GetFrontBufferData IDirect3DDevice9_GetFrontBufferData_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetFrontBufferData_hook(IDirect3DDevice9* pDevice, UINT iSwapChain, IDirect3DSurface9* pDestSurface){
   vireio::debugf("IDirect3DDevice9_GetFrontBufferData_hook: pDevice: %i, iSwapChain: %i, pDestSurface: %i", pDevice, iSwapChain, pDestSurface);
   return IDirect3DDevice9_GetFrontBufferData_orig(pDevice, iSwapChain, pDestSurface);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_StretchRect)(IDirect3DDevice9*, IDirect3DSurface9*, CONST RECT*, IDirect3DSurface9*, CONST RECT*, D3DTEXTUREFILTERTYPE);
IDirect3DDevice9_StretchRect IDirect3DDevice9_StretchRect_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_StretchRect_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter){
   vireio::debugf("IDirect3DDevice9_StretchRect_hook: pDevice: %i, pSourceSurface: %i, pSourceRect: %i, pDestSurface: %i, pDestRect: %i, Filter: %i", pDevice, pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
   return IDirect3DDevice9_StretchRect_orig(pDevice, pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_ColorFill)(IDirect3DDevice9*, IDirect3DSurface9*, CONST RECT*, D3DCOLOR);
IDirect3DDevice9_ColorFill IDirect3DDevice9_ColorFill_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_ColorFill_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color){
   vireio::debugf("IDirect3DDevice9_ColorFill_hook: pDevice: %i, pSurface: %i, pRect: %i, color: %i", pDevice, pSurface, pRect, color);
   return IDirect3DDevice9_ColorFill_orig(pDevice, pSurface, pRect, color);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateOffscreenPlainSurface)(IDirect3DDevice9*, UINT, UINT, D3DFORMAT, D3DPOOL, IDirect3DSurface9**, HANDLE*);
IDirect3DDevice9_CreateOffscreenPlainSurface IDirect3DDevice9_CreateOffscreenPlainSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateOffscreenPlainSurface_hook(IDirect3DDevice9* pDevice, UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle){
   vireio::debugf("IDirect3DDevice9_CreateOffscreenPlainSurface_hook: pDevice: %i, Width: %i, Height: %i, Format: %i, Pool: %i, ppSurface: %i, pSharedHandle: %i", pDevice, Width, Height, Format, Pool, ppSurface, pSharedHandle);
   return IDirect3DDevice9_CreateOffscreenPlainSurface_orig(pDevice, Width, Height, Format, Pool, ppSurface, pSharedHandle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetRenderTarget)(IDirect3DDevice9*, DWORD, IDirect3DSurface9*);
IDirect3DDevice9_SetRenderTarget IDirect3DDevice9_SetRenderTarget_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetRenderTarget_hook(IDirect3DDevice9* pDevice, DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget){
   vireio::debugf("IDirect3DDevice9_SetRenderTarget_hook: pDevice: %i, RenderTargetIndex: %i, pRenderTarget: %i", pDevice, RenderTargetIndex, pRenderTarget);
   return IDirect3DDevice9_SetRenderTarget_orig(pDevice, RenderTargetIndex, pRenderTarget);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetRenderTarget)(IDirect3DDevice9*, DWORD, IDirect3DSurface9**);
IDirect3DDevice9_GetRenderTarget IDirect3DDevice9_GetRenderTarget_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetRenderTarget_hook(IDirect3DDevice9* pDevice, DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget){
   vireio::debugf("IDirect3DDevice9_GetRenderTarget_hook: pDevice: %i, RenderTargetIndex: %i, ppRenderTarget: %i", pDevice, RenderTargetIndex, ppRenderTarget);
   return IDirect3DDevice9_GetRenderTarget_orig(pDevice, RenderTargetIndex, ppRenderTarget);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetDepthStencilSurface)(IDirect3DDevice9*, IDirect3DSurface9*);
IDirect3DDevice9_SetDepthStencilSurface IDirect3DDevice9_SetDepthStencilSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetDepthStencilSurface_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9* pNewZStencil){
   vireio::debugf("IDirect3DDevice9_SetDepthStencilSurface_hook: pDevice: %i, pNewZStencil: %i", pDevice, pNewZStencil);
   return IDirect3DDevice9_SetDepthStencilSurface_orig(pDevice, pNewZStencil);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetDepthStencilSurface)(IDirect3DDevice9*, IDirect3DSurface9**);
IDirect3DDevice9_GetDepthStencilSurface IDirect3DDevice9_GetDepthStencilSurface_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetDepthStencilSurface_hook(IDirect3DDevice9* pDevice, IDirect3DSurface9** ppZStencilSurface){
   vireio::debugf("IDirect3DDevice9_GetDepthStencilSurface_hook: pDevice: %i, ppZStencilSurface: %i", pDevice, ppZStencilSurface);
   return IDirect3DDevice9_GetDepthStencilSurface_orig(pDevice, ppZStencilSurface);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_BeginScene)(IDirect3DDevice9*);
IDirect3DDevice9_BeginScene IDirect3DDevice9_BeginScene_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_BeginScene_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_BeginScene_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_BeginScene_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_EndScene)(IDirect3DDevice9*);
IDirect3DDevice9_EndScene IDirect3DDevice9_EndScene_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_EndScene_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_EndScene_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_EndScene_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_Clear)(IDirect3DDevice9*, DWORD, CONST D3DRECT*, DWORD, D3DCOLOR, float, DWORD);
IDirect3DDevice9_Clear IDirect3DDevice9_Clear_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_Clear_hook(IDirect3DDevice9* pDevice, DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil){
   vireio::debugf("IDirect3DDevice9_Clear_hook: pDevice: %i, Count: %i, pRects: %i, Flags: %i, Color: %i, Z: %i, Stencil: %i", pDevice, Count, pRects, Flags, Color, Z, Stencil);
   return IDirect3DDevice9_Clear_orig(pDevice, Count, pRects, Flags, Color, Z, Stencil);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetTransform)(IDirect3DDevice9*, D3DTRANSFORMSTATETYPE, CONST D3DMATRIX*);
IDirect3DDevice9_SetTransform IDirect3DDevice9_SetTransform_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetTransform_hook(IDirect3DDevice9* pDevice, D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix){
   vireio::debugf("IDirect3DDevice9_SetTransform_hook: pDevice: %i, State: %i, pMatrix: %i", pDevice, State, pMatrix);
   return IDirect3DDevice9_SetTransform_orig(pDevice, State, pMatrix);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetTransform)(IDirect3DDevice9*, D3DTRANSFORMSTATETYPE, D3DMATRIX*);
IDirect3DDevice9_GetTransform IDirect3DDevice9_GetTransform_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetTransform_hook(IDirect3DDevice9* pDevice, D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix){
   vireio::debugf("IDirect3DDevice9_GetTransform_hook: pDevice: %i, State: %i, pMatrix: %i", pDevice, State, pMatrix);
   return IDirect3DDevice9_GetTransform_orig(pDevice, State, pMatrix);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_MultiplyTransform)(IDirect3DDevice9*, D3DTRANSFORMSTATETYPE, CONST D3DMATRIX*);
IDirect3DDevice9_MultiplyTransform IDirect3DDevice9_MultiplyTransform_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_MultiplyTransform_hook(IDirect3DDevice9* pDevice, D3DTRANSFORMSTATETYPE arg1, CONST D3DMATRIX* arg2){
   vireio::debugf("IDirect3DDevice9_MultiplyTransform_hook: pDevice: %i, arg1: %i, arg2: %i", pDevice, arg1, arg2);
   return IDirect3DDevice9_MultiplyTransform_orig(pDevice, arg1, arg2);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetViewport)(IDirect3DDevice9*, CONST D3DVIEWPORT9*);
IDirect3DDevice9_SetViewport IDirect3DDevice9_SetViewport_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetViewport_hook(IDirect3DDevice9* pDevice, CONST D3DVIEWPORT9* pViewport){
   vireio::debugf("IDirect3DDevice9_SetViewport_hook: pDevice: %i, pViewport: %i", pDevice, pViewport);
   return IDirect3DDevice9_SetViewport_orig(pDevice, pViewport);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetViewport)(IDirect3DDevice9*, D3DVIEWPORT9*);
IDirect3DDevice9_GetViewport IDirect3DDevice9_GetViewport_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetViewport_hook(IDirect3DDevice9* pDevice, D3DVIEWPORT9* pViewport){
   vireio::debugf("IDirect3DDevice9_GetViewport_hook: pDevice: %i, pViewport->X: %i, pViewport->Y: %i, pViewport->Width: %i, pViewport->Height: %i, pViewport->MinZ: %i, pViewport->MaxZ: %i", pDevice, pViewport);
   return IDirect3DDevice9_GetViewport_orig(pDevice, pViewport);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetMaterial)(IDirect3DDevice9*, CONST D3DMATERIAL9*);
IDirect3DDevice9_SetMaterial IDirect3DDevice9_SetMaterial_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetMaterial_hook(IDirect3DDevice9* pDevice, CONST D3DMATERIAL9* pMaterial){
   vireio::debugf("IDirect3DDevice9_SetMaterial_hook: pDevice: %i, pMaterial: %i", pDevice, pMaterial);
   return IDirect3DDevice9_SetMaterial_orig(pDevice, pMaterial);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetMaterial)(IDirect3DDevice9*, D3DMATERIAL9*);
IDirect3DDevice9_GetMaterial IDirect3DDevice9_GetMaterial_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetMaterial_hook(IDirect3DDevice9* pDevice, D3DMATERIAL9* pMaterial){
   vireio::debugf("IDirect3DDevice9_GetMaterial_hook: pDevice: %i, pMaterial->Diffuse: %i, pMaterial->Ambient: %i, pMaterial->Specular: %i, pMaterial->Emissive: %i, pMaterial->Power: %i", pDevice, pMaterial);
   return IDirect3DDevice9_GetMaterial_orig(pDevice, pMaterial);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetLight)(IDirect3DDevice9*, DWORD, CONST D3DLIGHT9*);
IDirect3DDevice9_SetLight IDirect3DDevice9_SetLight_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetLight_hook(IDirect3DDevice9* pDevice, DWORD Index, CONST D3DLIGHT9* arg2){
   vireio::debugf("IDirect3DDevice9_SetLight_hook: pDevice: %i, Index: %i, arg2: %i", pDevice, Index, arg2);
   return IDirect3DDevice9_SetLight_orig(pDevice, Index, arg2);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetLight)(IDirect3DDevice9*, DWORD, D3DLIGHT9*);
IDirect3DDevice9_GetLight IDirect3DDevice9_GetLight_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetLight_hook(IDirect3DDevice9* pDevice, DWORD Index, D3DLIGHT9* arg2){
   vireio::debugf("IDirect3DDevice9_GetLight_hook: pDevice: %i, Index: %i, arg2->Type: %i, arg2->Diffuse: %i, arg2->Specular: %i, arg2->Ambient: %i, arg2->Position: %i, arg2->Direction: %i, arg2->Range: %i, arg2->Falloff: %i, arg2->Attenuation0: %i, arg2->Attenuation1: %i, arg2->Attenuation2: %i, arg2->Theta: %i, arg2->Phi: %i", pDevice, Index, arg2);
   return IDirect3DDevice9_GetLight_orig(pDevice, Index, arg2);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_LightEnable)(IDirect3DDevice9*, DWORD, BOOL);
IDirect3DDevice9_LightEnable IDirect3DDevice9_LightEnable_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_LightEnable_hook(IDirect3DDevice9* pDevice, DWORD Index, BOOL Enable){
   vireio::debugf("IDirect3DDevice9_LightEnable_hook: pDevice: %i, Index: %i, Enable: %i", pDevice, Index, Enable);
   return IDirect3DDevice9_LightEnable_orig(pDevice, Index, Enable);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetLightEnable)(IDirect3DDevice9*, DWORD, BOOL*);
IDirect3DDevice9_GetLightEnable IDirect3DDevice9_GetLightEnable_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetLightEnable_hook(IDirect3DDevice9* pDevice, DWORD Index, BOOL* pEnable){
   vireio::debugf("IDirect3DDevice9_GetLightEnable_hook: pDevice: %i, Index: %i, pEnable: %i", pDevice, Index, pEnable);
   return IDirect3DDevice9_GetLightEnable_orig(pDevice, Index, pEnable);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetClipPlane)(IDirect3DDevice9*, DWORD, CONST float*);
IDirect3DDevice9_SetClipPlane IDirect3DDevice9_SetClipPlane_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetClipPlane_hook(IDirect3DDevice9* pDevice, DWORD Index, CONST float* pPlane){
   vireio::debugf("IDirect3DDevice9_SetClipPlane_hook: pDevice: %i, Index: %i, pPlane: %i", pDevice, Index, pPlane);
   return IDirect3DDevice9_SetClipPlane_orig(pDevice, Index, pPlane);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetClipPlane)(IDirect3DDevice9*, DWORD, float*);
IDirect3DDevice9_GetClipPlane IDirect3DDevice9_GetClipPlane_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetClipPlane_hook(IDirect3DDevice9* pDevice, DWORD Index, float* pPlane){
   vireio::debugf("IDirect3DDevice9_GetClipPlane_hook: pDevice: %i, Index: %i, pPlane: %i", pDevice, Index, pPlane);
   return IDirect3DDevice9_GetClipPlane_orig(pDevice, Index, pPlane);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetRenderState)(IDirect3DDevice9*, D3DRENDERSTATETYPE, DWORD);
IDirect3DDevice9_SetRenderState IDirect3DDevice9_SetRenderState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetRenderState_hook(IDirect3DDevice9* pDevice, D3DRENDERSTATETYPE State, DWORD Value){
   vireio::debugf("IDirect3DDevice9_SetRenderState_hook: pDevice: %i, State: %i, Value: %i", pDevice, State, Value);
   return IDirect3DDevice9_SetRenderState_orig(pDevice, State, Value);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetRenderState)(IDirect3DDevice9*, D3DRENDERSTATETYPE, DWORD*);
IDirect3DDevice9_GetRenderState IDirect3DDevice9_GetRenderState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetRenderState_hook(IDirect3DDevice9* pDevice, D3DRENDERSTATETYPE State, DWORD* pValue){
   vireio::debugf("IDirect3DDevice9_GetRenderState_hook: pDevice: %i, State: %i, pValue: %i", pDevice, State, pValue);
   return IDirect3DDevice9_GetRenderState_orig(pDevice, State, pValue);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateStateBlock)(IDirect3DDevice9*, D3DSTATEBLOCKTYPE, IDirect3DStateBlock9**);
IDirect3DDevice9_CreateStateBlock IDirect3DDevice9_CreateStateBlock_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateStateBlock_hook(IDirect3DDevice9* pDevice, D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB){
   vireio::debugf("IDirect3DDevice9_CreateStateBlock_hook: pDevice: %i, Type: %i, ppSB: %i", pDevice, Type, ppSB);
   return IDirect3DDevice9_CreateStateBlock_orig(pDevice, Type, ppSB);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_BeginStateBlock)(IDirect3DDevice9*);
IDirect3DDevice9_BeginStateBlock IDirect3DDevice9_BeginStateBlock_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_BeginStateBlock_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_BeginStateBlock_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_BeginStateBlock_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_EndStateBlock)(IDirect3DDevice9*, IDirect3DStateBlock9**);
IDirect3DDevice9_EndStateBlock IDirect3DDevice9_EndStateBlock_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_EndStateBlock_hook(IDirect3DDevice9* pDevice, IDirect3DStateBlock9** ppSB){
   vireio::debugf("IDirect3DDevice9_EndStateBlock_hook: pDevice: %i, ppSB: %i", pDevice, ppSB);
   return IDirect3DDevice9_EndStateBlock_orig(pDevice, ppSB);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetClipStatus)(IDirect3DDevice9*, CONST D3DCLIPSTATUS9*);
IDirect3DDevice9_SetClipStatus IDirect3DDevice9_SetClipStatus_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetClipStatus_hook(IDirect3DDevice9* pDevice, CONST D3DCLIPSTATUS9* pClipStatus){
   vireio::debugf("IDirect3DDevice9_SetClipStatus_hook: pDevice: %i, pClipStatus: %i", pDevice, pClipStatus);
   return IDirect3DDevice9_SetClipStatus_orig(pDevice, pClipStatus);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetClipStatus)(IDirect3DDevice9*, D3DCLIPSTATUS9*);
IDirect3DDevice9_GetClipStatus IDirect3DDevice9_GetClipStatus_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetClipStatus_hook(IDirect3DDevice9* pDevice, D3DCLIPSTATUS9* pClipStatus){
   vireio::debugf("IDirect3DDevice9_GetClipStatus_hook: pDevice: %i, pClipStatus->ClipUnion: %i, pClipStatus->ClipIntersection: %i", pDevice, pClipStatus);
   return IDirect3DDevice9_GetClipStatus_orig(pDevice, pClipStatus);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetTexture)(IDirect3DDevice9*, DWORD, IDirect3DBaseTexture9**);
IDirect3DDevice9_GetTexture IDirect3DDevice9_GetTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetTexture_hook(IDirect3DDevice9* pDevice, DWORD Stage, IDirect3DBaseTexture9** ppTexture){
   vireio::debugf("IDirect3DDevice9_GetTexture_hook: pDevice: %i, Stage: %i, ppTexture: %i", pDevice, Stage, ppTexture);
   return IDirect3DDevice9_GetTexture_orig(pDevice, Stage, ppTexture);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetTexture)(IDirect3DDevice9*, DWORD, IDirect3DBaseTexture9*);
IDirect3DDevice9_SetTexture IDirect3DDevice9_SetTexture_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetTexture_hook(IDirect3DDevice9* pDevice, DWORD Stage, IDirect3DBaseTexture9* pTexture){
   vireio::debugf("IDirect3DDevice9_SetTexture_hook: pDevice: %i, Stage: %i, pTexture: %i", pDevice, Stage, pTexture);
   return IDirect3DDevice9_SetTexture_orig(pDevice, Stage, pTexture);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetTextureStageState)(IDirect3DDevice9*, DWORD, D3DTEXTURESTAGESTATETYPE, DWORD*);
IDirect3DDevice9_GetTextureStageState IDirect3DDevice9_GetTextureStageState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetTextureStageState_hook(IDirect3DDevice9* pDevice, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue){
   vireio::debugf("IDirect3DDevice9_GetTextureStageState_hook: pDevice: %i, Stage: %i, Type: %i, pValue: %i", pDevice, Stage, Type, pValue);
   return IDirect3DDevice9_GetTextureStageState_orig(pDevice, Stage, Type, pValue);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetTextureStageState)(IDirect3DDevice9*, DWORD, D3DTEXTURESTAGESTATETYPE, DWORD);
IDirect3DDevice9_SetTextureStageState IDirect3DDevice9_SetTextureStageState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetTextureStageState_hook(IDirect3DDevice9* pDevice, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value){
   vireio::debugf("IDirect3DDevice9_SetTextureStageState_hook: pDevice: %i, Stage: %i, Type: %i, Value: %i", pDevice, Stage, Type, Value);
   return IDirect3DDevice9_SetTextureStageState_orig(pDevice, Stage, Type, Value);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetSamplerState)(IDirect3DDevice9*, DWORD, D3DSAMPLERSTATETYPE, DWORD*);
IDirect3DDevice9_GetSamplerState IDirect3DDevice9_GetSamplerState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetSamplerState_hook(IDirect3DDevice9* pDevice, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue){
   vireio::debugf("IDirect3DDevice9_GetSamplerState_hook: pDevice: %i, Sampler: %i, Type: %i, pValue: %i", pDevice, Sampler, Type, pValue);
   return IDirect3DDevice9_GetSamplerState_orig(pDevice, Sampler, Type, pValue);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetSamplerState)(IDirect3DDevice9*, DWORD, D3DSAMPLERSTATETYPE, DWORD);
IDirect3DDevice9_SetSamplerState IDirect3DDevice9_SetSamplerState_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetSamplerState_hook(IDirect3DDevice9* pDevice, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value){
   vireio::debugf("IDirect3DDevice9_SetSamplerState_hook: pDevice: %i, Sampler: %i, Type: %i, Value: %i", pDevice, Sampler, Type, Value);
   return IDirect3DDevice9_SetSamplerState_orig(pDevice, Sampler, Type, Value);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_ValidateDevice)(IDirect3DDevice9*, DWORD*);
IDirect3DDevice9_ValidateDevice IDirect3DDevice9_ValidateDevice_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_ValidateDevice_hook(IDirect3DDevice9* pDevice, DWORD* pNumPasses){
   vireio::debugf("IDirect3DDevice9_ValidateDevice_hook: pDevice: %i, pNumPasses: %i", pDevice, pNumPasses);
   return IDirect3DDevice9_ValidateDevice_orig(pDevice, pNumPasses);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPaletteEntries)(IDirect3DDevice9*, UINT, CONST PALETTEENTRY*);
IDirect3DDevice9_SetPaletteEntries IDirect3DDevice9_SetPaletteEntries_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPaletteEntries_hook(IDirect3DDevice9* pDevice, UINT PaletteNumber, CONST PALETTEENTRY* pEntries){
   vireio::debugf("IDirect3DDevice9_SetPaletteEntries_hook: pDevice: %i, PaletteNumber: %i, pEntries: %i", pDevice, PaletteNumber, pEntries);
   return IDirect3DDevice9_SetPaletteEntries_orig(pDevice, PaletteNumber, pEntries);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPaletteEntries)(IDirect3DDevice9*, UINT, PALETTEENTRY*);
IDirect3DDevice9_GetPaletteEntries IDirect3DDevice9_GetPaletteEntries_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPaletteEntries_hook(IDirect3DDevice9* pDevice, UINT PaletteNumber, PALETTEENTRY* pEntries){
   vireio::debugf("IDirect3DDevice9_GetPaletteEntries_hook: pDevice: %i, PaletteNumber: %i, pEntries: %i", pDevice, PaletteNumber, pEntries);
   return IDirect3DDevice9_GetPaletteEntries_orig(pDevice, PaletteNumber, pEntries);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetCurrentTexturePalette)(IDirect3DDevice9*, UINT);
IDirect3DDevice9_SetCurrentTexturePalette IDirect3DDevice9_SetCurrentTexturePalette_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetCurrentTexturePalette_hook(IDirect3DDevice9* pDevice, UINT PaletteNumber){
   vireio::debugf("IDirect3DDevice9_SetCurrentTexturePalette_hook: pDevice: %i, PaletteNumber: %i", pDevice, PaletteNumber);
   return IDirect3DDevice9_SetCurrentTexturePalette_orig(pDevice, PaletteNumber);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetCurrentTexturePalette)(IDirect3DDevice9*, UINT*);
IDirect3DDevice9_GetCurrentTexturePalette IDirect3DDevice9_GetCurrentTexturePalette_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetCurrentTexturePalette_hook(IDirect3DDevice9* pDevice, UINT* PaletteNumber){
   vireio::debugf("IDirect3DDevice9_GetCurrentTexturePalette_hook: pDevice: %i, PaletteNumber: %i", pDevice, PaletteNumber);
   return IDirect3DDevice9_GetCurrentTexturePalette_orig(pDevice, PaletteNumber);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetScissorRect)(IDirect3DDevice9*, CONST RECT*);
IDirect3DDevice9_SetScissorRect IDirect3DDevice9_SetScissorRect_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetScissorRect_hook(IDirect3DDevice9* pDevice, CONST RECT* pRect){
   vireio::debugf("IDirect3DDevice9_SetScissorRect_hook: pDevice: %i, pRect: %i", pDevice, pRect);
   return IDirect3DDevice9_SetScissorRect_orig(pDevice, pRect);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetScissorRect)(IDirect3DDevice9*, RECT*);
IDirect3DDevice9_GetScissorRect IDirect3DDevice9_GetScissorRect_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetScissorRect_hook(IDirect3DDevice9* pDevice, RECT* pRect){
   vireio::debugf("IDirect3DDevice9_GetScissorRect_hook: pDevice: %i, pRect: %i", pDevice, pRect);
   return IDirect3DDevice9_GetScissorRect_orig(pDevice, pRect);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetSoftwareVertexProcessing)(IDirect3DDevice9*, BOOL);
IDirect3DDevice9_SetSoftwareVertexProcessing IDirect3DDevice9_SetSoftwareVertexProcessing_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetSoftwareVertexProcessing_hook(IDirect3DDevice9* pDevice, BOOL bSoftware){
   vireio::debugf("IDirect3DDevice9_SetSoftwareVertexProcessing_hook: pDevice: %i, bSoftware: %i", pDevice, bSoftware);
   return IDirect3DDevice9_SetSoftwareVertexProcessing_orig(pDevice, bSoftware);
}
typedef BOOL(APIENTRY* IDirect3DDevice9_GetSoftwareVertexProcessing)(IDirect3DDevice9*);
IDirect3DDevice9_GetSoftwareVertexProcessing IDirect3DDevice9_GetSoftwareVertexProcessing_orig = 0;
BOOL APIENTRY IDirect3DDevice9_GetSoftwareVertexProcessing_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_GetSoftwareVertexProcessing_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_GetSoftwareVertexProcessing_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetNPatchMode)(IDirect3DDevice9*, float);
IDirect3DDevice9_SetNPatchMode IDirect3DDevice9_SetNPatchMode_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetNPatchMode_hook(IDirect3DDevice9* pDevice, float nSegments){
   vireio::debugf("IDirect3DDevice9_SetNPatchMode_hook: pDevice: %i, nSegments: %i", pDevice, nSegments);
   return IDirect3DDevice9_SetNPatchMode_orig(pDevice, nSegments);
}
typedef float(APIENTRY* IDirect3DDevice9_GetNPatchMode)(IDirect3DDevice9*);
IDirect3DDevice9_GetNPatchMode IDirect3DDevice9_GetNPatchMode_orig = 0;
float APIENTRY IDirect3DDevice9_GetNPatchMode_hook(IDirect3DDevice9* pDevice){
   vireio::debugf("IDirect3DDevice9_GetNPatchMode_hook: pDevice: %i", pDevice);
   return IDirect3DDevice9_GetNPatchMode_orig(pDevice);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawPrimitive)(IDirect3DDevice9*, D3DPRIMITIVETYPE, UINT, UINT);
IDirect3DDevice9_DrawPrimitive IDirect3DDevice9_DrawPrimitive_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawPrimitive_hook(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount){
   vireio::debugf("IDirect3DDevice9_DrawPrimitive_hook: pDevice: %i, PrimitiveType: %i, StartVertex: %i, PrimitiveCount: %i", pDevice, PrimitiveType, StartVertex, PrimitiveCount);
   return IDirect3DDevice9_DrawPrimitive_orig(pDevice, PrimitiveType, StartVertex, PrimitiveCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawIndexedPrimitive)(IDirect3DDevice9*, D3DPRIMITIVETYPE, INT, UINT, UINT, UINT, UINT);
IDirect3DDevice9_DrawIndexedPrimitive IDirect3DDevice9_DrawIndexedPrimitive_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawIndexedPrimitive_hook(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE arg1, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount){
   vireio::debugf("IDirect3DDevice9_DrawIndexedPrimitive_hook: pDevice: %i, arg1: %i, BaseVertexIndex: %i, MinVertexIndex: %i, NumVertices: %i, startIndex: %i, primCount: %i", pDevice, arg1, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
   return IDirect3DDevice9_DrawIndexedPrimitive_orig(pDevice, arg1, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawPrimitiveUP)(IDirect3DDevice9*, D3DPRIMITIVETYPE, UINT, CONST void*, UINT);
IDirect3DDevice9_DrawPrimitiveUP IDirect3DDevice9_DrawPrimitiveUP_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawPrimitiveUP_hook(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride){
   vireio::debugf("IDirect3DDevice9_DrawPrimitiveUP_hook: pDevice: %i, PrimitiveType: %i, PrimitiveCount: %i, pVertexStreamZeroData: %i, VertexStreamZeroStride: %i", pDevice, PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
   return IDirect3DDevice9_DrawPrimitiveUP_orig(pDevice, PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawIndexedPrimitiveUP)(IDirect3DDevice9*, D3DPRIMITIVETYPE, UINT, UINT, UINT, CONST void*, D3DFORMAT, CONST void*, UINT);
IDirect3DDevice9_DrawIndexedPrimitiveUP IDirect3DDevice9_DrawIndexedPrimitiveUP_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawIndexedPrimitiveUP_hook(IDirect3DDevice9* pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride){
   vireio::debugf("IDirect3DDevice9_DrawIndexedPrimitiveUP_hook: pDevice: %i, PrimitiveType: %i, MinVertexIndex: %i, NumVertices: %i, PrimitiveCount: %i, pIndexData: %i, IndexDataFormat: %i, pVertexStreamZeroData: %i, VertexStreamZeroStride: %i", pDevice, PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
   return IDirect3DDevice9_DrawIndexedPrimitiveUP_orig(pDevice, PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_ProcessVertices)(IDirect3DDevice9*, UINT, UINT, UINT, IDirect3DVertexBuffer9*, IDirect3DVertexDeclaration9*, DWORD);
IDirect3DDevice9_ProcessVertices IDirect3DDevice9_ProcessVertices_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_ProcessVertices_hook(IDirect3DDevice9* pDevice, UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags){
   vireio::debugf("IDirect3DDevice9_ProcessVertices_hook: pDevice: %i, SrcStartIndex: %i, DestIndex: %i, VertexCount: %i, pDestBuffer: %i, pVertexDecl: %i, Flags: %i", pDevice, SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
   return IDirect3DDevice9_ProcessVertices_orig(pDevice, SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateVertexDeclaration)(IDirect3DDevice9*, CONST D3DVERTEXELEMENT9*, IDirect3DVertexDeclaration9**);
IDirect3DDevice9_CreateVertexDeclaration IDirect3DDevice9_CreateVertexDeclaration_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateVertexDeclaration_hook(IDirect3DDevice9* pDevice, CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl){
   vireio::debugf("IDirect3DDevice9_CreateVertexDeclaration_hook: pDevice: %i, pVertexElements: %i, ppDecl: %i", pDevice, pVertexElements, ppDecl);
   return IDirect3DDevice9_CreateVertexDeclaration_orig(pDevice, pVertexElements, ppDecl);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexDeclaration)(IDirect3DDevice9*, IDirect3DVertexDeclaration9*);
IDirect3DDevice9_SetVertexDeclaration IDirect3DDevice9_SetVertexDeclaration_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexDeclaration_hook(IDirect3DDevice9* pDevice, IDirect3DVertexDeclaration9* pDecl){
   vireio::debugf("IDirect3DDevice9_SetVertexDeclaration_hook: pDevice: %i, pDecl: %i", pDevice, pDecl);
   return IDirect3DDevice9_SetVertexDeclaration_orig(pDevice, pDecl);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexDeclaration)(IDirect3DDevice9*, IDirect3DVertexDeclaration9**);
IDirect3DDevice9_GetVertexDeclaration IDirect3DDevice9_GetVertexDeclaration_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexDeclaration_hook(IDirect3DDevice9* pDevice, IDirect3DVertexDeclaration9** ppDecl){
   vireio::debugf("IDirect3DDevice9_GetVertexDeclaration_hook: pDevice: %i, ppDecl: %i", pDevice, ppDecl);
   return IDirect3DDevice9_GetVertexDeclaration_orig(pDevice, ppDecl);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetFVF)(IDirect3DDevice9*, DWORD);
IDirect3DDevice9_SetFVF IDirect3DDevice9_SetFVF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetFVF_hook(IDirect3DDevice9* pDevice, DWORD FVF){
   vireio::debugf("IDirect3DDevice9_SetFVF_hook: pDevice: %i, FVF: %i", pDevice, FVF);
   return IDirect3DDevice9_SetFVF_orig(pDevice, FVF);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetFVF)(IDirect3DDevice9*, DWORD*);
IDirect3DDevice9_GetFVF IDirect3DDevice9_GetFVF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetFVF_hook(IDirect3DDevice9* pDevice, DWORD* pFVF){
   vireio::debugf("IDirect3DDevice9_GetFVF_hook: pDevice: %i, pFVF: %i", pDevice, pFVF);
   return IDirect3DDevice9_GetFVF_orig(pDevice, pFVF);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateVertexShader)(IDirect3DDevice9*, CONST DWORD*, IDirect3DVertexShader9**);
IDirect3DDevice9_CreateVertexShader IDirect3DDevice9_CreateVertexShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateVertexShader_hook(IDirect3DDevice9* pDevice, CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader){
   vireio::debugf("IDirect3DDevice9_CreateVertexShader_hook: pDevice: %i, pFunction: %i, ppShader: %i", pDevice, pFunction, ppShader);
   return IDirect3DDevice9_CreateVertexShader_orig(pDevice, pFunction, ppShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexShader)(IDirect3DDevice9*, IDirect3DVertexShader9*);
IDirect3DDevice9_SetVertexShader IDirect3DDevice9_SetVertexShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexShader_hook(IDirect3DDevice9* pDevice, IDirect3DVertexShader9* pShader){
   vireio::debugf("IDirect3DDevice9_SetVertexShader_hook: pDevice: %i, pShader: %i", pDevice, pShader);
   return IDirect3DDevice9_SetVertexShader_orig(pDevice, pShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexShader)(IDirect3DDevice9*, IDirect3DVertexShader9**);
IDirect3DDevice9_GetVertexShader IDirect3DDevice9_GetVertexShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexShader_hook(IDirect3DDevice9* pDevice, IDirect3DVertexShader9** ppShader){
   vireio::debugf("IDirect3DDevice9_GetVertexShader_hook: pDevice: %i, ppShader: %i", pDevice, ppShader);
   return IDirect3DDevice9_GetVertexShader_orig(pDevice, ppShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexShaderConstantF)(IDirect3DDevice9*, UINT, CONST float*, UINT);
IDirect3DDevice9_SetVertexShaderConstantF IDirect3DDevice9_SetVertexShaderConstantF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexShaderConstantF_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount){
   vireio::debugf("IDirect3DDevice9_SetVertexShaderConstantF_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, Vector4fCount: %i", pDevice, StartRegister, pConstantData, Vector4fCount);
   return IDirect3DDevice9_SetVertexShaderConstantF_orig(pDevice, StartRegister, pConstantData, Vector4fCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexShaderConstantF)(IDirect3DDevice9*, UINT, float*, UINT);
IDirect3DDevice9_GetVertexShaderConstantF IDirect3DDevice9_GetVertexShaderConstantF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexShaderConstantF_hook(IDirect3DDevice9* pDevice, UINT StartRegister, float* pConstantData, UINT Vector4fCount){
   vireio::debugf("IDirect3DDevice9_GetVertexShaderConstantF_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, Vector4fCount: %i", pDevice, StartRegister, pConstantData, Vector4fCount);
   return IDirect3DDevice9_GetVertexShaderConstantF_orig(pDevice, StartRegister, pConstantData, Vector4fCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexShaderConstantI)(IDirect3DDevice9*, UINT, CONST int*, UINT);
IDirect3DDevice9_SetVertexShaderConstantI IDirect3DDevice9_SetVertexShaderConstantI_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexShaderConstantI_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount){
   vireio::debugf("IDirect3DDevice9_SetVertexShaderConstantI_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, Vector4iCount: %i", pDevice, StartRegister, pConstantData, Vector4iCount);
   return IDirect3DDevice9_SetVertexShaderConstantI_orig(pDevice, StartRegister, pConstantData, Vector4iCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexShaderConstantI)(IDirect3DDevice9*, UINT, int*, UINT);
IDirect3DDevice9_GetVertexShaderConstantI IDirect3DDevice9_GetVertexShaderConstantI_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexShaderConstantI_hook(IDirect3DDevice9* pDevice, UINT StartRegister, int* pConstantData, UINT Vector4iCount){
   vireio::debugf("IDirect3DDevice9_GetVertexShaderConstantI_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, Vector4iCount: %i", pDevice, StartRegister, pConstantData, Vector4iCount);
   return IDirect3DDevice9_GetVertexShaderConstantI_orig(pDevice, StartRegister, pConstantData, Vector4iCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetVertexShaderConstantB)(IDirect3DDevice9*, UINT, CONST BOOL*, UINT );
IDirect3DDevice9_SetVertexShaderConstantB IDirect3DDevice9_SetVertexShaderConstantB_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetVertexShaderConstantB_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount){
   vireio::debugf("IDirect3DDevice9_SetVertexShaderConstantB_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, BoolCount: %i", pDevice, StartRegister, pConstantData, BoolCount);
   return IDirect3DDevice9_SetVertexShaderConstantB_orig(pDevice, StartRegister, pConstantData, BoolCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetVertexShaderConstantB)(IDirect3DDevice9*, UINT, BOOL*, UINT);
IDirect3DDevice9_GetVertexShaderConstantB IDirect3DDevice9_GetVertexShaderConstantB_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetVertexShaderConstantB_hook(IDirect3DDevice9* pDevice, UINT StartRegister, BOOL* pConstantData, UINT BoolCount){
   vireio::debugf("IDirect3DDevice9_GetVertexShaderConstantB_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, BoolCount: %i", pDevice, StartRegister, pConstantData, BoolCount);
   return IDirect3DDevice9_GetVertexShaderConstantB_orig(pDevice, StartRegister, pConstantData, BoolCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetStreamSource)(IDirect3DDevice9*, UINT, IDirect3DVertexBuffer9*, UINT, UINT);
IDirect3DDevice9_SetStreamSource IDirect3DDevice9_SetStreamSource_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetStreamSource_hook(IDirect3DDevice9* pDevice, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride){
   vireio::debugf("IDirect3DDevice9_SetStreamSource_hook: pDevice: %i, StreamNumber: %i, pStreamData: %i, OffsetInBytes: %i, Stride: %i", pDevice, StreamNumber, pStreamData, OffsetInBytes, Stride);
   return IDirect3DDevice9_SetStreamSource_orig(pDevice, StreamNumber, pStreamData, OffsetInBytes, Stride);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetStreamSource)(IDirect3DDevice9*, UINT, IDirect3DVertexBuffer9**, UINT*, UINT*);
IDirect3DDevice9_GetStreamSource IDirect3DDevice9_GetStreamSource_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetStreamSource_hook(IDirect3DDevice9* pDevice, UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride){
   vireio::debugf("IDirect3DDevice9_GetStreamSource_hook: pDevice: %i, StreamNumber: %i, ppStreamData: %i, pOffsetInBytes: %i, pStride: %i", pDevice, StreamNumber, ppStreamData, pOffsetInBytes, pStride);
   return IDirect3DDevice9_GetStreamSource_orig(pDevice, StreamNumber, ppStreamData, pOffsetInBytes, pStride);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetStreamSourceFreq)(IDirect3DDevice9*, UINT, UINT);
IDirect3DDevice9_SetStreamSourceFreq IDirect3DDevice9_SetStreamSourceFreq_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetStreamSourceFreq_hook(IDirect3DDevice9* pDevice, UINT StreamNumber, UINT Setting){
   vireio::debugf("IDirect3DDevice9_SetStreamSourceFreq_hook: pDevice: %i, StreamNumber: %i, Setting: %i", pDevice, StreamNumber, Setting);
   return IDirect3DDevice9_SetStreamSourceFreq_orig(pDevice, StreamNumber, Setting);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetStreamSourceFreq)(IDirect3DDevice9*, UINT, UINT*);
IDirect3DDevice9_GetStreamSourceFreq IDirect3DDevice9_GetStreamSourceFreq_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetStreamSourceFreq_hook(IDirect3DDevice9* pDevice, UINT StreamNumber, UINT* pSetting){
   vireio::debugf("IDirect3DDevice9_GetStreamSourceFreq_hook: pDevice: %i, StreamNumber: %i, pSetting: %i", pDevice, StreamNumber, pSetting);
   return IDirect3DDevice9_GetStreamSourceFreq_orig(pDevice, StreamNumber, pSetting);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetIndices)(IDirect3DDevice9*, IDirect3DIndexBuffer9*);
IDirect3DDevice9_SetIndices IDirect3DDevice9_SetIndices_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetIndices_hook(IDirect3DDevice9* pDevice, IDirect3DIndexBuffer9* pIndexData){
   vireio::debugf("IDirect3DDevice9_SetIndices_hook: pDevice: %i, pIndexData: %i", pDevice, pIndexData);
   return IDirect3DDevice9_SetIndices_orig(pDevice, pIndexData);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetIndices)(IDirect3DDevice9*, IDirect3DIndexBuffer9**);
IDirect3DDevice9_GetIndices IDirect3DDevice9_GetIndices_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetIndices_hook(IDirect3DDevice9* pDevice, IDirect3DIndexBuffer9** ppIndexData){
   vireio::debugf("IDirect3DDevice9_GetIndices_hook: pDevice: %i, ppIndexData: %i", pDevice, ppIndexData);
   return IDirect3DDevice9_GetIndices_orig(pDevice, ppIndexData);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreatePixelShader)(IDirect3DDevice9*, CONST DWORD*, IDirect3DPixelShader9**);
IDirect3DDevice9_CreatePixelShader IDirect3DDevice9_CreatePixelShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreatePixelShader_hook(IDirect3DDevice9* pDevice, CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader){
   vireio::debugf("IDirect3DDevice9_CreatePixelShader_hook: pDevice: %i, pFunction: %i, ppShader: %i", pDevice, pFunction, ppShader);
   return IDirect3DDevice9_CreatePixelShader_orig(pDevice, pFunction, ppShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPixelShader)(IDirect3DDevice9*, IDirect3DPixelShader9*);
IDirect3DDevice9_SetPixelShader IDirect3DDevice9_SetPixelShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPixelShader_hook(IDirect3DDevice9* pDevice, IDirect3DPixelShader9* pShader){
   vireio::debugf("IDirect3DDevice9_SetPixelShader_hook: pDevice: %i, pShader: %i", pDevice, pShader);
   return IDirect3DDevice9_SetPixelShader_orig(pDevice, pShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPixelShader)(IDirect3DDevice9*, IDirect3DPixelShader9**);
IDirect3DDevice9_GetPixelShader IDirect3DDevice9_GetPixelShader_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPixelShader_hook(IDirect3DDevice9* pDevice, IDirect3DPixelShader9** ppShader){
   vireio::debugf("IDirect3DDevice9_GetPixelShader_hook: pDevice: %i, ppShader: %i", pDevice, ppShader);
   return IDirect3DDevice9_GetPixelShader_orig(pDevice, ppShader);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPixelShaderConstantF)(IDirect3DDevice9*, UINT, CONST float*, UINT);
IDirect3DDevice9_SetPixelShaderConstantF IDirect3DDevice9_SetPixelShaderConstantF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPixelShaderConstantF_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount){
   vireio::debugf("IDirect3DDevice9_SetPixelShaderConstantF_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, Vector4fCount: %i", pDevice, StartRegister, pConstantData, Vector4fCount);
   return IDirect3DDevice9_SetPixelShaderConstantF_orig(pDevice, StartRegister, pConstantData, Vector4fCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPixelShaderConstantF)(IDirect3DDevice9*, UINT, float*, UINT);
IDirect3DDevice9_GetPixelShaderConstantF IDirect3DDevice9_GetPixelShaderConstantF_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPixelShaderConstantF_hook(IDirect3DDevice9* pDevice, UINT StartRegister, float* pConstantData, UINT Vector4fCount){
   vireio::debugf("IDirect3DDevice9_GetPixelShaderConstantF_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, Vector4fCount: %i", pDevice, StartRegister, pConstantData, Vector4fCount);
   return IDirect3DDevice9_GetPixelShaderConstantF_orig(pDevice, StartRegister, pConstantData, Vector4fCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPixelShaderConstantI)(IDirect3DDevice9*, UINT, CONST int*, UINT);
IDirect3DDevice9_SetPixelShaderConstantI IDirect3DDevice9_SetPixelShaderConstantI_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPixelShaderConstantI_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount){
   vireio::debugf("IDirect3DDevice9_SetPixelShaderConstantI_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, Vector4iCount: %i", pDevice, StartRegister, pConstantData, Vector4iCount);
   return IDirect3DDevice9_SetPixelShaderConstantI_orig(pDevice, StartRegister, pConstantData, Vector4iCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPixelShaderConstantI)(IDirect3DDevice9*, UINT, int*, UINT);
IDirect3DDevice9_GetPixelShaderConstantI IDirect3DDevice9_GetPixelShaderConstantI_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPixelShaderConstantI_hook(IDirect3DDevice9* pDevice, UINT StartRegister, int* pConstantData, UINT Vector4iCount){
   vireio::debugf("IDirect3DDevice9_GetPixelShaderConstantI_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, Vector4iCount: %i", pDevice, StartRegister, pConstantData, Vector4iCount);
   return IDirect3DDevice9_GetPixelShaderConstantI_orig(pDevice, StartRegister, pConstantData, Vector4iCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_SetPixelShaderConstantB)(IDirect3DDevice9*, UINT, CONST BOOL*, UINT );
IDirect3DDevice9_SetPixelShaderConstantB IDirect3DDevice9_SetPixelShaderConstantB_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_SetPixelShaderConstantB_hook(IDirect3DDevice9* pDevice, UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount){
   vireio::debugf("IDirect3DDevice9_SetPixelShaderConstantB_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, BoolCount: %i", pDevice, StartRegister, pConstantData, BoolCount);
   return IDirect3DDevice9_SetPixelShaderConstantB_orig(pDevice, StartRegister, pConstantData, BoolCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_GetPixelShaderConstantB)(IDirect3DDevice9*, UINT, BOOL*, UINT);
IDirect3DDevice9_GetPixelShaderConstantB IDirect3DDevice9_GetPixelShaderConstantB_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_GetPixelShaderConstantB_hook(IDirect3DDevice9* pDevice, UINT StartRegister, BOOL* pConstantData, UINT BoolCount){
   vireio::debugf("IDirect3DDevice9_GetPixelShaderConstantB_hook: pDevice: %i, StartRegister: %i, pConstantData: %i, BoolCount: %i", pDevice, StartRegister, pConstantData, BoolCount);
   return IDirect3DDevice9_GetPixelShaderConstantB_orig(pDevice, StartRegister, pConstantData, BoolCount);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawRectPatch)(IDirect3DDevice9*, UINT, CONST float*, CONST D3DRECTPATCH_INFO*);
IDirect3DDevice9_DrawRectPatch IDirect3DDevice9_DrawRectPatch_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawRectPatch_hook(IDirect3DDevice9* pDevice, UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo){
   vireio::debugf("IDirect3DDevice9_DrawRectPatch_hook: pDevice: %i, Handle: %i, pNumSegs: %i, pRectPatchInfo: %i", pDevice, Handle, pNumSegs, pRectPatchInfo);
   return IDirect3DDevice9_DrawRectPatch_orig(pDevice, Handle, pNumSegs, pRectPatchInfo);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DrawTriPatch)(IDirect3DDevice9*, UINT, CONST float*, CONST D3DTRIPATCH_INFO*);
IDirect3DDevice9_DrawTriPatch IDirect3DDevice9_DrawTriPatch_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DrawTriPatch_hook(IDirect3DDevice9* pDevice, UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo){
   vireio::debugf("IDirect3DDevice9_DrawTriPatch_hook: pDevice: %i, Handle: %i, pNumSegs: %i, pTriPatchInfo: %i", pDevice, Handle, pNumSegs, pTriPatchInfo);
   return IDirect3DDevice9_DrawTriPatch_orig(pDevice, Handle, pNumSegs, pTriPatchInfo);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_DeletePatch)(IDirect3DDevice9*, UINT);
IDirect3DDevice9_DeletePatch IDirect3DDevice9_DeletePatch_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_DeletePatch_hook(IDirect3DDevice9* pDevice, UINT Handle){
   vireio::debugf("IDirect3DDevice9_DeletePatch_hook: pDevice: %i, Handle: %i", pDevice, Handle);
   return IDirect3DDevice9_DeletePatch_orig(pDevice, Handle);
}
typedef HRESULT(APIENTRY* IDirect3DDevice9_CreateQuery)(IDirect3DDevice9*, D3DQUERYTYPE, IDirect3DQuery9**);
IDirect3DDevice9_CreateQuery IDirect3DDevice9_CreateQuery_orig = 0;
HRESULT APIENTRY IDirect3DDevice9_CreateQuery_hook(IDirect3DDevice9* pDevice, D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery){
   vireio::debugf("IDirect3DDevice9_CreateQuery_hook: pDevice: %i, Type: %i, ppQuery: %i", pDevice, Type, ppQuery);
   return IDirect3DDevice9_CreateQuery_orig(pDevice, Type, ppQuery);
}
