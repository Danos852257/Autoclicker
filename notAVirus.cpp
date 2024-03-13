#include <Windows.h>
#include <iostream>
#include <random>

int main(){
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, screenWidth);
    std::uniform_int_distribution<int> distribution1(0, screenHeight);

    while(true){
        int mouseX = distribution(rng);
        int mouseY = distribution1(rng);

        Sleep(100);
        SetCursorPos(mouseX, mouseY);
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

        if(GetAsyncKeyState(27) & 0x8000){
            return 0;
        }
    }


    return 0;
}`