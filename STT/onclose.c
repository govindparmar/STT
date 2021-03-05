#include "STT.h"

VOID WINAPI OnClose(
	_In_ HWND hWnd
)
{
	DestroyWindow(hWnd);
}
