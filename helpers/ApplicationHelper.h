#ifndef APPLICATIONHELPER_H
#define APPLICATIONHELPER_H

#include <iostream>

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

        void ticks()
        {
            return;
        }

        void time()
        {
            return;
        }
        #pragma endregion

        #pragma region functionality: prints
        void print_2d_array()
        {
            return;
        }
        #pragma endregion

        #pragma region testing
        void test()
        {
            cout << "\tApplicationHelper\t- Starting class testing\n";

            this->nop();
            this->ticks();
            this->time();
            this->print_2d_array();

            cout << "\tApplicationHelper\t- Testing Successful\n\n";
        }
        #pragma endregion
};

#endif