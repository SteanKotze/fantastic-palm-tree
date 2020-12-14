#include <iostream>
#include "controllers/surrogates/AnnieController.h"
#include "helpers/DataContainerHelper.h"

#include <time.h>
using namespace std;

int main() 
{
    srand(time(NULL));
    
    AnnieController annie;
    annie.test();

    DataContainerHelper data_container;
    data_container.import_data_from_text_file(".\\data\\datasets\\2x - Crane Controller");
    for (int i = 0; i < data_container.inputs.size(); i++)
    {
        vector<double> temp = data_container.inputs[i];
        for (int j = 0; j < temp.size(); j++)
        {
            if (j != temp.size() - 1)
            {
                cout << temp[j] << " , ";
            } else
            {
                cout << temp[j];
            }
            
        }
        cout << "\n";
    }

    int i;
    cin >> i;
    
    return 0;
}