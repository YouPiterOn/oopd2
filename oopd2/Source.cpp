#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Books.h"
#include"Clothing.h"
#include"Electronics.h"
#include"Order.h"
#include"ProductCatalog.h"
#include"Inventory.h"

using namespace std;

int main() {
	list<Product> products;
	
	string configPath = "";
	cout << "Enter configuration file path: ";
	cin >> configPath;
	ifstream configFile(configPath);
	for (string line; getline(configFile, line);) {
		if (line[0] == '#') continue;
		stringstream itemConfig(line);
		char skip;
		string type;
		getline(itemConfig, type, ',');
		string name;
		getline(itemConfig, name, ',');
		float price;
		itemConfig >> price;
		itemConfig >> skip;
		int quantity;
		itemConfig >> quantity;
		itemConfig >> skip;
		if (type == "Electronics") {
			string brand;
			getline(itemConfig, brand, ',');
			string model;
			getline(itemConfig, model, ',');
			int powerConsumption;
			itemConfig >> powerConsumption;
			products.push_back(Electronics(name, price, quantity, brand, model, powerConsumption));
		}
		else if (type == "Books") {
			string author;
			getline(itemConfig, author, ',');
			string genre;
			getline(itemConfig, genre, ',');
			string ISBN;
			itemConfig >> ISBN;
			products.push_back(Books(name, price, quantity, author, genre, ISBN));
		}
		else if (type == "Clothing") {
			string size;
			getline(itemConfig, size, ',');
			string color;
			getline(itemConfig, color, ',');
			string material;
			itemConfig >> material;
			products.push_back(Clothing(name, price, quantity, size, color, material));
		}
	}
	ProductCatalog catalod(&products);
	Inventory inventory(&products);
	return 0;
}