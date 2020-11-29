#ifndef ACTIVATIONFUNCTIONHELPER_H
#define ACTIVATIONFUNCTIONHELPER_H

#include <iostream>
#include <math.h>

using namespace std;

class ActivationFunctionHelper
{
    public:
        #pragma region variables
        double linear_c;
        double logistic_c;
        double tanh_c;
        double tanh_m;
        double relu_c;
        double leaky_relu_pos_c;
        double leaky_relu_neg_c;
        double elu_linear_c;
        double elu_exponential_c;
        double srelu_lower_c;
        double srelu_center_c;
        double srelu_upper_c;
        double srelu_lower_boundary;
        double srelu_upper_boundary;
        #pragma endregion

        #pragma region functionality
        ActivationFunctionHelper()
        {
            this->linear_c = 1.0;
            this->logistic_c = 1.0;
            this->tanh_c = 1.0;
            this->tanh_m = 1.0;
            this->relu_c = 1.0;
            this->leaky_relu_pos_c = 1.0;
            this->leaky_relu_neg_c = 0.01;
            this->elu_linear_c = 1.0;
            this->elu_exponential_c = 1.0;
            this->srelu_lower_c = 0.1;
            this->srelu_center_c = 1.0;
            this->srelu_upper_c = 0.1;
            this->srelu_lower_boundary = -1.0;
            this->srelu_upper_boundary = 1.0;
        }

        double get_activation_value(int activation_function, double x_axis)
        {
            switch (activation_function)
            {
                case 0:
                    return this->linear(x_axis);
                case 1:
                    return this->logistic(x_axis);
                case 2:
                    return this->tanH(x_axis);
                case 3:
                    return this->relu(x_axis);
                case 4:
                    return this->leaky_relu(x_axis);
                case 5:
                    return this->elu(x_axis);
                case 6:
                    return this->srelu(x_axis);
                default:
                    return 0.0;
            }
        }

        double get_activation_derivative_value(int activation_function, double x_axis)
        {
            switch (activation_function)
            {
                case 0:
                    return this->linear_derivative(x_axis);
                case 1:
                    return this->logistic_derivative(x_axis);
                case 2:
                    return this->tanH_derivative(x_axis);
                case 3:
                    return this->relu_derivative(x_axis);
                case 4:
                    return this->leaky_relu_derivative(x_axis);
                case 5:
                    return this->elu_derivative(x_axis);
                case 6:
                    return this->srelu_derivative(x_axis);
                default:
                    return 0.0;
            }
        }

        double linear(double x_axis)
        {
            // y = mx + c
            return this->linear_c * x_axis;
        }

        double linear_derivative(double x_axis)
        {
            // 'y = m
            return this->linear_c;
        }

        double logistic(double x_axis)
        {
            double output = 1.0 / ( 1.0 + exp(-1.0 * this->logistic_c * x_axis));
            return output;
        }

        double logistic_derivative(double x_axis)
        {
            double output = this->logistic(x_axis);
            output = this->logistic_c * output * (1.0 - output);
            return output;
        }

        double tanH(double x_axis)
        {
            return this->tanh_m * tanh(this->tanh_c * x_axis);
        }

        double tanH_derivative(double x_axis)
        {
            double output = this->tanH(x_axis);
            output = this->tanh_m * this->tanh_c * (1.0 - output * output);
            return output;
        }

        double relu(double x_axis)
        {
            if (x_axis >= 0)
            {
                return this->relu_c * x_axis;
            } else
            {
                return 0.0;
            }
        }

        double relu_derivative(double x_axis)
        {
            if (x_axis >= 0)
            {
                return this->relu_c;
            } else
            {
                return 0.0;
            }
        }

        double leaky_relu(double x_axis)
        {
            if (x_axis >= 0)
            {
                return this->leaky_relu_pos_c * x_axis;
            } else
            {
                return this->leaky_relu_neg_c * x_axis;
            }
        }

        double leaky_relu_derivative(double x_axis)
        {
            if (x_axis >= 0)
            {
                return this->leaky_relu_pos_c;
            } else
            {
                return this->leaky_relu_neg_c;
            }
            
        }

        double elu(double x_axis)
        {
            if (x_axis >= 0)
            {
                return this->elu_linear_c * x_axis;
            } else
            {
                return this->elu_exponential_c * (exp(x_axis) - 1.0);
            }            
        }

        double elu_derivative(double x_axis)
        {
            if (x_axis >= 0)
            {
                return this->elu_linear_c;
            } else
            {
                return (this->elu(x_axis) - this->elu_exponential_c);
            }
            
        }

        double srelu(double x_axis)
        {
            if (x_axis <= this->srelu_lower_boundary)
            {
                double neg_y_value = this->srelu_center_c * this->srelu_lower_boundary;
                double neg_c = neg_y_value - ( this->srelu_lower_c * this->srelu_lower_boundary );
                return this->srelu_lower_c * x_axis + neg_c;
            } else if (x_axis >= this->srelu_upper_boundary)
            {
                double pos_y_value = this->srelu_center_c * this->srelu_upper_boundary;
                double pos_c = pos_y_value - ( this->srelu_upper_c * this->srelu_upper_boundary );
                return this->srelu_upper_c * x_axis + pos_c;
            } else
            {
                return this->srelu_center_c * x_axis;
            }
        }

        double srelu_derivative(double x_axis)
        {
            if (x_axis <= this->srelu_lower_boundary)
            {
                return this->srelu_lower_c;
            } else if (x_axis >= this->srelu_upper_boundary)
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
