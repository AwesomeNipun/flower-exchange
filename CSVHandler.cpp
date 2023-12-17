//
// Created by Nipun Pramuditha on 12/15/2023.
//

#include "CSVHandler.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

vector<Order> CSVHandler::readCSV(const string &filename){
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening the file: " << filename << endl;
        return {};
    }

    vector<Order> orders;
    string line;

    getline(inputFile, line);

    while (getline(inputFile, line)) {
        Order order;

        stringstream ss(line);
        string clientOrderID, instrument, strSide, strQuantity, strPrice;
        int side = 0, quantity =0;
        double price =0.0;

        getline(ss, clientOrderID, ',');
        getline(ss, instrument, ',');
        getline(ss, strSide, ',');
        getline(ss, strQuantity, ',');
        getline(ss, strPrice, ',');

        try {
            if (!(strSide=="")) side = stoi(strSide);
        } catch (std::invalid_argument& e){}

            if (!(strQuantity=="")) quantity = stoi(strQuantity);
            if (!(strPrice=="")) price = stod(strPrice);

        order.setClientOrderID(clientOrderID);
        order.setInstrument(instrument);
        order.setSide(side);
        order.setQuantity(quantity);
        order.setPrice(price);

        orders.push_back(order);
    }
    inputFile.close();
    return orders;
}

void CSVHandler::writeToCSV(const string &filename, vector<Order> &orders) {
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Error opening the file: " << filename << endl;
    }

    outputFile << "ClientOrderID, OrderID, Instrument, Side, Price, Quantity, Status, Reason,TransactionTime" << endl;
    for (size_t i = 0; i < orders.size(); i++) {
        outputFile
                << orders[i].getClientOrderID() << ","
                << orders[i].getOrderID() << ","
                << orders[i].getInstrument() << ","
                << orders[i].getSide() << ","
                << orders[i].getPrice() << ","
                << orders[i].getQuantity() << ","
                << orders[i].getExecStatus() << ","
                << orders[i].getReason() << ","
                << orders[i].getTransactTime() << endl;
    }
    outputFile.close();
}