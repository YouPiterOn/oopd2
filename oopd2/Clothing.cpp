#include "Clothing.h"

Clothing::Clothing(std::string name, int price, int quantityInStock, std::string size, std::string color, std::string material) {
    setName(name);
    setPrice(price);
    setQuantityInStock(quantityInStock);
    setSize(size);
    setColor(color);
    setMaterial(material);
}

std::string Clothing::getSize() {
    return _size;
}

std::string Clothing::getColor() {
    return _color;
}

std::string Clothing::getMaterial() {
    return _material;
}

void Clothing::setSize(std::string size) {
    _size = size;
}

void Clothing::setColor(std::string color) {
    _color = color;
}

void Clothing::setMaterial(std::string material) {
    _material = material;
}
