
//include headers

#include "stdafx.h"
#include<windows.h> 

#define MYTIMER 100

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{

	WNDCLASSEX wndClass;
	HWND hwnd;
	MSG msg;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = TEXT("MY ANIMATED WINDOW");
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&wndClass);

	hwnd = CreateWindow(TEXT("MY ANIMATED WINDOW"),
		TEXT("MY ANIMATED WINDOW"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	
	static RECT rc, rcTemp;
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hBrush;
	static int iPaintFlag = 0;
	TCHAR str[255];

	switch (iMsg)
	{
		case WM_CREATE:
			wsprintf(str, TEXT("WM Create is arrived"));
			MessageBox(hwnd, str, TEXT("Message"), NULL);
			rcTemp.left = 0;
			rcTemp.right = 0;
			rcTemp.bottom = 0;
			rcTemp.top = 0;
			SetTimer(hwnd, MYTIMER, 1000, NULL);
			break;

		case WM_TIMER:
			KillTimer(hwnd, MYTIMER);
			iPaintFlag++;
			if (iPaintFlag > 7)
				iPaintFlag = 0;
			
			rcTemp.left = rcTemp.right;
			rcTemp.bottom = rc.bottom;
			rcTemp.top = rc.top;
			rcTemp.right = rcTemp.right + rc.right / 8;

			
			InvalidateRect(hwnd, NULL, false);
			SetTimer(hwnd, MYTIMER, 1000, NULL);
			break;

		case WM_PAINT:
			
			GetClientRect(hwnd, &rc);
			
			
			
						

			hdc = BeginPaint(hwnd, &ps);

			/*switch (iPaintFlag)
			{
				case 1:
					hBrush = CreateSolidBrush(RGB(255, 0, 0));
					SelectObject(hdc, hBrush);
					FillRect(hdc, &rc, hBrush);
					break;
				case 2:
					hBrush = CreateSolidBrush(RGB(0, 255, 0));
					SelectObject(hdc, hBrush);
					FillRect(hdc, &rc, hBrush);
					break;
				case 3:
					hBrush = CreateSolidBrush(RGB(0, 0, 255));
					SelectObject(hdc, hBrush);
					FillRect(hdc, &rc, hBrush);
					break;
				case 4:
					hBrush = CreateSolidBrush(RGB(0, 255, 255));
					SelectObject(hdc, hBrush);
					FillRect(hdc, &rc, hBrush);
					break;
				case 5:
					hBrush = CreateSolidBrush(RGB(255, 0, 255));
					SelectObject(hdc, hBrush);
					FillRect(hdc, &rc, hBrush);
					break;
				case 6:
					hBrush = CreateSolidBrush(RGB(255,255, 0));
					SelectObject(hdc, hBrush);
					FillRect(hdc, &rc, hBrush);
					break;
				case 7:
					hBrush = CreateSolidBrush(RGB(255, 255, 255));
					SelectObject(hdc, hBrush);
					FillRect(hdc, &rc, hBrush);
					break;
				case 0:
				default:
					hBrush = CreateSolidBrush(RGB(0, 0, 0));
					SelectObject(hdc, hBrush);
					FillRect(hdc, &rc, hBrush);
					break;

			}*/

			switch (iPaintFlag)
			{
			case 1:
				hBrush = CreateSolidBrush(RGB(255, 0, 0));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rcTemp, hBrush);
				break;
			case 2:
				hBrush = CreateSolidBrush(RGB(0, 255, 0));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rcTemp, hBrush);
				break;
			case 3:
				hBrush = CreateSolidBrush(RGB(0, 0, 255));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rcTemp, hBrush);
				break;
			case 4:
				hBrush = CreateSolidBrush(RGB(0, 255, 255));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rcTemp, hBrush);
				break;
			case 5:
				hBrush = CreateSolidBrush(RGB(255, 0, 255));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rcTemp, hBrush);
				break;
			case 6:
				hBrush = CreateSolidBrush(RGB(255, 255, 0));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rcTemp, hBrush);
				break;
			case 7:
				hBrush = CreateSolidBrush(RGB(255, 255, 255));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rcTemp, hBrush);
				break;
			case 0:
			default:
				hBrush = CreateSolidBrush(RGB(0, 0, 0));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rcTemp, hBrush);
				break;

			}

			break;
		
		case WM_DESTROY:
			PostQuitMessage(0);
			break;


	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}





