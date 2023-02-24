#include <windows.h>

typedef HRESULT(APIENTRY* OrignalDirect3DCreate9Ex) (UINT SDKVersion, IDirect3D9Ex**);
typedef IDirect3D9* (APIENTRY* OrignalDirect3DCreate9) (UINT SDKVersion);
typedef IDirect3D9* (APIENTRY* OrignalDirect3DCreate9On12) (UINT SDKVersion, void* pOverrideList, UINT NumOverrideEntries);

struct d3d9_dll { 
	HMODULE dll;
	FARPROC OrignalD3DPERF_BeginEvent;
	FARPROC OrignalD3DPERF_EndEvent;
	FARPROC OrignalD3DPERF_GetStatus;
	FARPROC OrignalD3DPERF_QueryRepeatFrame;
	FARPROC OrignalD3DPERF_SetMarker;
	FARPROC OrignalD3DPERF_SetOptions;
	FARPROC OrignalD3DPERF_SetRegion;
	FARPROC OrignalDebugSetLevel;
	FARPROC OrignalDebugSetMute;
	FARPROC OrignalDirect3D9EnableMaximizedWindowedModeShim;
	OrignalDirect3DCreate9 OrignalDirect3DCreate9;
	OrignalDirect3DCreate9Ex OrignalDirect3DCreate9Ex;
	OrignalDirect3DCreate9On12 OrignalDirect3DCreate9On12;
	FARPROC OrignalDirect3DCreate9On12Ex;
	FARPROC OrignalDirect3DShaderValidatorCreate9;
	FARPROC OrignalPSGPError;
	FARPROC OrignalPSGPSampleTexture;
} d3d9;

