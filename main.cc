#include <iostream>
#include "helpers/ApplicationHelper.h"
#include "helpers/MathHelper.h"

#include <time.h>
using namespace std;

int main() 
{
    srand(time(NULL));
    
    ApplicationHelper application_helper;
    application_helper.test();

    MathHelper meth_helper;
    meth_helper.test();

    int i;
    cin >> i;
    
    return 0;
}