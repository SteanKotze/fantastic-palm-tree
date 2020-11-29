#include <iostream>
#include "controllers/surrogates/AnnieController.h"
#include "helpers/ActivationFunctionHelper.h"
#include "helpers/ApplicationHelper.h"
#include "helpers/MathHelper.h"

#include <time.h>
using namespace std;

int main() 
{
    srand(time(NULL));
    
    AnnieController annie;
    annie.test();

    int i;
    cin >> i;
    
    return 0;
}