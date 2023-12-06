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

class Shop
{
private:
	list<Product> _products;
	list<Order> _orders;
	int _orderId = 0;
public:
	
	Inventory Inventory;
	ProductCatalog Catalog;
	Order CurrentOrder;

	void addProduct(Product product) {
		_products.push_back(product);
		Inventory.addProduct(&_products.back());
		Catalog.addProduct(&_products.back());
	}

	void Configure(string configPath) {
		ifstream configFile(configPath);
		if (!configFile) {
			cout << "Invalid path";
			return;
		}
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
				addProduct(Electronics(name, price, quantity, brand, model, powerConsumption));
			}
			else if (type == "Books") {
				string author;
				getline(itemConfig, author, ',');
				string genre;
				getline(itemConfig, genre, ',');
				string ISBN;
				itemConfig >> ISBN;
				addProduct(Books(name, price, quantity, author, genre, ISBN));
			}
			else if (type == "Clothing") {
				string size;
				getline(itemConfig, size, ',');
				string color;
				getline(itemConfig, color, ',');
				string material;
				itemConfig >> material;
				addProduct(Clothing(name, price, quantity, size, color, material));
			}
		}
	}

	void FinishCurrentOrder(string username) {
		CurrentOrder.setCustomer(username);
		CurrentOrder.setOrderId(to_string(_orderId));
		_orderId++;
		_orders.push_back(CurrentOrder);
		CurrentOrder = Order();
	}
};

int main() {
	Shop shop;
	string help = "1 - Configure catalog\n2 - Find product\n3 - Show catalog\n4 - Finish order\n5 - Add to shopping cart\n";
	cout << help;
	int command = 0;
	while (true) {
		cout << "Enter command: ";
		cin >> command;
		switch (command)
		{
		case 1:
		{
			string configPath;
			cout << "Enter path to config file:";
			cin >> configPath;
			shop.Configure(configPath);
			break;
		}
		case 2:
		{
			string productName;
			cout << "Enter product name: ";
			cin >> productName;
			Product* product = shop.Catalog.SearchByName(productName);
			product->Print();
			cout << "Do you want to add this product to your shopping cart? Y/N";
			char ans = 'N';
			cin >> ans;
			if (ans == 'Y') {
				shop.CurrentOrder.addProduct(product);
				cout << "Product added succesfully";
			}
			break;
		}
		case 3:
		{
			shop.Catalog.viewProducts();
		}
		case 4:
		{
			cout << "Your order: " << endl;
			shop.CurrentOrder.Print();
			cout << "Do you want to finish the order?";
			char ans = 'N';
			cin >> ans;
			if (ans == 'Y') {
				cout << "Enter your username :";
				string username;
				cin >> username;
				shop.FinishCurrentOrder(username);
			}
			break;
		}
		case 5:
		{
			string productID;
			cout << "Enter product id: ";
			cin >> productID;
			Product* product = shop.Catalog.findProduct(productID);
			product->Print();
			cout << "Do you want to add this product to your shopping cart? Y/N";
			char ans = 'N';
			cin >> ans;
			if (ans == 'Y') {
				shop.CurrentOrder.addProduct(product);
				cout << "Product added succesfully";
			}
			break;
		}
		}
	}
	return 0;
}
