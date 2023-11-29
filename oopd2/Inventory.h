#pragma once
#include <list>
#include "Product.h"

class Inventory {
private:
    const int _lowStockLimit = 10;
    std::list<Product*> _products;
    std::list<Product*> _lowStock;

    void addToLowStock(Product* product);
    void removeFromLowStock(std::string productID);

public:
    Inventory();

    Inventory(std::list<Product> products);

    void addProduct(Product product);

    void removeProduct(std::string productID);

    Product* findProduct(std::string productID);

    void addQuantity(std::string productID, int quantity);

    void subtractQuantity(std::string productID, int quantity);
};
