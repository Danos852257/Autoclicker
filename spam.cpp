#include <Windows.h>
#include <iostream>

int main(){
    while(true){
        if(GetAsyncKeyState(27) & 0x8000){
            return 0;
        }

        if(GetAsyncKeyState('R') & 0x8000){
            Sleep(5);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
    }
    return 0;
}