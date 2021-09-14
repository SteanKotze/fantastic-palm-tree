#ifndef ACTIVATIONFUNCTIONHELPER_H
#define ACTIVATIONFUNCTIONHELPER_H

#include <iostream>
#include <math.h>

using namespace std;

class ActivationFunctionHelper
{
    public:
        #pragma region  --- Variables ---
        //  --- linear ---
        double linear_c;
        double linear_m;
        //  --- logistic ---
        double logistic_c;
        double logistic_m;
        double logistic_max;
        //  --- tanH ---
        double tanh_c;
        double tanh_m;
        //  --- relU ---
        double relu_c;
        double relu_cut_off;
        //  --- leaky relU ---
        double leaky_relu_pos_c;
        double leaky_relu_neg_c;
        double leaky_relu_cut_off;
        //  --- elU ---
        double elu_linear_c;
        double elu_exponential_c;
        double elu_cut_off;
        //  --- srelU ---
        double srelu_lower_c;
        double srelu_center_c;
        double srelu_upper_c;
        double srelu_lower_boundary;
        double srelu_upper_boundary;

        ActivationFunctionHelper()
        {
            this->linear_c = 0.0;
            this->linear_m = 1.0;
            this->logistic_c = 0.0;
            this->logistic_m = 1.0;
            this->logistic_max = 1.0;
            this->tanh_c = 0.0;
            this->tanh_m = 1.0;
            this->relu_c = 1.0;
            this->relu_cut_off = 0.0;
            this->leaky_relu_pos_c = 1.0;
            this->leaky_relu_neg_c = 0.01;
            this->leaky_relu_cut_off = 0.0;
            this->elu_linear_c = 1.0;
            this->elu_exponential_c = 1.0;
            this->elu_cut_off = 0.0;
            this->srelu_lower_c = 0.1;
            this->srelu_center_c = 1.0;
            this->srelu_upper_c = 0.1;
            this->srelu_lower_boundary = -1.0;
            this->srelu_upper_boundary = 1.0;
        }
        #pragma endregion

        #pragma region  --- Functionality ---
        double get_activation_value(int activation_function, double x)
        {
            switch (activation_function)
            {
                case 0:
                    return this->linear(x);
                case 1:
                    return this->logistic(x);
                case 2:
                    return this->tanH(x);
                case 3:
                    return this->relu(x);
                case 4:
                    return this->leaky_relu(x);
                case 5:
                    return this->elu(x);
                case 6:
                    return this->srelu(x);
                default:
                    return 0.0;
            }
        }

        double get_activation_derivative_value(int activation_function, double x)
        {
            switch (activation_function)
            {
                case 0:
                    return this->linear_derivative(x);
                case 1:
                    return this->logistic_derivative(x);
                case 2:
                    return this->tanH_derivative(x);
                case 3:
                    return this->relu_derivative(x);
                case 4:
                    return this->leaky_relu_derivative(x);
                case 5:
                    return this->elu_derivative(x);
                case 6:
                    return this->srelu_derivative(x);
                default:
                    return 0.0;
            }
        }

        double linear(double x)
        {
            return this->linear(this->linear_c, this->linear_m, x);
        }

        double linear(double c, double m, double x)
        {
            // y = m.x + c
            return m*x + c;
        }

        double linear_derivative(double x)
        {
            // 'y = m
            return this->linear_c;
        }

        double logistic(double x)
        {
            //  y = 1/(1 + e^(-c.x))
            return this->logistic_max / ( 1.0 + exp( -1.0 * this->logistic_m * (x - this->logistic_c) ) );
        }

        double logistic_derivative(double x)
        {
            //  `y = y(1 -y)
            double output = this->logistic(x);
            return this->logistic_m * output * (1.0 - output);
        }

        double tanH(double x)
        {
            //  y = m.tanh(c.x)
            return this->tanh_m * tanh(this->tanh_c + x);
        }

        double tanH_derivative(double x)
        {
            double output = this->tanH(x);
            return this->tanh_m * (1.0 - output * output);
        }

