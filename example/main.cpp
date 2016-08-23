#include <windows.h>

typedef BOOL (CALLBACK* LPFNDLLFUNC1)();

int main(void)
{
	HINSTANCE hDLL;               // Handle to DLL
	LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
	DWORD dwParam1;
	UINT  uParam2, uReturnVal;

	hDLL = LoadLibrary(".\\..\\build\\openvr_api.dll");
	if (hDLL == NULL) { return -1; }
	lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL,
	                                            "VR_IsHmdPresent");
	if (!lpfnDllFunc1) {
	  // handle the error
	  FreeLibrary(hDLL);
	  return -2;
	}
	else {
	  // call the function
	  uReturnVal = lpfnDllFunc1();
	}
    return (0);
}