#ifndef ANNIE_H
#define ANNIE_H

#include <iostream>
#include <vector>

using namespace std;

class Annie
{
    private:
        //  VARIABLES
        vector<float> v_bias_nodes;
        vector<float> v_drop_out;
        vector<float> v_nodes;
        vector<float> v_nodes_average;
        vector<float> v_nodes_pre_activation;
        vector<float> v_weights;
        vector<float> v_weights_momentum;

        float f_accuracy_requirement;
        float f_bias;
        float f_input_drop_out;
        float f_lambda_1;
        float f_lambda_2;
        float f_learning_rate;
        float f_momentum;
        float f_output_drop_out;
        float f_weight_decay;
        float f_weight_range;

        int i_accuracy_sample_size;
        int i_activation_function;
        int i_batch_size;
        int i_epochs;
        int i_fitness_sample_size;
        int i_hidden_length;
        int i_hidden_width;
        int i_input_width;
        int i_iterations_child;
        int i_output_width;
        int i_password;

        bool b_allow_testing;
        bool b_bias;
        bool b_momentum;

    public:
        void test()
        {
            cout << "I'm a cute neural network, bitch\n";
        }
};

#endif