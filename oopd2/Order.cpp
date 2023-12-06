#include "Order.h"


void Order::addProduct(Product* product) {
    _products.push_back(product);
    calculateTotalCost();
}

void Order::changeStatus() {
    _orderStatus = !_orderStatus;
}

void Order::calculateTotalCost() {
    _totalCost = 0;
    for (Product* product : _products) {
        _totalCost += product->getPrice();
    }
}

void Order::Print() {
    std::cout << std::endl << _customer << ", ID " << _orderID << std::endl;
    for (Product* product : _products) {
        std::cout << product->getName() << ", $" << product->getPrice() << std::endl;
    }
    std::cout << "Total: " << _totalCost << std::endl;
    if (_orderStatus) {
        std::cout << "Completed" << std::endl;
    }
    else {
        std::cout << "In progress" << std::endl;
    }
}
