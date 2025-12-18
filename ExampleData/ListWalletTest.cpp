#include<iostream>
#include<fstream>
#include"../include/Date.h"
#include"../include/Category.h"
#include"../include/Income.h"
#include"../include/Expense.h"
#include"../include/Wallet.h"
#include"../include/ListWallet.h"

using namespace std;

int ListWalletTest() {
	ListWallet list_wallet;
	list_wallet.Init();
	list_wallet.Add_Wallet("momo");

	// Example data
	list_wallet.wallet[0].Add_Source("Salary");
	list_wallet.wallet[0].Add_Source("Poker");
	list_wallet.wallet[0].Add_Source("Bussiness");
	list_wallet.wallet[0].Add_Category("House");
	list_wallet.wallet[0].Add_Category("Food");
	list_wallet.wallet[0].Add_Category("Poker");

	cout << list_wallet.wallet[0].name << "\n";

	// Income Info
	Date d1 = { 14, 12, 2025 };
	int amount1 = 150000;
	Category source1 = { 0, "Salary" };
	string des1 = "Luong ve";
	list_wallet.wallet[0].Add_Income(d1, amount1, source1, des1);

	Date d11 = { 10, 12, 2025 };
	int amount11 = 150000;
	Category source11 = { 0, "Bussiness" };
	string des11 = "Tien ve";
	list_wallet.wallet[0].Add_Income(d11, amount11, source11, des11);

	// Expense Info
	Date d2 = { 14, 12, 2025 };
	int amount2 = 150000;
	Category category2 = { 1, "Food" };
	string des2 = "Tien an";
	list_wallet.wallet[0].Add_Expense(d2, amount2, category2, des2);

	Date d21 = { 14, 12, 2025 };
	int amount21 = 150000;
	Category category21 = { 1, "Food" };
	string des21 = "Tien an";
	list_wallet.wallet[0].Add_Expense(d21, amount21, category21, des21);
	return 0;
}