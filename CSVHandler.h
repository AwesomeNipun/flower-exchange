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

public:
    static vector<Order> readCSV(const string &filename);
    static void writeToCSV(const string &filename, vector<Order> &orders);
};


#endif //FLOWER_EXCHANGE_CSVHANDLER_H
