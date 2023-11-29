#pragma once
#include "Product.h"

class Clothing : public Product {
private:
    std::string _size = "";
    std::string _color = "";
    std::string _material = "";

public:
    Clothing(std::string name, float price, int quantityInStock, std::string size, std::string color, std::string material);

    std::string getSize();
    std::string getColor();
    std::string getMaterial();

    void setSize(std::string size);
    void setColor(std::string color);
    void setMaterial(std::string material);
};

