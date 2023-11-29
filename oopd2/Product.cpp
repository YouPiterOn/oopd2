#include "Product.h"

int Product::getPrice() {
    return _price;
}

std::string Product::getName() {
    return _name;
}

std::string Product::getProductID() {
    return _productID;
}

int Product::getQuantityInStock() {
    return _quantityInStock;
}

void Product::setPrice(int price) {
    _price = price;
}

void Product::setName(std::string name) {
    _name = name;
}

void Product::setProductID(std::string productID) {
    _productID = productID;
}

void Product::setQuantityInStock(int quantityInStock) {
    _quantityInStock = quantityInStock;
}

int Product::getTotalCost() {
    return _quantityInStock * _price;
}
