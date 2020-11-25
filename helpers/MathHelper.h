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

        #pragma region functionality: general
        vector<vector<double>> get_shape(int x_size, int y_size)
        {
            vector<vector<double>> output_vector(x_size);

            for (int i = 0; i < x_size; i++)
            {
                vector<double> temp_vector(y_size);
                for (int j = 0; j < y_size; j++)
                {
                    temp_vector[j] = 0.0;
                }
                output_vector[i] = temp_vector;
            }

            return output_vector;
        }

        vector<vector<double>> matrix_multiplication(vector<vector<double>> input_vector_one, vector<vector<double>> input_vector_two)
        {
            vector<vector<double>> output_vector;
            return output_vector;
        }

        void matrix_scalar_multiplication(double scalar, vector<vector<double>> input_vector_one)
        {
            for (int i = 0; i < input_vector_one.size(); i++)
            {
                for (int j = 0; j < input_vector_one[i].size(); j++)
                {
                    input_vector_one[i][j] = input_vector_one[i][j] * scalar;
                }
            }
        }
        #pragma endregion
        
        #pragma region testing
        void test()
        {
            cout << "\tMathHelper\t\t- Starting class testing\n";

            this->get_shape(3, 3);

            cout << "\tMathHelper\t\t- Testing Successful\n";
        }
        #pragma endregion
};

#endif