#ifndef APPLICATIONHELPER_H
#define APPLICATIONHELPER_H

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

#include "MathHelper.h"

using namespace std;

class ApplicationHelper
{
    private:

    public:
        #pragma region constructors and deconstructors
        ApplicationHelper() {}
        #pragma endregion
        
        #pragma region functionality
        void nop()
        {
            return;
        }

        string ticks()
        {
            return to_string(chrono::system_clock::to_time_t(chrono::system_clock::now()));
        }

        string time()
        {
            std::time_t current_time = std::time(0);
            string current_formatted_time = string(ctime(&current_time));
            return current_formatted_time.erase(current_formatted_time.length() - 1);
        }
        #pragma endregion

        #pragma region testing
        void test()
        {
            cout << "\tApplicationHelper\t- Starting class testing\n";

            this->nop();
            cout << "\t\tApplicationHelper\t- ticks() - " << this->ticks() << "\n";
            cout << "\t\tApplicationHelper\t- time() - " << this->time() << "\n";
            

            cout << "\tApplicationHelper\t- Testing Successful\n\n";
        }
        #pragma endregion
};

#endif