//headers
#include "stdafx.h"
#include<windows.h>



//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	
	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	ATOM atom = RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		TEXT("My App"),
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

//using WM_KEYDOWN with NUMPAD keys from 0 to 7
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH hBrush;
	RECT rc;
	TCHAR str[255]; 
	static int iPaintFlag = 0;
	switch (iMsg) {

	case WM_CREATE:
		wsprintf(str, TEXT("WM_Create is Arrived"));
		MessageBox(hwnd, str, TEXT("MESSAGE"), MB_OK);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
			
			case VK_NUMPAD1:
				wsprintf(str, TEXT("1 was Pressed on Numpad"));
				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
				iPaintFlag = 1;
				InvalidateRect(hwnd, NULL, NULL);
				break;

			case VK_NUMPAD2:
				wsprintf(str, TEXT("2 was Pressed on Numpad"));
				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
				iPaintFlag = 2;
				InvalidateRect(hwnd, NULL, NULL);
				break;
							   			

			case VK_NUMPAD3:
				wsprintf(str,TEXT("3 was Pressed on Numpad"));
				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
				iPaintFlag = 3;
				InvalidateRect(hwnd, NULL, NULL);
				break;

			case VK_NUMPAD4:
				wsprintf(str, TEXT("4 was Pressed on Numpad"));
				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
				iPaintFlag = 4;
				InvalidateRect(hwnd, NULL, NULL);
				break;

			case VK_NUMPAD5:
				wsprintf(str, TEXT("5 was Pressed on Numpad"));
				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
				iPaintFlag = 5;
				InvalidateRect(hwnd, NULL, NULL);
				break;

			case VK_NUMPAD6:
				wsprintf(str, TEXT("6 was Pressed on Numpad"));
				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
				iPaintFlag = 6;
				InvalidateRect(hwnd, NULL, NULL);
				break;

			case VK_NUMPAD7:
				wsprintf(str, TEXT("7 was Pressed on Numpad"));
				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
				iPaintFlag = 7;
				InvalidateRect(hwnd, NULL, NULL);
				break;


			case VK_NUMPAD0:
			default:
				wsprintf(str, TEXT("0 was Pressed on Numpad"));
				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
				iPaintFlag = 0;
				InvalidateRect(hwnd, NULL, NULL);
				break;
			
		}
	break;

	case WM_PAINT:
		GetClientRect(hwnd, &rc);

		hdc = BeginPaint(hwnd, &ps);

		switch (iPaintFlag) {
		
		case 0:
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc, hBrush);
			break;

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
			hBrush = CreateSolidBrush(RGB(0,255, 255));
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

		}
		
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));

}


/*using WM_CHAR with keys RGBCMYKW*/
//using WM_CHAR
//LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
//	
//	HDC hdc;
//	PAINTSTRUCT ps;
//	HBRUSH hBrush;
//	RECT rc;
//	TCHAR str[255];
//	static int iPaintFlag = 0;
//	switch (iMsg) {
//
//	case WM_CREATE:
//		wsprintf(str, TEXT("WM_Create is Arrived"));
//		MessageBox(hwnd, str, TEXT("MESSAGE"), MB_OK);
//		break;
//
//	case WM_CHAR:
//		switch (LOWORD(wParam))
//		{
//			case 'r':
//			case 'R':
//				wsprintf(str, TEXT("r or R was Pressed"));
//				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
//				iPaintFlag = 1;
//
//				InvalidateRect(hwnd, NULL,false);
//				break;
//			
//			case 'g':
//			case 'G':
//				wsprintf(str, TEXT("g or G was Pressed"));
//				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
//				iPaintFlag = 2;
//
//				InvalidateRect(hwnd, NULL, false);
//				break;
//
//			case 'b':
//			case 'B':
//				wsprintf(str, TEXT("b or B was Pressed"));
//				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
//				iPaintFlag = 3;
//
//				InvalidateRect(hwnd, NULL, false);
//				break;
//
//			case 'c':
//			case 'C':
//				wsprintf(str, TEXT("c or C was Pressed"));
//				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
//				iPaintFlag = 4;
//
//				InvalidateRect(hwnd, NULL, false);
//				break;
//
//			case 'M':
//			case 'm':
//				wsprintf(str, TEXT("m or M was Pressed"));
//				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
//				iPaintFlag = 5;
//
//				InvalidateRect(hwnd, NULL, false);
//				break;
//			
//			case 'y':
//			case 'Y':
//				wsprintf(str, TEXT("y or Y was Pressed"));
//				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
//				iPaintFlag = 6;
//
//				InvalidateRect(hwnd, NULL, false);
//				break;
//
//			case 'w':
//			case 'W':
//				wsprintf(str, TEXT("w or W was Pressed"));
//				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
//				iPaintFlag = 7;
//
//				InvalidateRect(hwnd, NULL, false);
//				break;
//
//			case 'k':
//			case 'K':
//			default:
//				wsprintf(str, TEXT("k or K was Pressed"));
//				MessageBox(hwnd, str, TEXT("Message"), MB_OK);
//				iPaintFlag = 0;
//				InvalidateRect(hwnd, NULL, false);
//				break;
//		}
//		break;
//
//	case WM_PAINT:
//		GetClientRect(hwnd, &rc);
//
//		hdc = BeginPaint(hwnd, &ps);
//
//		switch (iPaintFlag) 
//		{
//		
//			case 0:
//				hBrush = CreateSolidBrush(RGB(0, 0, 0)); //black
//				SelectObject(hdc, hBrush);
//				FillRect(hdc, &rc, hBrush);
//				break;
//
//			case 1:
//			
//				hBrush = CreateSolidBrush(RGB(255, 0, 0)); //red
//				SelectObject(hdc, hBrush);
//				FillRect(hdc, &rc, hBrush);
//				break;
//		
//			case 2:
//			
//				hBrush = CreateSolidBrush(RGB(0, 255, 0)); //green
//				SelectObject(hdc, hBrush);
//				FillRect(hdc, &rc, hBrush);
//				break;
//			
//			case 3:
//				hBrush = CreateSolidBrush(RGB(0, 0, 255)); //blue
//				SelectObject(hdc, hBrush);
//				FillRect(hdc, &rc,hBrush);
//				break;
//
//			case 4:
//				hBrush = CreateSolidBrush(RGB(0, 255, 255)); //cyan
//				SelectObject(hdc, hBrush);
//				FillRect(hdc, &rc, hBrush);
//				break;
//
//			case 5:
//				hBrush = CreateSolidBrush(RGB(255, 0, 255)); //magenta
//				SelectObject(hdc, hBrush);
//				FillRect(hdc, &rc, hBrush);
//				break;
//
//			case 6:
//				hBrush = CreateSolidBrush(RGB(255, 255, 0)); //yellow
//				SelectObject(hdc, hBrush);
//				FillRect(hdc, &rc, hBrush);
//				break;
//
//			case 7:
//				hBrush = CreateSolidBrush(RGB(255,255,255)); //white
//				SelectObject(hdc, hBrush);
//				FillRect(hdc, &rc, hBrush);
//				break;
//
//
//		}
//
//		EndPaint(hwnd, &ps);
//		break;
//
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//
//
//	}
//
//	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
//
//}