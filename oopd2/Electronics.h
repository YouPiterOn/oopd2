#pragma once
#pragma once
#include "Product.h"

class Electronics : public Product {
private:
    std::string _brand = "";
    std::string _model = "";
    int _powerConsumption = 0;

public:
    Electronics(std::string name, float price, int quantityInStock, std::string brand, std::string model, int powerConsumption);

    std::string getBrand();
    std::string getModel();
    int getPowerConsumption();

    void setBrand(std::string brand);
    void setModel(std::string model);
    void setPowerConsumption(int powerConsumption);
};
