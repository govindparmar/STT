#include "STT.h"

CONST WCHAR g_wszClassName[] = L"SECONDS_COUNTER_WINDOW_CLASS";

_Pre_satisfies_(hInstance != NULL)
_Success_(return > 0)
_Ret_range_(0, USHRT_MAX)
_Check_return_
_Must_inspect_result_

ATOM WINAPI RegisterWCEX(
	_In_ _Notnull_ HINSTANCE hInstance
)
{
	WNDCLASSEXW wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEXW));

	wcex.cbSize = sizeof(WNDCLASSEXW);
	wcex.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wcex.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wcex.hIcon =
	wcex.hIconSm = LoadIconW(NULL, IDI_APPLICATION);
	wcex.hInstance = hInstance;
	wcex.lpszClassName = g_wszClassName;
	wcex.lpfnWndProc = WindowProc;
	
	return RegisterClassExW(&wcex);
}