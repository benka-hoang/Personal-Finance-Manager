#include<iostream>
#include<fstream>
#include"../include/Date.h"
#include"../include/Category.h"
#include"../include/Income.h"
#include"../include/Expense.h"
#include"../include/Wallet.h"
#include"../include/ListWallet.h"

using namespace std;

int main() {
	ListWallet list_wallet;
	list_wallet.Init();

	cout << "Kaka\n";

	// Example data
	Wallet momo;
	momo.Init();
	momo.id = 0;
	momo.name = "Momo";
	momo.inc_source[0] = { 0, "Salary" };
	momo.inc_source[1] = { 1, "Poker" };
	momo.inc_source[2] = { 2, "Bussiness" };
	momo.exp_category[0] = { 0, "House" };
	momo.exp_category[1] = { 1, "Food" };
	momo.exp_category[2] = { 2, "Poker" };

	// Income Info
	Date d1 = { 14, 12, 2025 };
	int amount1 = 150000;
	Category source1 = { 0, "Salary" };
	string des1 = "Luong ve";
	momo.Add_Income(d1, amount1, source1, des1);

	Date d11 = { 10, 12, 2025 };
	int amount11 = 150000;
	Category source11 = { 0, "Bussiness" };
	string des11 = "Tien ve";
	momo.Add_Income(d11, amount11, source11, des11);

	cout << momo.list_inc[0].des << "\n";

	// Expense Info
	Date d2 = { 14, 12, 2025 };
	int amount2 = 150000;
	Category category2 = { 1, "Food" };
	string des2 = "Tien an";
	momo.Add_Expense(d2, amount2, category2, des2);

	Date d21 = { 14, 12, 2025 };
	int amount21 = 150000;
	Category category21 = { 1, "Food" };
	string des21 = "Tien an";
	momo.Add_Expense(d21, amount21, category21, des21);

	for (int i = 0; i < momo.size_inc; ++i) {
		momo.list_inc[i].Display();
	}
	return 0;
}