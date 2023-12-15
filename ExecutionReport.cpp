//
// Created by Nipun Pramuditha on 12/15/2023.
//

#include "ExecutionReport.h"

void ExecutionReport::setExecutionReport(vector<Order> &Executions) {
    ExecutionReport::executionReport = Executions;
}

vector<Order> &ExecutionReport::getExecutionReport()  {
    return executionReport;
}