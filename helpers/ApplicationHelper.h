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

        #pragma region functionality: prints
        void print_2d_array(vector<vector<double>> two_dim_vector)
        {
            cout.precision(2);
            for (int i = 0; i < two_dim_vector.size(); i++)
            {
                for (int j = 0; j < two_dim_vector[i].size(); j++)
                {
                    cout << to_string(two_dim_vector[i][j]) << "\t";
                }
                cout << "\n";
            }
            return;
        }
        #pragma endregion

        #pragma region testing
        void test()
        {
            cout << "\tApplicationHelper\t- Starting class testing\n";

            this->nop();
            cout << "\t\tApplicationHelper\t- ticks() - " << this->ticks() << "\n";
            cout << "\t\tApplicationHelper\t- time() - " << this->time() << "\n";
            cout << "\t\tApplicationHelper\t- print_2d_array()\n";
            
            MathHelper meth_helper;
            this->print_2d_array(meth_helper.get_shape(3, 3));

            cout << "\tApplicationHelper\t- Testing Successful\n\n";
        }
        #pragma endregion
};

#endif