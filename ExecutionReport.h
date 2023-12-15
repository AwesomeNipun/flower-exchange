//
// Created by Nipun Pramuditha on 12/15/2023.
//

#ifndef FLOWER_EXCHANGE_EXECUTIONREPORT_H
#define FLOWER_EXCHANGE_EXECUTIONREPORT_H

# include "Order.h"
# include <vector>
using namespace std;

class ExecutionReport {
private:
    vector<Order> executionReport;
public:
    void setExecutionReport(vector<Order> &executions);
    void addToReport(Order order);

    vector<Order> &getExecutionReport();
};


#endif //FLOWER_EXCHANGE_EXECUTIONREPORT_H
