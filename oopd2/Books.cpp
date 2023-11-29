#include "Books.h"

Books::Books(std::string name, int price, int quantityInStock, std::string author, std::string genre, std::string ISBN) {
    setName(name);
    setPrice(price);
    setQuantityInStock(quantityInStock);
    setAuthor(author);
    setGenre(genre);
    setISBN(ISBN);
}

std::string Books::getAuthor() {
    return _author;
}

std::string Books::getGenre() {
    return _genre;
}

std::string Books::getISBN() {
    return _ISBN;
}

void Books::setAuthor(std::string author) {
    _author = author;
}

void Books::setGenre(std::string genre) {
    _genre = genre;
}

void Books::setISBN(std::string ISBN) {
    _ISBN = ISBN;
}
