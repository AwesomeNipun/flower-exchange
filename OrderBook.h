//
// Created by Nipun Pramuditha on 12/15/2023.
//

#ifndef FLOWER_EXCHANGE_ORDERBOOK_H
#define FLOWER_EXCHANGE_ORDERBOOK_H


#include "Order.h"
#include <vector>
#include "ExecutionReport.h"
using namespace std;

class OrderBook {
private:
    string instrument;
    vector<Order> buyOrders;
    vector<Order> sellOrders;

public:
    OrderBook(const string& instrument);
    static bool compareBuy(Order& od1, Order& od2);
    static bool compareSell(Order& od1, Order& od2);

    string getTimestamp();
    void addOrderToExecutionReport(Order order, ExecutionReport &executionReport);
};


#endif //FLOWER_EXCHANGE_ORDERBOOK_H
