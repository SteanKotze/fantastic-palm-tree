#region Imports
import  copy                            as cp
import  json                            as js
import  numpy                           as np
import  os
import  random                          as rn
#endregion

class DatasetImportHelper:
    def __init__(self):
        self.dataset_lower_boundary = None
        self.dataset_upper_boundary = None
        self.dataset_mean = None
        self.dataset_median = None
        
        self.dataset_sample_count = None
        self.number_of_requests = None

        self.inputs = None
        self.used_inputs = None
        self.outputs = None
        self.used_outputs = None
        self.output_classes = None
        self.used_output_classes = None

        self.json_data = None

        return

    def import_data_from_json(self, **kwargs) -> None:
        """
            Description:

                Imports a Data() instance from a previous .json export.

            |\n
            |\n
            |\n
            |\n
            |\n

            Arguments:

                + file_name  = ( str ) The file to import
                    ~ Required

                + is_full_path = ( bool ) Flag to specify if full path was used in
                    <file_name> variable

                + extension_included = ( bool ) Flag for if the file extension was added
                    to the <file_name> variable
        """

        #   STEP: Check if file was passed
        if ("file_name" not in kwargs):
            raise Exception("An error occured in DatasetImportHelper.import_data_from_json() -> No file_name argument passed")
        
        try:
            file_path = None
            if ("is_full_path" in kwargs):
                if (kwargs["is_full_path"]):
                    file_path = kwargs["file_name"]

            if (file_path == None):
                file_path = os.path.abspath(".") + "\\data\\datasets\\" + kwargs["file_name"]
                if ("extension_included" in kwargs):
                    if (kwargs["extension_included"] == False):
                        file_path = file_path + ".json"
                        
            with open(file_path) as json_file:
                self.json_data = js.load(json_file)

            if all(key in self.json_data for key in ('data', 'input', 'output', 'class')):
                self.dataset_lower_boundary = self.json_data['data']['lower']
                self.dataset_upper_boundary = self.json_data['data']['upper']
                self.dataset_mean = self.json_data['data']['mean']
                self.dataset_median = self.json_data['data']['median']

                self.dataset_sample_count = self.json_data['data']['len']
                self.number_of_requests = self.json_data['data']['requests']

                self.inputs = self.json_data['input']['unused']
                self.used_inputs = self.json_data['input']['used']
                self.outputs = self.json_data['output']['unused']
                self.used_outputs = self.json_data['output']['used']
                self.output_classes = self.json_data['class']['unused']
                self.used_output_classes = self.json_data['class']['used']

            else:
                raise Exception("The specified json file did not contain the required key:value pairs. Namely: 'data', 'input', 'outpu', and 'class'")            

        except Exception as ex:
            print("Initial Error: ", ex)
            raise Exception("An error occured in DatasetImportHelper.import_data_from_json() -> Try:Catch")

        return

    def import_data_from_text(self, **kwargs) -> None:
        """
            Description:

                Imports data from a text file.

            |\n
            |\n
            |\n
            |\n
            |\n

            Arguments:

                + file_name  = ( str ) The name of the file to import the data from
                    ~ Required

                + is_full_path = ( bool ) Flag to specify if full path was used in
                    <file_name> variable
        """

        if ("file_name" not in kwargs):
            raise Exception("An error occured in DatasetImportHelper.import_data_from_text() -> No file passed")

        try:
            file_path = None
            if ("is_full_path" in kwargs):
                if (kwargs["is_full_path"]):
                    file_path = kwargs["file_name"]

            if (file_path == None):
                file_path = os.path.abspath(".") + "\\data\\datasets\\" + kwargs["file_name"]

            meta_data = self.__import_data_from_txt__(file_path + "\\meta_data.txt", ":")
            inputs = self.__import_data_from_txt__(file_path + "\\inputs.txt", ",")
            outputs = self.__import_data_from_txt__(file_path + "\\outputs.txt", ",")
            output_classes = self.__import_data_from_txt__(file_path + "\\output_classes.txt", ",")

            if ((len(inputs) == len(outputs)) and (len(inputs))):
                self.inputs = inputs
                self.used_inputs = []
                self.outputs = outputs
                self.used_outputs = []
                self.output_classes = output_classes
                self.used_output_classes = []

            for i in range(0, len(meta_data)):
                if (meta_data[i][0] == 'lower_boundary'):
                    self.dataset_lower_boundary = float(meta_data[i][1])
                
                elif (meta_data[i][0] == 'upper_boundary'):
                    self.dataset_upper_boundary = float(meta_data[i][1])

                elif (meta_data[i][0] == 'mean'):
                    self.dataset_mean = float(meta_data[i][1])

                elif (meta_data[i][0] == 'median'):
                    self.dataset_median = float(meta_data[i][1])

                elif (meta_data[i][0] == 'dataset_sample_count'):
                    self.dataset_sample_count = int(meta_data[i][1])

                elif (meta_data[i][0] == 'number_of_requests'):
                    self.number_of_requests = int(meta_data[i][1])

        except Exception as ex:
            print("Initial error:", ex)
            raise Exception("An error occured in DatasetImportHelper.import_data_from_text() -> Try:Catch")

        return

    def import_data_from_csv(self, **kwargs) -> None:
        return

    def export_data_to_json(self, **kwargs) -> None:
        """
            Description:

                Exports this data container instance to file.

            |\n
            |\n
            |\n
            |\n
            |\n

            Arguments:

                + file_name  = ( str ) The file to import
                    ~ Required

                + is_full_path = ( bool ) Flag to specify if full path was used in
                    <file_name> variable

                + extension_included = ( bool ) Flag for if the file extension was added
                    to the <file_name> variable
        """

        if ("file_name" not in kwargs):
            raise Exception("An error occured in DatasetImportHelper.export_data_to_json() -> No file_name argument passed")

        try:
            file_path = None
            if ("is_full_path" in kwargs):
                if (kwargs["is_full_path"]):
                    file_path = kwargs["file_name"]

            if (file_path == None):
                file_path = os.path.abspath(".") + "\\data\\datasets\\" + kwargs["file_name"]
                if ("extension_included" in kwargs):
                    if (kwargs['extension_included'] == False):
                        sFilePath = sFilePath + ".json"

            if (os.path.exists(file_path) == True):
                raise Exception("An error occured in DatasetImportHelper.exportData -> Step 3: A file with that name already exists")

            #   STEP: Populate the temp dictionary
            output_dictionary = {}
            output_dictionary["data"] = {
                "lower":    self.dataset_lower_boundary,
                "upper":    self.dataset_upper_boundary,
                "mean":     self.dataset_mean,
                "median":   self.dataset_median,
                "len":      self.dataset_sample_count,
                "requests": self.number_of_requests
            }

            output_dictionary["input"] = {
                "used":     self.used_inputs,
                "unused":   self.inputs
            }

            output_dictionary["output"] = {
                "used":     self.used_outputs,
                "unused":   self.outputs
            }

            output_dictionary["class"] = {
                "used":     self.used_output_classes,
                "unused":   self.output_classes
            }

            #   STEP: Create the file
            json_file = open(file_path, "a")
            json_file.close()
            json_file = None

            #   STEP: Open the file
            with open(file_path, "r+") as json_file:
                js.dump(output_dictionary, json_file, indent=4, separators=(", ", " : "))

        except Exception as ex:
            print("Initial Error: ", ex)
            raise Exception("An error occured in DatasetImportHelper.exportData")
        
        return
    
    def export_data_to_text(self, **kwargs) -> None:
        """
            Description:

                Exports this class' data to meta_data.txt, inputs.txt, outputs.txt,
                    and output_classes.txt.

            |\n
            |\n
            |\n
            |\n
            |\n

            Arguments:

                + file_name  = ( str ) The file to import
                    ~ Required

                + is_full_path = ( bool ) Flag to specify if full path was used in
                    <file_name> variable
        """

        if ('file_name' not in kwargs):
            raise Exception("An error occured in DatasetImportHelper.export_data_to_text -> No file name specified")
        
        try:
            file_path = None

            #   STEP: Check full file path
            if ('is_full_path' in kwargs):
                if (kwargs['is_full_path']):
                    file_path = kwargs['file_name']

            if (file_path == None):
                file_path = os.path.abspath(".") + "\\data\\datasets\\" + kwargs['file_name']

            #   STEP: Create required files
            json_file = open(file_path + "\\meta_data.txt", "a")
            json_file.close()
            json_file = open(file_path + "\\inputs.txt", "a")
            json_file.close()
            json_file = open(file_path + "\\outputs.txt", "a")
            json_file.close()
            json_file = open(file_path + "\\output_classes.txt", "a")
            json_file.close()
            
            #   STEP: Write meta_data data
            with open(file_path + "\\meta_data.txt", "r+") as meta_data_file:
                meta_data_file.write("lower_boundary:" + str(self.dataset_lower_boundary) + "\n")
                meta_data_file.write("upper_boundary:" + str(self.dataset_upper_boundary) + "\n")
                meta_data_file.write("mean:" + str(self.dataset_mean) + "\n")
                meta_data_file.write("median:" + str(self.dataset_median) + "\n")
                meta_data_file.write("dataset_sample_count:" + str(self.dataset_sample_count) + "\n")
                meta_data_file.write("number_of_requests:" + str(self.number_of_requests) + "\n")

            #   STEP: Write input data
            with open(file_path + "\\inputs.txt", "r+") as inputs_file:
                for i in range(0, len(self.used_inputs)):
                    self.inputs.append(self.used_inputs[i])

                for i in range(0, len(self.inputs)):
                    output_string = ""
                    for j in range(0, len(self.inputs[i])):
                        output_string += str(self.inputs[i][j])

                        if (j != len(self.inputs[i]) - 1):
                            output_string += ","
                        
                        else:
                            output_string += "\n"

                    inputs_file.write(output_string)

            #   STEP: Write output data
            with open(file_path + "\\outputs.txt", "r+") as outputs_file:
                for i in range(0, len(self.used_outputs)):
                    self.outputs.append(self.used_outputs[i])

                for i in range(0, len(self.outputs)):
                    output_string = ""
                    for j in range(0, len(self.outputs[i])):
                        output_string += str(self.outputs[i][j])

                        if (j != len(self.outputs[i]) - 1):
                            output_string += ","
                        
                        else:
                            output_string += "\n"

                    outputs_file.write(output_string)

            #   STEP: Write output_classes data
            with open(file_path + "\\output_classes.txt", "r+") as output_classes_file:
                for i in range(0, len(self.used_output_classes)):
                    self.output_classes.append(self.used_output_classes[i])

                for i in range(0, len(self.output_classes)):
                    output_string = ""
                    for j in range(0, len(self.output_classes[i])):
                        output_string += str(self.output_classes[i][j])

                        if (j != len(self.output_classes[i]) - 1):
                            output_string += ","
                        
                        else:
                            output_string += "\n"

                output_classes_file.write(output_string)

        except Exception as ex:
            print("Initial Error: ", ex)
            raise Exception("An error occured in DatasetImportHelper.export_data_to_text() -> Try:Catch")

        return 

    def __import_data_from_txt__(self, file_path: str, separator: str) -> list:
        txt_file = None
        data_list = []

        try:
            with open(file_path, "r+") as txt_file:
                txt_data_lines = txt_file.readlines()

            for i in range(0, len(txt_data_lines)):
                current_data_line = txt_data_lines[i]
                current_data_point = ""
                output_data_list = []

                for j in range(0, len(current_data_line)):
                    if (current_data_line[j] == separator):
                        try:
                            output_data_list.append(float(current_data_point.strip('\n')))
                        except:
                            output_data_list.append(current_data_point.strip('\n'))
                        current_data_point = ""

                    else:
                        current_data_point += current_data_line[j]
                
                try:
                    output_data_list.append(float(current_data_point.strip('\n')))
                except:
                    output_data_list.append(current_data_point.strip('\n'))
                data_list.append(output_data_list)

        except Exception as ex:
            print("Initial Error:", ex)
            raise Exception("An error occured in DatasetImportHelper.__import_data_from_txt__()")
        
        finally:
            if (txt_file != None):
                txt_file.close()
                txt_file = None

        return data_list

if (__name__ == "__main__"):
    dataset = DatasetImportHelper()
    dataset.import_data_from_json(file_name="8x - Abalone\\abalone_0.json")
    dataset.export_data_to_text(file_name="8x - Abalone")
