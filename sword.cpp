#include <Windows.h>
#include <iostream>

int main(){
    bool x = false;
    while(true){
        if(x){
            Sleep(625);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if(GetAsyncKeyState('Q') & 0x8000 || GetAsyncKeyState(27)){
            break;
        }
        if(GetAsyncKeyState('R') & 0x8000 && !x){
            x = true;
        }
        if(GetAsyncKeyState('R') & 0x8000 && x){
            x = false;
        }
    }
    return 0;
}