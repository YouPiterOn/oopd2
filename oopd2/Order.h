#pragma once
#include <list>
#include "Product.h"

class Order {
private:
    std::string _orderID = "0";
    std::string _customer = "";
    std::list<Product*> _products;
    float _totalCost = 0;
    bool _orderStatus = false;

    void calculateTotalCost();

public:
    void setOrderId(std::string id) {
        _orderID = id;
    }
    void setCustomer(std::string customer) {
        _customer = customer;
    }
    std::string getOrderId() {
        return _orderID;
    }
    std::string getCustomer() {
        return _customer;
    }
    int getTotalCost() {
        return _totalCost;
    }
    void Print();
    void addProduct(Product* product);
    void changeStatus();
};
