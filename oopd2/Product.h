#pragma once
#pragma once
#include <iostream>

class Product {
private:
    int _price;
    std::string _name;
    std::string _productID;
    int _quantityInStock;

public:
    int getPrice();
    std::string getName();
    std::string getProductID();
    int getQuantityInStock();

    void setPrice(int price);
    void setName(std::string name);
    void setProductID(std::string productID);
    void setQuantityInStock(int quantityInStock);

    int getTotalCost();
};
