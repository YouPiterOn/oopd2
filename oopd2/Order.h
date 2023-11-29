#pragma once
#include <list>
#include "Product.h"

class Order {
private:
    std::string _orderID;
    std::string _customer;
    std::list<Product> _products;
    float _totalCost;
    bool _orderStatus;

    void calculateTotalCost();

public:
    Order(std::string orderID, std::string customer);

    void addProduct(Product product);
    void changeStatus();
};