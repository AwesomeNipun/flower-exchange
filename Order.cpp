//
// Created by Nipun Pramuditha on 12/15/2023.
//

#include "Order.h"

// constructor
Order::Order(const string& ClientOrderID, const string& Instrument, int Side, int Quantity, double Price) {

    clientOrderID = ClientOrderID;
    instrument = Instrument;
    side = Side;
    quantity = Quantity;
    price = Price;
}

Order::Order() {}

// setters and getters

const string& Order::getClientOrderID() const {
    return clientOrderID;
}

void Order::setClientOrderID(const string& ClientOrderID) {
    clientOrderID = ClientOrderID;
}

const string& Order::getInstrument() const {
    return instrument;
}

void Order::setInstrument(const string& Instrument) {
    instrument = Instrument;
}

int Order::getSide() const {
    return side;
}

void Order::setSide(int Side) {
    side = Side;
}

int Order::getQuantity() const {
    return quantity;
}

void Order::setQuantity(int Quantity) {
    quantity = Quantity;
}

double Order::getPrice() const {
    return price;
}

void Order::setPrice(double Price) {
    price = Price;
}

const string& Order::getStatus() const {
    return status;
}

void Order::setStatus(const string& Status) {
    status = Status;
}

const string& Order::getTransactTime() const {
    return transactTime;
}

void Order::setTransactTime(const string& TransactTime) {
    transactTime = TransactTime;
}

const string& Order::getReason() const {
    return reason;
}

void Order::setReason(const string& Reason) {
    reason = Reason;
}

const string& Order::getOrderID() const {
    return orderID;
}

void Order::setOrderID(const string& OrderID) {
    orderID = OrderID;
}

const string& Order::getExecStatus() const {
    return execStatus;
}

void Order::setExecStatus(const string& ExecStatus) {
    execStatus = ExecStatus;
}
