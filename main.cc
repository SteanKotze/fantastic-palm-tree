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

    int i;
    cin >> i;
    
    return 0;
}