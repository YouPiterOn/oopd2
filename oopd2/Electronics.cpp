#include "Electronics.h"

Electronics::Electronics(std::string name, int price, int quantityInStock, std::string brand, std::string model, int powerConsumption) {
    setName(name);
    setPrice(price);
    setQuantityInStock(quantityInStock);
    setBrand(brand);
    setModel(model);
    setPowerConsumption(powerConsumption);
}

std::string Electronics::getBrand() {
    return _brand;
}

std::string Electronics::getModel() {
    return _model;
}

int Electronics::getPowerConsumption() {
    return _powerConsumption;
}

void Electronics::setBrand(std::string brand) {
    _brand = brand;
}

void Electronics::setModel(std::string model) {
    _model = model;
}

void Electronics::setPowerConsumption(int powerConsumption) {
    _powerConsumption = powerConsumption;
}
