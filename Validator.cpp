//
// Created by Nipun Pramuditha on 12/15/2023.
//

#include "Validator.h"

void Validator::validateOrder(vector<Order> &orders){
    for (size_t i = 0; i < orders.size(); i++) {
        if(!validateClientOrderId(orders[i].getClientOrderID())){
            orders[i].setStatus("Reject");
            orders[i].setReason("Invalid Client Order ID");
        } else if (!validateInstrument(orders[i].getInstrument())){
            orders[i].setStatus("Reject");
            orders[i].setReason("Invalid Instrument");
        } else if (!validateSide(orders[i].getSide())){
            orders[i].setStatus("Reject");
            orders[i].setReason("Invalid Side");
        } else if (!validatePrice(orders[i].getPrice())){
            orders[i].setStatus("Reject");
            orders[i].setReason("Invalid Price");
        } else if (!validateQuantity(orders[i].getQuantity())){
            orders[i].setStatus("Reject");
            orders[i].setReason("Invalid Quantity");
        } else {
            orders[i].setStatus("Accept");
            orders[i].setReason("");
        }
    }
}

// check if the Client Order ID is empty
bool Validator::validateClientOrderId(const string &clientOrderId) {
    return (!clientOrderId.empty());
}

// check if the instruments are one of the defined 5 instruments
bool Validator::validateInstrument(const string &instrument) {
    return (instrument == "Rose" || instrument == "Lavender" || instrument == "Lotus" || instrument == "Tulip" || instrument == "Orchid");
}

//check if the side is either one of Buy[1] or Sell[2]
bool Validator::validateSide(int side) {
    return (side == 1 || side == 2);
}

// check if the price is a positive value
bool Validator::validatePrice(double price) {
    return (price>0);
}

// check if the quantity is a multiple of 10
// check if the quantity is within the defined range
bool Validator::validateQuantity(int quantity) {
    if (quantity % 10 != 0){
        return false;
    }
    return quantity >= MIN_QUANTITY && quantity <= MAX_QUANTITY;
}