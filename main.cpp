//
// Created by Nipun Pramuditha on 12/15/2023.
//


#include <iostream>
using namespace std;
#include "ExchangeApp.h"

int main()
{
    string filename = R"(..\Inputs\example_1.csv)";
    string output = R"(..\Outputs\example_1.csv)";
    ExchangeApp::execute(filename, output);

    return 0;
}
