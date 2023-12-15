//
// Created by Nipun Pramuditha on 12/15/2023.
//

#ifndef FLOWER_EXCHANGE_VALIDATOR_H
#define FLOWER_EXCHANGE_VALIDATOR_H

#include "Order.h"
#include <vector>

using namespace std;

class Validator {
    public:
        static void validateOrder(vector<Order> &orders);
    private:
        static const int MIN_QUANTITY = 10;
        static const int MAX_QUANTITY = 1000;

        static bool validateClientOrderId(const string &clientOrderId);

        static bool validateInstrument(const string &instrument);

        static bool validateSide(int side);

        static bool validatePrice(double price);

        static bool validateQuantity(int quantity);
};


#endif //FLOWER_EXCHANGE_VALIDATOR_H
