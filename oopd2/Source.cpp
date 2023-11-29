#include<iostream>
#include<fstream>
#include"Books.h"
#include"Clothing.h"
#include"Electronics.h"
#include"Order.h"
#include"ProductCatalog.h"

using namespace std;

int main() {
	string configPath = "";
	cout << "Enter configuration file path: ";
	cin >> configPath;
	ifstream configFile(configPath);
	string text;
	
	return 0;
}