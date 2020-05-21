#ifndef ANNIE_H
#define ANNIE_H

#include <iostream>
#include <vector>

using namespace std;

class Annie
{
    private:
        #pragma region Variables

        vector<float> v_nodes;
        vector<float> v_weights;
        vector<float> v_drop_out;
        vector<float> v_bias_nodes;
        vector<float> v_nodes_average;
        vector<float> v_weights_momentum;
        vector<float> v_nodes_pre_activation;

        float f_bias;
        float f_lambda_1;
        float f_lambda_2;
        float f_momentum;
        float f_weight_decay;
        float f_weight_range;
        float f_learning_rate;
        float f_input_drop_out;
        float f_output_drop_out;
        float f_accuracy_requirement;

        int i_epochs;
        int i_password;
        int i_batch_size;
        int i_input_width;
        int i_hidden_width;
        int i_output_width;
        int i_hidden_length;
        int i_iterations_child;
        int i_fitness_sample_size;
        int i_activation_function;
        int i_accuracy_sample_size;

        bool b_bias;
        bool b_momentum;
        bool b_allow_testing;

        #pragma endregion

    public:
        #pragma region Variables
        
        bool b_L1;
        bool b_L2;
        bool b_output;
        bool b_is_child;
        bool b_drop_out;
        bool b_is_fertile;
        bool b_is_classifier;
        bool b_noise_injection;

        #pragma endregion

        #pragma region Functions

        Annie()
        {
            cout << "Annie initialized\n";
        }

        void test()
        {
            cout << "\tTest success\n";
        }

        #pragma endregion

};

#endif