#include "ProductCatalog.h"
#include <iostream>

ProductCatalog::ProductCatalog() {}

ProductCatalog::ProductCatalog(std::list<Product> products) {
    for (Product product : products) {
        addProduct(product);
    }
}

void ProductCatalog::addProduct(Product product) {
    _products.push_back(new Product(product));
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
        std::cout << product->getName() << ", ";
        std::cout << product->getProductID() << ", ";
        std::cout << product->getPrice() << ", ";
        std::cout << product->getQuantityInStock() << std::endl;
    }
}
