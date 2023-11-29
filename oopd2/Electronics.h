#pragma once
#pragma once
#include "Product.h"

class Electronics : public Product {
private:
    std::string _brand;
    std::string _model;
    int _powerConsumption;

public:
    Electronics(std::string name, int price, int quantityInStock, std::string brand, std::string model, int powerConsumption);

    std::string getBrand();
    std::string getModel();
    int getPowerConsumption();

    void setBrand(std::string brand);
    void setModel(std::string model);
    void setPowerConsumption(int powerConsumption);
};
