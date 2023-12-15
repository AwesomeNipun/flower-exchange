//
// Created by Nipun Pramuditha on 12/15/2023.
//
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <algorithm>

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
    int side = order.getSide(); // get the side of the order

    if (side == 1) { // buy order
        if (sellOrders.empty()) { // no sell orders, therefore buy order should be added as a passive order
            order.setExecStatus(NEW);
            buyOrders.push_back(order);

            order.setTransactTime(getTimestamp());
            executionReport.addToReport(order);
        }
        else { // if there are existing sell orders, we need to iterate and find if a buy can be done
            int numSellOrders = sellOrders.size();
            double buyPrice = order.getPrice();
            for (size_t i=0; i<numSellOrders; i++){
                Order sellOrder = sellOrders[0];
                double sellPrice = sellOrder.getPrice();
                if (buyPrice >= sellPrice){ // if the sell price is lower than or equal the buy price, the buy can happen
                    int remainQuantity = order.getQuantity() - sellOrder.getQuantity();

                    // remainQuantity > 0 --> buy - partial fill, sell - fill
                    // remainQuantity = 0 --> buy and sell both fill
                    // remainQuantity < 0 --> buy - fill, sell - partial fill
                    if (remainQuantity > 0){
                        // transaction
                        order.setQuantity(sellOrder.getQuantity()); // buy the sell order quantity
                        order.setExecStatus(PFILL);
                        order.setPrice(sellPrice);  // buy for the sell price
                        sellOrder.setExecStatus(FILL);

                        order.setTransactTime(getTimestamp());
                        sellOrder.setTransactTime(getTimestamp());
                        executionReport.addToReport(order);
                        executionReport.addToReport(sellOrder);

                        order.setPrice(buyPrice); // set back the buy price
                        order.setQuantity(remainQuantity);
                        sellOrders.erase(sellOrders.begin());
                        break;
                    }
                    else if (remainQuantity == 0){
                        // transaction
                        order.setExecStatus(FILL);
                        order.setPrice(sellPrice); // buy for the sell price
                        sellOrder.setExecStatus(FILL);

                        order.setTransactTime(getTimestamp());
                        sellOrder.setTransactTime(getTimestamp());
                        executionReport.addToReport(order);
                        executionReport.addToReport(sellOrder);

                        order.setPrice(buyPrice); // set back the buy price
                        sellOrders.erase(sellOrders.begin());
                        break;
                    }
                    else{
                        // transaction
                        order.setExecStatus(FILL);
                        order.setPrice(sellPrice); // buy for the sell price
                        sellOrder.setExecStatus(PFILL);
                        sellOrder.setQuantity(order.getQuantity());

                        order.setTransactTime(getTimestamp());
                        sellOrder.setTransactTime(getTimestamp());
                        executionReport.addToReport(order);
                        executionReport.addToReport(sellOrder);

                        order.setPrice(buyPrice); //set back the buy price
                        sellOrder.setQuantity(-remainQuantity);

                        // this order can go in another iteration to buy more, hence no break
                    }
                }
                else{   // if the sell price is larger than buy price, order cannot be processed at this time

                    if (i > 0) {    // order has been already processed at least once
                        buyOrders.push_back(order);
                        break;
                    }
                    order.setExecStatus(NEW);
                    buyOrders.push_back(order);
                    order.setTransactTime(getTimestamp());
                    executionReport.addToReport(order);
                    break;

                }
            }
        }
        // after execution of an order, we will sort the orders based on the price
        std::sort(buyOrders.begin(), buyOrders.end(), compareBuy);
    }
    else{ // sell order
        if (buyOrders.empty()) {  // no buy orders, therefore buy order should be added as a passive order
            order.setExecStatus(NEW);
            sellOrders.push_back(order);

            order.setTransactTime(getTimestamp());
            executionReport.addToReport(order);
        }
        else { // if there are existing buy orders, we need to iterate and find if a sell can be done
            int numBuyOrders = buyOrders.size();
            double sellPrice = order.getPrice();

            for (size_t i=0; i<numBuyOrders; i++) {
                Order buyOrder = buyOrders[0];
                double buyPrice = buyOrder.getPrice();
                if (sellPrice <=
                    buyPrice) { // if the buy price is greater than or equal the sell price, the sell can happen
                    int remainQuantity = order.getQuantity() - buyOrder.getQuantity();

                    // remainQuantity > 0 --> sell - partial fill, buy - fill
                    // remainQuantity = 0 --> buy and sell both fill
                    // remainQuantity < 0 --> sell - fill, buy - partial fill
                    if (remainQuantity > 0) {
                        // transaction
                        order.setQuantity(buyOrder.getQuantity()); // sell the buy order quantity
                        order.setExecStatus(PFILL);
                        order.setPrice(buyPrice);  // sell for the buy price
                        buyOrder.setExecStatus(FILL);

                        order.setTransactTime(getTimestamp());
                        buyOrder.setTransactTime(getTimestamp());
                        executionReport.addToReport(order);
                        executionReport.addToReport(buyOrder);

                        order.setPrice(sellPrice); // set back the sell price
                        order.setQuantity(remainQuantity);
                        buyOrders.erase(buyOrders.begin());
                        break;
                    } else if (remainQuantity == 0) {
                        // transaction
                        order.setExecStatus(FILL);
                        order.setPrice(buyPrice); // sell for the buy price
                        buyOrder.setExecStatus(FILL);

                        order.setTransactTime(getTimestamp());
                        buyOrder.setTransactTime(getTimestamp());
                        executionReport.addToReport(order);
                        executionReport.addToReport(buyOrder);

                        order.setPrice(sellPrice); // set back the sell price
                        buyOrders.erase(buyOrders.begin());
                        break;
                    } else {
                        // transaction
                        order.setExecStatus(FILL);
                        order.setPrice(buyPrice); // sell for the buy price
                        buyOrder.setExecStatus(PFILL);
                        buyOrder.setQuantity(order.getQuantity());

                        order.setTransactTime(getTimestamp());
                        buyOrder.setTransactTime(getTimestamp());
                        executionReport.addToReport(order);
                        executionReport.addToReport(buyOrder);

                        order.setPrice(sellPrice); //set back the sell price
                        buyOrder.setQuantity(-remainQuantity);

                        // this order can go in another iteration to sell more, hence no break
                    }
                } else {   // if the sell price is larger than buy price, order cannot be processed at this time

                    if (i > 0) {    // order has been already processed at least once
                        sellOrders.push_back(order);
                        break;
                    }
                    order.setExecStatus(NEW);
                    sellOrders.push_back(order);
                    order.setTransactTime(getTimestamp());
                    executionReport.addToReport(order);
                    break;

                }
            }
        }
        // after execution of an order, we will sort the orders based on the price
        std::sort(sellOrders.begin(), sellOrders.end(), compareSell);
    }
}

string OrderBook::getTimestamp() {

    // current date/time based on current system
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Format the time (without millisecond part)
    struct std::tm* timeInfo = std::localtime(&currentTime);

    // desired format
    std::ostringstream oss;
    oss << std::put_time(timeInfo, "%Y%m%d-%H%M%S");

    // Add milliseconds
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    oss << '.' << std::setfill('0') << std::setw(3) << milliseconds.count();
    return oss.str();
}
