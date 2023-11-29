#pragma once
#pragma once
#include "Product.h"

class Books : public Product {
private:
    std::string _author = "";
    std::string _genre = "";
    std::string _ISBN = "";

public:
    Books(std::string name, float price, int quantityInStock, std::string author, std::string genre, std::string ISBN);

    std::string getAuthor();
    std::string getGenre();
    std::string getISBN();

    void setAuthor(std::string author);
    void setGenre(std::string genre);
    void setISBN(std::string ISBN);
};
