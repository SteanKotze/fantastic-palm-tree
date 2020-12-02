#ifndef DATACONTAINERHELPER_H
#define DATACONTAINERHELPER_H

#include <vector>

using namespace std;

class DataContainerHelper
{
    public:
        #pragma region Variables
        //  metadata
        int number_of_requests;
        int number_of_unique_outputs;

        int data_sample_count;

        //  data
        vector<vector<double>> inputs;
        vector<vector<double>> outputs;
        vector<vector<double>> used_inputs;
        vector<vector<double>> used_outputs;

        //  other
        bool output_is_active;
        #pragma endregion

        #pragma region Functionality: Constructors and Destructors
        DataContainerHelper()
        {
            this->number_of_requests = 0;
            this-> number_of_unique_outputs = 0;
            this->data_sample_count = 0;
            this->output_is_active = true;
        }
        #pragma endregion

        #pragma region Functionality: Imports and Exports
        bool import_data()
        {
            return true;
        }

        bool import_data_from_text_file()
        {
            return true;
        }

        bool export_data()
        {
            return true;
        }

        void serialize()
        {
            return;
        }

        void unserialize()
        {
            return;
        }
        #pragma endregion

        #pragma region Functionality: Gets
        int get_dataset_total_sample_count()
        {
            return 0;
        }

        int get_dataset_current_sample_count()
        {
            return 0;
        }

        int get_dataset_input_width()
        {
            return 0;
        }

        int get_dataset_output_width()
        {
            return 0;
        }

        void get_dataset_input_euclidian_distance()
        {
            return;
        }

        void get_input_and_output_at_index()
        {
            return;
        }

        void get_random_input_and_output()
        {
            return;
        }
        #pragma endregion

        #pragma region Functionality: Data Manipulation
        void reset_dataset()
        {
            return;
        }

        void split_dataset()
        {
            // should be able to specify split size
            return;
        }

        void pop_input_and_output_at_index()
        {
            return;
        }

        void insert_input_and_output_data_sample()
        {
            return;
        }
        #pragma endregion

        #pragma region Functionality: General
        void test()
        {
            //
        }
        #pragma endregion
};

#endif
