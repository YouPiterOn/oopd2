#pragma once
#include <list>
#include "Product.h"

class ProductCatalog {
private:
    std::list<Product*> _products;

public:
    ProductCatalog();

    ProductCatalog(std::list<Product> products);

    void addProduct(Product product);

    Product* findProduct(std::string productID);

    void removeProduct(std::string productID);

    void viewProducts();
};
