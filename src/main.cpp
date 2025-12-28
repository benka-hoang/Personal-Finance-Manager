#include<iostream>
#include<fstream>

#include"../include/Date.h"
#include"../include/Category.h"
#include"../include/Income.h"
#include"../include/Expense.h"
#include"../include/Wallet.h"
#include"../include/ListWallet.h"
#include"../include/Recurring.h"
#include"../include/UserInterface.h"

using namespace std;

void CreateSampleData();
void DefaultProgram();

int main() {
	UI();
	return 0;
}

void DefaultProgram() {
	list_wallet.Init();
	list_wallet.SaveData();
	return;
}

// Function to generate sample data
void CreateSampleData() {
	// 1. Initialize global wallet list
	// Note: This automatically creates wallet[0] named "Others"
	list_wallet.Init();

	// ---------------------------------------------------------
	// WALLET 1: Personal Wallet (Stored at index 1)
	// ---------------------------------------------------------
	list_wallet.Add_Wallet("Personal Wallet");

	// Access wallet at index 1 (Index 0 is "Others")
	Wallet& w1 = list_wallet.wallet[1];

	// Add Income Sources
	// Note: Index 0 is "Others" (created by Init). New sources start at index 1.
	w1.Add_Source("Salary");        // index 1
	w1.Add_Source("Bonus");         // index 2
	w1.Add_Source("Gift");          // index 3

	// Add Expense Categories
	// Note: Index 0 is "Others". New categories start at index 1.
	w1.Add_Category("Food");          // index 1
	w1.Add_Category("Transport");     // index 2
	w1.Add_Category("Entertainment"); // index 3

	// Add Income
	// Use w1.inc_source[x] where x matches the added source index
	w1.Add_Income({ 10, 1, 2024 }, 20000000, w1.inc_source[1], "January Salary");
	w1.Add_Income({ 15, 1, 2024 }, 5000000, w1.inc_source[2], "Tet Bonus");

	// Add Expense
	w1.Add_Expense({ 11, 1, 2024 }, 50000, w1.exp_category[1], "Lunch");
	w1.Add_Expense({ 12, 1, 2024 }, 30000, w1.exp_category[2], "Bus ticket");
	w1.Add_Expense({ 14, 1, 2024 }, 200000, w1.exp_category[3], "Movie tickets");


	// ---------------------------------------------------------
	// WALLET 2: Savings Fund (Stored at index 2)
	// ---------------------------------------------------------
	list_wallet.Add_Wallet("Savings Fund");
	Wallet& w2 = list_wallet.wallet[2];

	// Source (starts at index 1)
	w2.Add_Source("Bank Interest"); // index 1
	w2.Add_Source("Deposit");       // index 2

	// Category (starts at index 1)
	w2.Add_Category("Investment");  // index 1
	w2.Add_Category("Emergency");   // index 2

	// Income
	w2.Add_Income({ 1, 2, 2024 }, 10000000, w2.inc_source[2], "Initial Deposit");
	w2.Add_Income({ 28, 2, 2024 }, 50000, w2.inc_source[1], "Feb Interest");

	// Expense
	w2.Add_Expense({ 15, 3, 2024 }, 2000000, w2.exp_category[1], "Buy Stocks");


	// ---------------------------------------------------------
	// WALLET 3: Travel Fund (Stored at index 3)
	// ---------------------------------------------------------
	list_wallet.Add_Wallet("Travel Fund");
	Wallet& w3 = list_wallet.wallet[3];

	// Source
	w3.Add_Source("Freelance");     // index 1
	w3.Add_Source("Selling Items"); // index 2

	// Category
	w3.Add_Category("Flight");      // index 1
	w3.Add_Category("Hotel");       // index 2
	w3.Add_Category("Visa");        // index 3
	cout << w3.size_category << "\n";

	// Income
	w3.Add_Income({ 5, 4, 2024 }, 3000000, w3.inc_source[1], "Project Payment");
	w3.Add_Income({ 10, 4, 2024 }, 500000, w3.inc_source[2], "Sold old books");

	// Expense
	w3.Add_Expense({ 20, 4, 2024 }, 1500000, w3.exp_category[1], "Book Flight to Da Nang");
	w3.Add_Expense({ 21, 4, 2024 }, 800000, w3.exp_category[2], "Deposit Hotel");

	cout << "Sample data generated successfully!" << endl;
}