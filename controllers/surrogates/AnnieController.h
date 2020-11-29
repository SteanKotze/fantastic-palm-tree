#ifndef ANNIECONTOLLER_H
#define ANNIECONTOLLER_H

#include <iostream>
#include <vector>

#include "../../helpers/ActivationFunctionHelper.h"

using namespace std;

class AnnieController
{
    private:
        

    public:
        #pragma region variables
        //  layout
        int input_width;
        int output_width;
        int hidden_width;
        int hidden_height;

        double weight_range;
        vector<vector<double>> weights;
        vector<vector<double>> weight_momentums;

        vector<vector<double>> nodes;
        vector<vector<double>> nodes_pre_activation;
        vector<vector<double>> node_averages;

        //  activation function
        int activation_function;

        //  learning rate
        double learning_rate;

        //  momentum
        bool momentum_is_active;
        double momentum;

        //  default training variables
        double accuracy_requirement;
        int number_of_epochs;
        int batch_size;
        int accuracy_test_sample_size;
        int fitness_test_samples_size;
        
        //  bias
        bool bias_is_active;
        double bias;

        //  public variables
        bool output_is_active;
        #pragma endregion

        #pragma region functionality: contructors and destructors
        AnnieController()
        {
            this->weight_range = 1.0;
            this->activation_function = 2;
            this->learning_rate = 0.05;
            this->momentum_is_active = true;
            this->momentum = 0.001;
            this->accuracy_requirement = 0.05;
            this->number_of_epochs = 30;
            this->batch_size = 20;
            this->accuracy_test_sample_size = 150;
            this->fitness_test_samples_size = 15;
            this->bias_is_active = true;
            this->bias = 1.0;
            this->output_is_active = true;
        }
        #pragma endregion

        #pragma region functionality: MVP
        void set_layout()
        {
            // pass dataset
            return;
        }

        void propogate_forward()
        {
            // pass a set of inputs
            return;
        }

        void propogate_backward()
        {
            // pass a set of outputs
            return;
        }

        void train_using_dataset()
        {
            // pass dataset
            /*
                should use propogate_forwards()
                shoudl use propogate_backward()
                should save accuracy results to public variables
                */
            return;
        }
        #pragma endregion

        #pragma region functionality: other
        void test()
        {
            cout << "\tAnnieController\t- Starting class testing\n";
            cout << "\tAnnieController\t- Testing successful\n\n";
        }
        #pragma endregion
};

#endif