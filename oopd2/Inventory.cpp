#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {}

Inventory::Inventory(std::list<Product>* products) {
    for (auto iter = products->begin(); iter != products->end(); ++iter) {
        Product* product = &*iter;
        addProduct(product);
        if (product->getQuantityInStock() <= _lowStockLimit) {
            addToLowStock(product);
        }
    }
}

void Inventory::addToLowStock(Product* product) {
    if (product) {
        _lowStock.push_back(product);
    }
}

void Inventory::removeFromLowStock(std::string productID) {
    for (auto iter = _lowStock.begin(); iter != _lowStock.end(); ++iter) {
        if ((*iter)->getProductID() == productID) {
            _lowStock.erase(iter);
            break;
        }
    }
}

void Inventory::addProduct(Product* product) {
    _products.push_back(product);
}

void Inventory::removeProduct(std::string productID) {
    for (auto iter = _products.begin(); iter != _products.end(); ++iter) {
        if ((*iter)->getProductID() == productID) {
            delete* iter;
            _products.erase(iter);
            break;
        }
    }
}

Product* Inventory::findProduct(std::string productID) {
    for (Product* product : _products) {
        if (product->getProductID() == productID) {
            return product;
        }
    }
    return nullptr;
}

void Inventory::addQuantity(std::string productID, int quantity) {
    Product* product = findProduct(productID);
    if (product) {
        int q = product->getQuantityInStock();
        q += quantity;
        product->setQuantityInStock(q);
        if (q > _lowStockLimit) {
            removeFromLowStock(productID);
        }
    }
}

void Inventory::subtractQuantity(std::string productID, int quantity) {
    Product* product = findProduct(productID);
    if (product) {
        int q = product->getQuantityInStock();
        q -= quantity;
        if (q < 0) {
            std::cout << "Cannot subtract quantity";
            return;
        }
        product->setQuantityInStock(q);
        if (q <= _lowStockLimit) {
            addToLowStock(product);
            std::cout << "Product has low stock";
        }
    }
}
