//
// Created by Nipun Pramuditha on 12/15/2023.
//

#include "ExchangeApp.h"
#include "CSVHandler.h"
#include "Validator.h"
#include "ExecutionReport.h"
#include "OrderBook.h"
#include <string>
#include <vector>

using namespace std;

void ExchangeApp::execute(string inputFile, string outputFile){
    cout << "\n============================\n" << endl;
    cout << "Starting the exchange app...\n" << endl;
    cout << "============================\n" << endl;

    cout << "\nReading CSV files to get the orders..." << endl;
    vector<Order> orders = CSVHandler::readCSV(inputFile);

    Validator::validateOrder(orders);

    ExecutionReport executionReport;

    OrderBook roseOB((string &) "Rose");
    OrderBook lavenderOB((string &) "Lavender");
    OrderBook lotusOB((string &) "Lotus");
    OrderBook tulipOB((string &) "Tulip");
    OrderBook orchidOB((string &) "Orchid");

    cout << "\nProcessing the orders..." << endl;
    for (size_t i = 0; i < orders.size(); i++) {
        string ordID = to_string(i+1);    // Generate a unique order ID for each order
        orders[i].setOrderID("ord" + ordID);
        if (orders[i].getStatus() == "Accept"){
            string instrument = orders[i].getInstrument();
            if (instrument == "Rose") {
                roseOB.addOrderToExecutionReport(orders[i], executionReport);
            } else if (instrument == "Lavender") {
                lavenderOB.addOrderToExecutionReport(orders[i], executionReport);
            } else if (instrument == "Lotus") {
                lotusOB.addOrderToExecutionReport(orders[i], executionReport);
            } else if (instrument == "Tulip") {
                tulipOB.addOrderToExecutionReport(orders[i], executionReport);
            } else if (instrument == "Orchid") {
                orchidOB.addOrderToExecutionReport(orders[i], executionReport);
            }
        } else {
            orders[i].setExecStatus("Reject");
            executionReport.getExecutionReport().push_back(orders[i]);
        }
    }

    cout<< "OrderID   |   ClientOrderID   |   Instrument   |   Side   |   Status   |   Quantity   |   Price   |   Reason   |   TransactionTime" << endl;
    for (size_t i = 0; i < executionReport.getExecutionReport().size(); i++) {
        cout << executionReport.getExecutionReport()[i].getOrderID() << " "<< executionReport.getExecutionReport()[i].getClientOrderID() << " " << executionReport.getExecutionReport()[i].getInstrument() << " " << executionReport.getExecutionReport()[i].getSide() << " " << executionReport.getExecutionReport()[i].getExecStatus() << " " << executionReport.getExecutionReport()[i].getQuantity() << " " << executionReport.getExecutionReport()[i].getPrice() << " " << executionReport.getExecutionReport()[i].getReason() << " " << executionReport.getExecutionReport()[i].getTransactTime() << endl;
    }

    cout << "\nWriting the executed orders to the output CSV file..." << endl;
    CSVHandler::writeToCSV(outputFile, executionReport.getExecutionReport());

    cout << "\n============================\n" << endl;
    cout << "Exchange process completed...\n" << endl;
    cout << "============================\n" << endl;
}