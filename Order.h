//
// Created by Nipun Pramuditha on 12/15/2023.
//

#ifndef FLOWER_EXCHANGE_ORDER_H
#define FLOWER_EXCHANGE_ORDER_H

#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Order {
private:

    string clientOrderID;
    string instrument;
    int side;
    int quantity;
    double price;
    string status;
    string transactTime;
    string reason;
    string execStatus;
    string orderID;
    // array to store the string values of side, price and quantity
    vector<string> inputStrings;

public:
    Order();
    Order(const string &ClientOrderID, const string &Instrument, int Side, int Quantity, double Price);

    const string &getClientOrderID() const;
    const string &getInstrument() const;
    int getSide() const;
    int getQuantity() const;
    double getPrice() const;
    const string &getStatus() const;
    const string &getTransactTime() const;
    const string &getReason() const;
    const string &getOrderID() const;
    const string &getExecStatus() const;
    vector <string> &getInputStrings();

    void setClientOrderID(const string &ClientOrderID);
    void setInstrument(const string &Instrument);
    void setSide(int Side);
    void setQuantity(int Quantity);
    void setPrice(double Price);
    void setStatus(const string &Status);
    void setTransactTime(const string &TransactTime);
    void setReason(const string &Reason);
    void setOrderID(const string &OrderID);
    void setExecStatus(const string &ExecStatus);
    void setInputStrings(const vector <string> &InputStrings);
};

#endif //FLOWER_EXCHANGE_ORDER_H
