
#define UNICODE
#define _UNICODE


#include <iostream>
#include <windows.h>
#include "Window.hpp"




RECT myrect = {50, 50, 200, 150};

LRESULT CALLBACK WindProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch(uMsg){
        case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

        case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        
        case WM_PAINT:{
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
            
            FillRect(hdc, &myrect, brush);
            DeleteObject(brush);
            EndPaint(hwnd, &ps);

        }
        return 0;

        case WM_KEYDOWN:{
            if(wParam == VK_RIGHT) OffsetRect(&myrect, 10, 0);
            if(wParam == VK_LEFT) OffsetRect(&myrect, -10, 0);
            if(wParam == VK_DOWN) OffsetRect(&myrect, 0, 10);
            if(wParam == VK_UP) OffsetRect(&myrect, 0, -10);
            InvalidateRect(hwnd, NULL, TRUE);
            return 0;
    }
}
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
    
};

HWND Create_Window(int Width, int Height, const wchar_t* title){
    const wchar_t CLASS_NAME[] = L"Window";
 WNDCLASS wc = { };
 wc.lpfnWndProc = WindProc;
 wc.hInstance = GetModuleHandle(nullptr);
 wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
 wc.lpszClassName = CLASS_NAME;

 RegisterClass(&wc);

 HWND hwnd = CreateWindowExW(0,
    CLASS_NAME,
    title,
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    Width,
    Height,
    NULL,
    NULL,
    GetModuleHandle(nullptr),
    NULL

);
if (hwnd != NULL){
    ShowWindow(hwnd, SW_SHOW);
}

 
return hwnd;
}
