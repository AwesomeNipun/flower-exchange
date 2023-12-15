//
// Created by Nipun Pramuditha on 12/15/2023.
//
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

#include "OrderBook.h"

OrderBook::OrderBook(const string& Instrument) {
    instrument = Instrument;
}

bool OrderBook::compareBuy(Order& od1, Order& od2) {
    return od1.getPrice() > od2.getPrice();
}

bool OrderBook::compareSell(Order& od1, Order& od2) {
    return od1.getPrice() < od2.getPrice();
}

void OrderBook::addOrderToExecutionReport(Order order, ExecutionReport &executionReport) {

}

// TODO : Implement this method correctly
string OrderBook::getTimestamp() {
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}