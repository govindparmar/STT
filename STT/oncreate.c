#include "STT.h"

_Success_(return == TRUE)

BOOL WINAPI OnCreate(
	_In_ HWND hWnd,
	_In_ LPCREATESTRUCTW lpCreateStruct
)
{
	CONST HINSTANCE hInstance = lpCreateStruct->hInstance;
	INITCOMMONCONTROLSEX iccx;
	SYSTEMTIME defaultSt;
	HWND hDateTime;
	HWND hCheck;
	HWND hLabel;

	iccx.dwICC = ICC_STANDARD_CLASSES | ICC_DATE_CLASSES;
	iccx.dwSize = sizeof(INITCOMMONCONTROLSEX);

	InitCommonControlsEx(&iccx);

	hDateTime = CreateWindowW(DATETIMEPICK_CLASSW, L"DateTime", 
		WS_BORDER | WS_CHILD | WS_VISIBLE | WS_TABSTOP | DTS_TIMEFORMAT,
		10, 10, 220, 21, hWnd, NULL, hInstance, NULL);
	hCheck = CreateWindowW(L"Button", L"Check", WS_VISIBLE | WS_CHILD | WS_TABSTOP, 10, 50, 100, 23, hWnd, NULL, hInstance, NULL);
	hLabel = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD, 10, 90, 250, 21, hWnd, NULL, hInstance, NULL);

	GetLocalTime(&defaultSt);
	defaultSt.wHour = 16;
	defaultSt.wMinute = 0;
	defaultSt.wSecond = 0;
	defaultSt.wMilliseconds = 0;

	DateTime_SetSystemtime(hDateTime, GDT_VALID, &defaultSt);

	return TRUE;
}