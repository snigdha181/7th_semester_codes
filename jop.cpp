#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
void playSound()
{
    std::cout << "\a";
    int main()
    {
        std::cout << "Chant Started...\n" << std::endl;
        int count = 0;
        int value = 0;
        while (true)
        {
            if (value == 108)
            {
                count++;
                std::cout << "\n\n108 reached " << count << " times!\n" << std::endl;
                std::thread soundThread(playSound);
                soundThread.detach();
                value = 0;
            }
            int key = _getch();
            if (key == 13)
            {
                value++;
                std::cout << value << std::endl;
            }
            else
            {
                value = 0;
                count = 0;
                std::cout << "\nThe previous count is reset\nPress enter key to start chanting again" << std::endl;
            }
        }
        return 0;
    }
