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

        void import_dataset_meta_data(vector<string> dataset_meta_data)
        {
            int update_counter = 0;

            for (int i = 0; i < dataset_meta_data.size(); i++)
            {
                size_t delimiter_position = dataset_meta_data[i].find(":");
                size_t endl_position = dataset_meta_data[i].find("\n");
                string key, value;

                key = dataset_meta_data[i].substr(0, delimiter_position);
                value = dataset_meta_data[i].substr(delimiter_position + 1, endl_position);

                if (key == "dataset_sample_count")
                {
                    this->data_sample_count = stoi(value);
                } else if (key == "number_of_requests")
                {
                    this->number_of_requests = stoi(value);
                }
            }
            return;
        }

        void import_dataset_data(vector<string> data, vector<vector<double>> *unused_data)
        {
            for (int i = 0; i < data.size(); i++)
            {
                unused_data->push_back(this->text_line_to_vector(data[i]));
            }

            if (unused_data->size() != this->data_sample_count)
            {
                throw "Dataset size does not match meta data for dataset.";
            }

            return;
        }

        vector<double> text_line_to_vector(string input_data)
        {
            vector<double> output_vector;
            string data_value = "";

            for(char& data_character : input_data)
            {
                if ((data_character != *",") && (data_character != *"\n"))
                {
                    data_value += data_character;
                } else if (data_character == *",")
                {
                    output_vector.push_back(stof(data_value));
                    data_value = "";
                }
            }
            output_vector.push_back(stof(data_value));

            return output_vector;
        }

        void clear_this()
        {
            this->number_of_requests = 0;
            this->number_of_unique_outputs = 0;
            this->data_sample_count = 0;
            this->output_is_active = true;

            this->inputs.clear();
            this->outputs.clear();
            this->used_inputs.clear();
            this->used_outputs.clear();

            return;
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
            this->number_of_unique_outputs = 0;
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
                return false;
            }

            try
            {
                this->import_dataset_meta_data(dataset_meta_data);
                this->import_dataset_data(dataset_intputs, &this->inputs);
                this->import_dataset_data(dataset_outputs, &this->outputs);
            } catch (...)
            {
                this->clear_this();
                return false;
            }

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
        }
        #pragma endregion
};

#endif
