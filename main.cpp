//
// Created by Nipun Pramuditha on 12/15/2023.
//


#include <iostream>
using namespace std;
#include "ExchangeApp.h"

int main()
{

    // for all the examples
//    for (int i = 1; i <= 8; i++) {
//        string filename = R"(..\Inputs\example_)" + to_string(i) + ".csv";
//        string output = R"(..\Outputs\example_)" + to_string(i) + ".csv";
//        ExchangeApp::execute(filename, output);
//    }

    // for a single example

     string filename = R"(..\Inputs\example_6.csv)";
     string output = R"(..\Outputs\example_6.csv)";
     ExchangeApp::execute(filename, output);

    return 0;
}
