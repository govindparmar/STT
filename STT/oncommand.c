#include "STT.h"

VOID WINAPI OnCommand(
	_In_ HWND hWnd,
	_In_ INT nID,
	_In_ HWND hwSource,
	_In_ UINT uNotify
)
{
	CONST HWND hCheck = FindWindowExW(hWnd, NULL, L"Button", NULL);
	CONST HWND hDateTime = FindWindowExW(hWnd, NULL, DATETIMEPICK_CLASSW, NULL);
	CONST HWND hLabel = FindWindowExW(hWnd, NULL, L"Static", NULL);

	if (hwSource == hCheck)
	{
		CONST WCHAR wszMessage[2000];
		ULARGE_INTEGER ulCurrent, ulTarget, ulDifference;
		FILETIME ftCurrent;
		FILETIME ftTarget;
		SYSTEMTIME st;
		SYSTEMTIME lt;

		GetLocalTime(&lt);
		DateTime_GetSystemtime(hDateTime, &st);

		SystemTimeToFileTime(&lt, &ftCurrent);
		SystemTimeToFileTime(&st, &ftTarget);

		ulCurrent.HighPart = ftCurrent.dwHighDateTime;
		ulCurrent.LowPart = ftCurrent.dwLowDateTime;

		ulTarget.HighPart = ftTarget.dwHighDateTime;
		ulTarget.LowPart = ftTarget.dwLowDateTime;

		if (ulTarget.QuadPart < ulCurrent.QuadPart)
		{
			StringCchCopyW(wszMessage, 2000, L"That time is in the past.");
		}
		else
		{
			ulDifference.QuadPart = ulTarget.QuadPart - ulCurrent.QuadPart;
			ulDifference.QuadPart /= 10000000;
			StringCchPrintfW(wszMessage, 2000, L"There are %I64u seconds until %.2hu:%.2hu", ulDifference.QuadPart, st.wHour, st.wMinute);
		}

		SetWindowTextW(hLabel, wszMessage);
	}

	return;
}
