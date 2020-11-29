#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class MathHelper
{
    private:
        bool check_shapes_for_multiplication(vector<vector<double>> input_vector_one, vector<vector<double>> input_vector_two)
        {
            int col = input_vector_one[0].size();
            for (int i = 0; i < input_vector_one.size(); i++)
            {
                if (input_vector_one[i].size() != col)
                {
                    return false;
                }
            }

            col = input_vector_two[0].size();
            for (int i = 0; i < input_vector_two.size(); i++)
            {
                if (input_vector_two[i].size() != col)
                {
                    return false;
                }
            }

            if (input_vector_one[0].size() != input_vector_two.size())
            {
                return false;
            }

            return true;
        }

        double row_times_col(vector<vector<double>> input_vector_one, vector<vector<double>> input_vector_two, int row, int col)
        {
            double output = 0.0;
            for (int i = 0; i < input_vector_one[row].size(); i++)
            {
                output += input_vector_one[row][i] * input_vector_two[i][col];
            }
            return output;
        }

    public:
        #pragma region constructors and deconstructors
        MathHelper() {}
        #pragma endregion

        #pragma region functionality: general
        vector<vector<double>> create_empty_matrix(int x_size, int y_size)
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

        vector<vector<double>> create_random_matrix(int x_size, int y_size)
        {
            vector<vector<double>> output_vector(x_size);
            vector<double> random_values = this->random_double_array(x_size * y_size);

            int double_count = 0;
            for (int i = 0; i < x_size; i++)
            {
                vector<double> temp_vector(y_size);
                for (int j = 0; j < y_size; j++)
                {
                    temp_vector[j] = random_values[double_count];
                    double_count++;
                }
                output_vector[i] = temp_vector;
            }

            return output_vector;
        }

        vector<vector<double>> matrix_multiplication(vector<vector<double>> input_vector_one, vector<vector<double>> input_vector_two)
        {
            if (this->check_shapes_for_multiplication(input_vector_one, input_vector_two) == false)
            {
                throw "yeet";
            }

            vector<vector<double>> output_vector = this->create_empty_matrix(input_vector_one.size(), input_vector_two[0].size());
            for (int i = 0; i < output_vector.size(); i++)
            {
                for (int j = 0; j < output_vector[0].size(); j++)
                {
                    output_vector[i][j] = this->row_times_col(input_vector_one, input_vector_two, i, j);
                }
            }

            return output_vector;
        }

        void matrix_scalar_multiplication(double scalar, vector<vector<double>> &input_vector)
        {
            for (int i = 0; i < input_vector.size(); i++)
            {
                for (int j = 0; j < input_vector[i].size(); j++)
                {
                    input_vector[i][j] *= scalar;
                }
            }
        }

        void print_2d_array(vector<vector<double>> two_dim_vector)
        {
            for (int i = 0; i < two_dim_vector.size(); i++)
            {
                cout << "\t\t";
                for (int j = 0; j < two_dim_vector[i].size(); j++)
                {
                    printf("%.2f", two_dim_vector[i][j]);
                    cout << "\t";
                    //cout << to_string(two_dim_vector[i][j]) << "\t";
                }
                cout << "\n";
            }
        }
        
        vector<double> random_double_array(int count)
        {
            vector<double> output(count);
            for (int i = 0; i < count; i++)
            {
                output[i] =(rand() % 32767 + 1)/32767.0;
            }
            return output;
        }
        #pragma endregion
        
        #pragma region testing
        void test()
        {
            cout << "\tMathHelper\t\t- Starting class testing\n";

            cout << "\t\tMathHelper\t\t - Test 1\n";
            vector<vector<double>> null_vector = this->create_empty_matrix(3, 3);
            for (int i = 0; i < null_vector.size(); i++)
            {
                for (int j = 0; j < null_vector[i].size(); j++)
                {
                    null_vector[i][j] = 1.0;
                }
            }

            this->matrix_scalar_multiplication(3.0, null_vector);
            this->print_2d_array(null_vector); 

            cout << "\n\t\tMathHelper\t\t - Test 2\n";
            vector<vector<double>> d = this->create_empty_matrix(3, 2);
            vector<vector<double>> e = this->create_empty_matrix(2, 4);
            cout << "\t\t";
            if (this->check_shapes_for_multiplication(d, e) == true)
            {
                cout << "true\n";
            } else
            {
                cout << "false\n";
            }
            
            cout << "\n\t\tMathHelper\t\t - Test 3\n";
            vector<vector<double>> f = this->create_random_matrix(3, 3);
            this->print_2d_array(f);

            cout << "\n\t\tMathHelper\t\t - Test 4\n";
            vector<vector<double>> a = this->create_random_matrix(4, 5);
            this->print_2d_array(a);
            cout << "\t\t\tx\n";
            vector<vector<double>> b = this->create_random_matrix(5, 7);
            this->print_2d_array(b);
            cout << "\t\t\t=\n";
            vector<vector<double>> c = this->matrix_multiplication(a, b);
            this->print_2d_array(c);

            cout << "\tMathHelper\t\t- Testing Successful\n\n";
        }
        #pragma endregion
};

#endif