extern "C"
{
	void FakeD3DPERF_BeginEvent() { }
	void FakeD3DPERF_EndEvent() { }
	void FakeD3DPERF_GetStatus() { }
	void FakeD3DPERF_QueryRepeatFrame() { }
	void FakeD3DPERF_SetMarker() { }
	void FakeD3DPERF_SetOptions() { }
	void FakeD3DPERF_SetRegion() { }
	void FakeDebugSetLevel() { }
	void FakeDebugSetMute() { }
	void FakeDirect3D9EnableMaximizedWindowedModeShim() { }
	IDirect3D9* FakeDirect3DCreate9(UINT SDKVersion) {
		vireio::debugf("convert Direct3DCreate9() to OrignalDirect3DCreate9On12()");
		
		HRESULT res = d3d9.OrignalDirect3DCreate9Ex(SDKVersion, &SharingExDx9);
		if (FAILED(res)) {
			vireio::debugf("Failed when creating the SharingExDx9");
			return NULL;
		}


		IDirect3D9* d9 = d3d9.OrignalDirect3DCreate9On12(SDKVersion, NULL, 0);
		DWORD64* dVtable_alt = (DWORD64*)*(DWORD64*)d9;

		if (MH_CreateHook((DWORD_PTR*)dVtable_alt[16], &D3DCreateDevice_hook, reinterpret_cast<void**>(&D3DCreateDevice_orig)) != MH_OK) {
			MessageBoxA(NULL, "Failed to create D3DCreateDevice hook", "Error", MB_OK);
			return NULL;
		}
		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
			MessageBoxA(NULL, "Failed to enable D3DCreateDevice hook", "Error", MB_OK);
			return NULL;
		}



		return d9;


		return d3d9.OrignalDirect3DCreate9(SDKVersion);

		IDirect3D9Ex* dx = NULL;
		IDirect3D9* dxout = NULL;

		
		
		if (FAILED(dx->QueryInterface(__uuidof(IDirect3D9), (void**)&dxout))) {
			vireio::debugf("Failed: QueryInterface");
		}
		

		return dxout;
	}
	void FakeDirect3DCreate9Ex() { }
	void FakeDirect3DCreate9On12() { }
	void FakeDirect3DCreate9On12Ex() { }
	void FakeDirect3DShaderValidatorCreate9() { }
	void FakePSGPError() { }
	void FakePSGPSampleTexture() { }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	char path[MAX_PATH];
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		vireio::debugf("d3d9 hooking dll loaded");
		//CopyMemory(path + GetSystemDirectory(path, MAX_PATH - 10), L"\\d3d9.dll", 11);
		//CopyMemory(path + GetSystemDirectory(path, MAX_PATH - 10), L"\\d3d9.dll", 11);

		d3d9.dll = LoadLibrary(L"C:\\Windows\\System32\\d3d9.dll");
		if (d3d9.dll == NULL)
		{
			MessageBox(0, L"Cannot load original d3d9.dll library", L"Proxy", MB_ICONERROR);
			ExitProcess(0);
		}

		if (MH_Initialize() != MH_OK) {
			MessageBox(NULL, L"Failed to initialize MinHook", L"Error", MB_OK);
			return false;
		}
		
		bool Fail = false;
		d3d9.OrignalD3DPERF_BeginEvent = GetProcAddress(d3d9.dll, "D3DPERF_BeginEvent");
		if (MH_CreateHook(FakeD3DPERF_BeginEvent, d3d9.OrignalD3DPERF_BeginEvent, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalD3DPERF_EndEvent = GetProcAddress(d3d9.dll, "D3DPERF_EndEvent");
		if (MH_CreateHook(FakeD3DPERF_EndEvent, d3d9.OrignalD3DPERF_EndEvent, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalD3DPERF_GetStatus = GetProcAddress(d3d9.dll, "D3DPERF_GetStatus");
		if (MH_CreateHook(FakeD3DPERF_GetStatus, d3d9.OrignalD3DPERF_GetStatus, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalD3DPERF_QueryRepeatFrame = GetProcAddress(d3d9.dll, "D3DPERF_QueryRepeatFrame");
		if (MH_CreateHook(FakeD3DPERF_QueryRepeatFrame, d3d9.OrignalD3DPERF_QueryRepeatFrame, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalD3DPERF_SetMarker = GetProcAddress(d3d9.dll, "D3DPERF_SetMarker");
		if (MH_CreateHook(FakeD3DPERF_SetMarker, d3d9.OrignalD3DPERF_SetMarker, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalD3DPERF_SetOptions = GetProcAddress(d3d9.dll, "D3DPERF_SetOptions");
		if (MH_CreateHook(FakeD3DPERF_SetOptions, d3d9.OrignalD3DPERF_SetOptions, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalD3DPERF_SetRegion = GetProcAddress(d3d9.dll, "D3DPERF_SetRegion");
		if (MH_CreateHook(FakeD3DPERF_SetRegion, d3d9.OrignalD3DPERF_SetRegion, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalDebugSetLevel = GetProcAddress(d3d9.dll, "DebugSetLevel");
		if (MH_CreateHook(FakeDebugSetLevel, d3d9.OrignalDebugSetLevel, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalDebugSetMute = GetProcAddress(d3d9.dll, "DebugSetMute");
		if (MH_CreateHook(FakeDebugSetMute, d3d9.OrignalDebugSetMute, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalDirect3D9EnableMaximizedWindowedModeShim = GetProcAddress(d3d9.dll, "Direct3D9EnableMaximizedWindowedModeShim");
		if (MH_CreateHook(FakeDirect3D9EnableMaximizedWindowedModeShim, d3d9.OrignalDirect3D9EnableMaximizedWindowedModeShim, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalDirect3DCreate9 = (OrignalDirect3DCreate9)GetProcAddress(d3d9.dll, "Direct3DCreate9");
		//if (MH_CreateHook(FakeDirect3DCreate9, d3d9.OrignalDirect3DCreate9, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalDirect3DCreate9Ex = (OrignalDirect3DCreate9Ex)GetProcAddress(d3d9.dll, "Direct3DCreate9Ex");
		if (MH_CreateHook(FakeDirect3DCreate9Ex, d3d9.OrignalDirect3DCreate9Ex, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalDirect3DCreate9On12 = (OrignalDirect3DCreate9On12)GetProcAddress(d3d9.dll, "Direct3DCreate9On12");
		if (MH_CreateHook(FakeDirect3DCreate9On12, d3d9.OrignalDirect3DCreate9On12, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalDirect3DCreate9On12Ex = GetProcAddress(d3d9.dll, "Direct3DCreate9On12Ex");
		if (MH_CreateHook(FakeDirect3DCreate9On12Ex, d3d9.OrignalDirect3DCreate9On12Ex, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalDirect3DShaderValidatorCreate9 = GetProcAddress(d3d9.dll, "Direct3DShaderValidatorCreate9");
		if (MH_CreateHook(FakeDirect3DShaderValidatorCreate9, d3d9.OrignalDirect3DShaderValidatorCreate9, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalPSGPError = GetProcAddress(d3d9.dll, "PSGPError");
		if (MH_CreateHook(FakePSGPError, d3d9.OrignalPSGPError, NULL) != MH_OK) { Fail = true; }
		d3d9.OrignalPSGPSampleTexture = GetProcAddress(d3d9.dll, "PSGPSampleTexture");
		if (MH_CreateHook(FakePSGPSampleTexture, d3d9.OrignalPSGPSampleTexture, NULL) != MH_OK) { Fail = true; }
		
		if (Fail) {
			MessageBoxA(NULL, "Failed to create hooks", "Error", MB_OK);
			return false;
		}

		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
			MessageBoxA(NULL, "Failed to enable hooks", "Error", MB_OK);
			return false;
		}

		break;
	}
	case DLL_PROCESS_DETACH:
	{
		FreeLibrary(d3d9.dll);
	}
	break;
	}
	return TRUE;
}
