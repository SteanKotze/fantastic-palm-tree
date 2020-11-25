#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <vector>

using namespace std;

class MathHelper
{
    private:

    public:
        #pragma region constructors and deconstructors
        MathHelper() {}
        #pragma endregion

        #pragma region functionality
        void get_shape()
        {
            return;
        }

        void round()
        {
            return;
        }

        void transpose()
        {
            return;
        }
        #pragma endregion
        
        #pragma region testing
        void test()
        {
            cout << "\tMathHelper\t\t- Starting class testing\n";

            this->get_shape();
            this->round();
            this->transpose();

            cout << "\tMathHelper\t\t- Testing Successful\n";
        }
        #pragma endregion
};

#endif