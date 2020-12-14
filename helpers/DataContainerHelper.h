#ifndef DATACONTAINERHELPER_H
#define DATACONTAINERHELPER_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class DataContainerHelper
{
    private:
        vector<string> read_text_file(string file_location)
        {
            string temporary_string;
            vector<string> output_vector;
            ifstream input_stream(file_location);

            while (getline(input_stream, temporary_string))
            {
                output_vector.push_back(temporary_string);
            }

            input_stream.close();
            return output_vector;
        }

        bool is_file_empty(vector<string> file_contents)
        {
            if (file_contents.size() <= 0)
            {
                return true;
            }
            return false;
        }

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
        bool import_data_from_text_file(string folder_location)
        {
            vector<string> dataset_meta_data = this->read_text_file(folder_location + "\\meta_data.txt");
            vector<string> dataset_intputs = this->read_text_file(folder_location + "\\inputs.txt");
            vector<string> dataset_outputs = this->read_text_file(folder_location + "\\outputs.txt");
            
            if (this->is_file_empty(dataset_meta_data) || this->is_file_empty(dataset_intputs) || this->is_file_empty(dataset_outputs))
            {
                cout << "uh oh!\n";
            } else
            {
                cout << "yay\n";
            }
            
            
            

            //  STEP 0: Check if folder exists
            //  step 1: Check if inputs, outputs, and meta-data files exist
                //  step 1.1: If files don't exist, throw new exception

            //  step 2: import meta data and save to this
            //  step 3: import inputs
                //  step 3.1: ensure inputs conform to meta-data

            //  step 4: import outputs
                //  step 4.1: ensure outputs conform to meta-data

            return true;
        }

        bool export_data_to_text_file(string folder_location)
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
