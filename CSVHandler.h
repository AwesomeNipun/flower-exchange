//
// Created by Nipun Pramuditha on 12/15/2023.
//

#ifndef FLOWER_EXCHANGE_CSVHANDLER_H
#define FLOWER_EXCHANGE_CSVHANDLER_H

#include "Order.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class CSVHandler {

    static std::vector<Order> readCSV(const std::__cxx11::basic_string<char> &filename);

    static void writeToCSV(const string &filename, vector<Order> &orders);
};


#endif //FLOWER_EXCHANGE_CSVHANDLER_H
