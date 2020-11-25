#include <iostream>
#include "helpers/ApplicationHelper.h"
#include "helpers/MathHelper.h"

using namespace std;

int main() 
{
    ApplicationHelper application_helper;
    application_helper.test();

    MathHelper meth_helper;
    meth_helper.test();

    int i;
    cin >> i;
    
    return 0;
}