#pragma once
#pragma once
#include <iostream>

class Product {
private:
    float _price = 0;
    std::string _name = "";
    std::string _productID = "";
    int _quantityInStock= 0;

public:
    virtual ~Product() {}
    float getPrice();
    std::string getName();
    std::string getProductID();
    int getQuantityInStock();

    void setPrice(float price);
    void setName(std::string name);
    void setProductID(std::string productID);
    void setQuantityInStock(int quantityInStock);

    float getTotalCost();

    void Print();
};
