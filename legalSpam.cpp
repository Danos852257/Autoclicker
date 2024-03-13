#include <Windows.h>
#include <iostream>
#include <random>

int main(){
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,2);
    std::uniform_int_distribution<int> distribution1(3, 10);
    std::uniform_int_distribution<int> distribution2(8, 57);
    std::uniform_int_distribution<int> distribution3(10, 113);
    int rand;
    int rand1;
    while(true){
        if(GetAsyncKeyState(27) & 0x8000){
            return 0;
        }
        rand = dist(rng);
        if(rand == 0){
            rand1 = distribution1(rng);
        }
        if(rand == 1){
            rand1 = distribution2(rng);
        }
        if(rand == 2){
            rand1 = distribution3(rng);
        }
        if(GetAsyncKeyState('R') & 0x8000){
            Sleep(rand1);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            std::cout << rand1 << std::endl;
        }
    }
    return 0;
}