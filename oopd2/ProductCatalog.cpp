#include "ProductCatalog.h"
#include <string>
#include <iostream>

ProductCatalog::ProductCatalog() {}

ProductCatalog::ProductCatalog(std::list<Product>* products) {
    for (auto iter = products->begin(); iter != products->end(); ++iter) {
        Product* product = &*iter;
        addProduct(product);
    }
}

void ProductCatalog::addProduct(Product* product) {
    product->setProductID(std::to_string(idPointer));
    _products.push_back(product);
    idPointer++;
}

Product* ProductCatalog::SearchByName(std::string name) {
    for (Product* product : _products) {
        if (product->getName() == name) {
            return product;
        }
    }
    return nullptr;
}

Product* ProductCatalog::findProduct(std::string productID) {
    for (Product* product : _products) {
        if (product->getProductID() == productID) {
            return product;
        }
    }
    return nullptr;
}

void ProductCatalog::removeProduct(std::string productID) {
    for (auto iter = _products.begin(); iter != _products.end(); ++iter) {
        if ((*iter)->getProductID() == productID) {
            delete* iter;
            _products.erase(iter);
            break;
        }
    }
}

void ProductCatalog::viewProducts() {
    for (Product* product : _products) {
        product->Print();
    }
}
