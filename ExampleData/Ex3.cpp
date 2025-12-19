#include<iostream>
#include<fstream>
#include"../include/Date.h"
#include"../include/Category.h"
#include"../include/Income.h"
#include"../include/Expense.h"
#include"../include/Wallet.h"
#include"../include/ListWallet.h"
#include"../include/Recurring.h"

using namespace std;

int Ex3() {
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

	// Income Info
	Date d1 = { 14, 12, 2025 };
	int amount1 = 150000;
	Category source1 = { 1, "Salary" };
	string des1 = "Luong ve";
	list_wallet.wallet[0].Add_Income(d1, amount1, source1, des1);

	Date d11 = { 10, 12, 2025 };
	int amount11 = 150000;
	Category source11 = { 3, "Bussiness" };
	string des11 = "Tien ve";
	list_wallet.wallet[0].Add_Income(d11, amount11, source11, des11);

	Date d12 = { 10, 12, 2023 };
	int amount12 = 20000;
	Category source12 = { 3, "Bussiness" };
	string des12 = "2023 Do nha";
	list_wallet.wallet[0].Add_Income(d12, amount12, source12, des12);

	// Expense Info
	Date d2 = { 14, 12, 2025 };
	int amount2 = 150000;
	Category category2 = { 2, "Food" };
	string des2 = "Tien an";
	list_wallet.wallet[0].Add_Expense(d2, amount2, category2, des2);

	Date d21 = { 14, 12, 2021 };
	int amount21 = 150000;
	Category category21 = { 1, "House" };
	string des21 = "2021 Do nha";
	list_wallet.wallet[0].Add_Expense(d21, amount21, category21, des21);

	// Recurring Info
	string name3 = "TaiXiu";
	Date start_date3 = { 31, 7, 2025 };
	Date end_date3 = { 31, 12, 2025 };
	int type3 = +1, amount3 = 5000;
	Category category3 = { 2, "Poker" };
	Recurring Re3 = Info_to_Recurring(name3, start_date3, end_date3, type3, amount3, category3);
	list_wallet.wallet[0].Add_Recurring(Re3);
	return 0;
}