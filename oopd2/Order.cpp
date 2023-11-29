#include "Order.h"

Order::Order(std::string orderID, std::string customer) {
    _orderID = orderID;
    _customer = customer;
    _totalCost = 0;
    _orderStatus = false;
}

void Order::addProduct(Product product) {
    _products.push_back(product);
    calculateTotalCost();
}

void Order::changeStatus() {
    _orderStatus = !_orderStatus;
}

void Order::calculateTotalCost() {
    _totalCost = 0;
    for (Product product : _products) {
        _totalCost += product.getPrice();
    }
}