        double relu(double x)
        {
            if (x >= this->relu_cut_off) return this->relu_c * x;
            return 0.0;
        }

        double relu_derivative(double x)
        {
            if (x >= this->relu_cut_off) return this->relu_c;
            return 0.0;
        }

        double leaky_relu(double x)
        {
            if (x >= this->leaky_relu_cut_off) return this->leaky_relu_pos_c * x;
            return this->leaky_relu_neg_c * x;
        }

        double leaky_relu_derivative(double x)
        {
            if (x >= this->leaky_relu_cut_off) return this->leaky_relu_pos_c;
            return this->leaky_relu_neg_c;            
        }

        double elu(double x)
        {
            if (x >= this->elu_cut_off) return this->elu_linear_c * x;
            return this->elu_exponential_c * (exp(x) - 1.0);
        }

        double elu_derivative(double x)
        {
            if (x >= this->elu_cut_off) return this->elu_linear_c;
            return (this->elu(x) - this->elu_exponential_c);            
        }

        double srelu(double x)
        {
            if (x <= this->srelu_lower_boundary)
            {
                double neg_y_value = this->srelu_center_c * this->srelu_lower_boundary;
                double neg_c = neg_y_value - ( this->srelu_lower_c * this->srelu_lower_boundary );
                return this->srelu_lower_c * x + neg_c;
            } else if (x >= this->srelu_upper_boundary)
            {
                double pos_y_value = this->srelu_center_c * this->srelu_upper_boundary;
                double pos_c = pos_y_value - ( this->srelu_upper_c * this->srelu_upper_boundary );
                return this->srelu_upper_c * x + pos_c;
            } else
            {
                return this->srelu_center_c * x;
            }
        }

        double srelu_derivative(double x)
        {
            if (x <= this->srelu_lower_boundary)
            {
                return this->srelu_lower_c;
            } else if (x >= this->srelu_upper_boundary)
            {
                return this->srelu_upper_c;
            } else
            {
                return this->srelu_center_c;
            }
        }

        void test()
        {
            double input = rand() % 10 + 1;
            cout << "\tActivationFunctionHelper\t- Starting class testing\n";
            cout << "\t\tlinear(" << input << ") = " << this->linear(input) << "\n";
            cout << "\t\tlinear_derivative(" << input << ") =  " << this->linear_derivative(input) << "\n";

            input = rand() % 10 + 1;
            cout << "\t\tlogisitic(" << input << ") =  " << this->logistic(input) << "\n";
            cout << "\t\tlogisitic_derivative(" << input << ") =  " << this->logistic_derivative(input) << "\n";

            input = rand() % 10 + 1;
            cout << "\t\ttanH(" << input << ") =  " << this->tanH(input) << "\n";
            cout << "\t\ttanH_derivative(" << input << ") =  " << this->tanH_derivative(input) << "\n";

            input = rand() % 20 - 10;
            cout << "\t\trelu(" << input << ") =  " << this->relu(input) << "\n";
            cout << "\t\trelu_derivative(" << input << ") =  " << this->relu_derivative(input) << "\n";

            input = rand() % 20 - 10;
            cout << "\t\tleaky_relu(" << input << ") =  " << this->leaky_relu(input) << "\n";
            cout << "\t\tleaky_relu_derivative(" << input << ") =  " << this->leaky_relu_derivative(input) << "\n";

            input = rand() % 20 - 10;
            cout << "\t\telu(" << input << ") =  " << this->elu(input) << "\n";
            cout << "\t\telu_derivative(" << input << ") =  " << this->elu_derivative(input) << "\n";

            input = rand() % 20 - 10;
            cout << "\t\tsrelu(" << input << ") =  " << this->srelu(input) << "\n";
            cout << "\t\tsrelu_derivative(" << input << ") =  " << this->srelu_derivative(input) << "\n";
            cout << "\tActivationFunctionHelper\t- Testing Successful\n\n";
        }
        #pragma endregion
};

#endif
