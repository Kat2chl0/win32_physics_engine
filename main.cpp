#include <windows.h>
#include <iostream>
#include "Window.hpp"

int main(){
HWND Window = Create_Window(CW_USEDEFAULT, CW_USEDEFAULT, L"Physik Engine");
if(Window == NULL){
    return -1;
}
MSG msg = { };
while (GetMessage(&msg, NULL, 0, 0)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
}