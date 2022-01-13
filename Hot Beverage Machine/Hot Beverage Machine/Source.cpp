#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <array>
#include <iomanip>

//Due to the fact that the code uses external .txt files, it is recommended to download and run from the source folder

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
string hotdrink() {
	string line = "";
	ifstream inFile;
	inFile.open("hotdrink.txt");
	if (inFile.is_open())
	{
		while (getline(inFile, line)) {
			SetConsoleTextAttribute(h, 12);
			cout << line << endl;
		}
		cout << "Enjoy!" << endl;
	}
	else
	{
		cout << "failed to load file" << endl;
	}
	inFile.close();
	return "Enjoy!";
}
string colddrink() {
	string line = "";
	ifstream inFile;
	inFile.open("colddrink.txt");
	if (inFile.is_open())
	{
		while (getline(inFile, line)) {
			SetConsoleTextAttribute(h, 12);
			cout << line << endl;
		}
		cout << "Enjoy!" << endl;
	}
	else
	{
		cout << "failed to load file" << endl;
	}
	inFile.close();
	return "Enjoy!";
}
void coffee() {
	int drtype, payment, cost, change;
	bool sugar;
	string wsugar;
	cout << "How would you like your coffee?" << endl;
	cout << "Ice(1), Milk(2), Black(3)" << endl;
	cin >> drtype;
	while (drtype < 1 || drtype > 3 || cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please try again." << endl;
			cout << "Ice(1), Milk(2), Black(3)" << endl;
			cin >> drtype;
		}
	switch(drtype){
	case 1:
		cost = 3;
		cout << "You have picked Ice Coffee";
		break;
	case 2:
		cost = 2;
		cout << "You have picked Milk Coffee";
		break;
	case 3:
		cost = 1;
		cout << "You have picked Black Coffee";
		break;
	}
	cout << endl;
	cout << "Would you like sugar with that? Does not come with extra cost" << endl;
	cout << "Yes(1) No(0)" << endl;
	cin >> sugar;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input" << endl;
		cout << "Would you like sugar with that?" << endl;
		cout << "Yes(1) No(0)" << endl;
		cin >> sugar;
	}
	if (sugar == true) {
		wsugar = "with sugar";
	}
	else {
		wsugar = "without sugar";
	}
	cout << endl;
	cout << "Cost: " << cost << endl;
	cout << "Enter the amount of payment: ";
	cin >> payment;
	while (payment < 0 || cost > payment) {
		cin.clear();
		cin.ignore(1000, '\n');
		if (cost > payment) {
			cout << "Not enough for payment" << endl;
		}
		else {
			cout << "Invalid Input" << endl;
		}
		cout << "Enter the amount of payment: ";
		cin >> payment;
	}
	change = payment - cost;
	cout << endl;
	cout << "You have paid " << payment << " AED" << endl;
	cout << "Your change is " << change << " AED" << endl;
	if (drtype == 2 || drtype == 3) {
		if (drtype == 2) {
			cout << "You have ordered Milk Coffee " << wsugar << endl;
		}
		else if (drtype == 3) {
			cout << "You have ordered Black Coffee " << wsugar << endl;
		}
		hotdrink();
	}
	else if (drtype == 1) {
		cout << "You have ordered Ice Coffee " << wsugar << endl;
		colddrink();
	}
}
void tea() {
	int drtype, payment, cost, change;
	bool sugar;
	string wsugar;
	cout << "How would you like your tea?" << endl;
	cout << "Ice(1), Milk(2), Black(3)" << endl;
	cin >> drtype;
	while (drtype < 1 || drtype > 3 || cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid Input. Please try again." << endl;
			cout << "Ice(1), Milk(2), Black(3)" << endl;
			cin >> drtype;
	}
	switch (drtype) {
	case 1:
		cost = 3;
		cout << "You have picked Ice Tea";
		break;
	case 2:
		cost = 2;
		cout << "You have picked Milk Tea";
		break;
	case 3:
		cost = 1;
		cout << "You have picked Black Tea";
		break;
	}
	cout << endl;
	cout << "Would you like sugar with that? Does not come with extra cost" << endl;
	cout << "Yes(1) No(0)" << endl;
	cin >> sugar;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input" << endl;
		cout << "Would you like sugar with that?" << endl;
		cout << "Yes(1) No(0)" << endl;
		cin >> sugar;
	}
	if (sugar == true) {
		wsugar = "with sugar";
	}
	else {
		wsugar = "without sugar";
	}
	cout << endl;
	cout << "Cost: " << cost << endl;
	cout << "Enter the amount of payment: ";
	cin >> payment;
	while (payment < 0 || cost > payment) {
		cin.clear();
		cin.ignore(1000, '\n');
		if (cost > payment) {
			cout << "Not enough for payment" << endl;
		}
		else {
			cout << "Invalid Input" << endl;
		}
		cout << "Enter the amount of payment: ";
		cin >> payment;
	}
	change = payment - cost;
	cout << endl;
	cout << "You have paid " << payment << " AED" << endl;
	cout << "Your change is " << change << " AED" << endl;
	if (drtype == 2 || drtype == 3) {
		if (drtype == 2) {
			cout << "You have ordered Milk Tea " << wsugar << endl;
		}
		else if (drtype == 3) {
			cout << "You have ordered Black Tea " << wsugar << endl;
		}
		hotdrink();
	}
	else if (drtype == 1) {
		cout << "You have ordered Ice Tea " << wsugar << endl;
		colddrink();
	}
}
int main() {
	char drchoice;
	int drtype;
	const char sep = ' ';
	const int namew = 20;
	string price = "Price(AED)";
	string menu[4][4] = {
		{"Coffee", price, "Tea", price},
		{"Ice Coffee", "3", "Ice Tea", "3"},
		{"Milk Coffee", "2", "Milk Tea", "2"},
		{"Black Coffee", "1", "Black Tea", "1"}
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << left << setw(namew) << setfill(sep) << menu[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "What would you like to order?" << endl;
	cout << "Coffee(c) or Tea(t)" << endl;
	cin >> drchoice;
	while ((drchoice != 'C' && drchoice != 'c') || (drchoice != 'T' && drchoice != 't')) {
		if (drchoice == 'C' || drchoice == 'c' || drchoice == 'T' || drchoice == 't') {
			break;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input" << endl;
		cout << "What would you like to order?" << endl;
		cout << "Coffee(c) or Tea(t)" << endl;
		cin >> drchoice;
	}
	if(drchoice == 'C' || drchoice == 'c') {
		coffee();
	}
	else if (drchoice == 'T' || drchoice == 't') {
		tea();
	}
}