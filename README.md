# win32_physics_engine
Prototype physics engine in C++ using only Windows API (windows.h) 

# What does it current do?
- Opens a UNICODE window (trough `CreateWindowExW`)
- Has a rectangle (`RECT`) which you can move with arrowkeys
- can draw shapes trough `WM_PAINT` with hcd and PAINTSTRUCT
- custome colors trough `HBRUSH`

# What comes in the future ? 
- Gravity and 3D Objekts
- Collision detection with respons
- Real physical behaviors like splashing water

  
## Build & Run
Compile using any Windows C++ compiler (e.g., MinGW / `g++` or MSVC):

```bash
g++ main.cpp -o engine.exe -lgdi32 -luser32
```
```
its also my first real project in C++ 
