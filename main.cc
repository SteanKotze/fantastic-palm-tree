#include <iostream>
#include "helpers/ActivationFunctionHelper.h"
#include "helpers/ApplicationHelper.h"
#include "helpers/MathHelper.h"

#include <time.h>
using namespace std;

int main() 
{
    srand(time(NULL));

    ActivationFunctionHelper activation_functions;
    activation_functions.test();

    int i;
    cin >> i;
    
    return 0;
}