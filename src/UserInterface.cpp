#include "../include/UserInterface.h"
#include"../include/Date.h"
#include"../include/Category.h"
#include"../include/Income.h"
#include"../include/Expense.h"
#include"../include/Wallet.h"
#include"../include/ListWallet.h"
#include"../include/Recurring.h"
#include"../include/UserInterface.h"
#include"cstdlib"

void ClearScreen() {
	system("cls");
	return;
}

const string arr[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
bool CheckOption(string &s, int l, int r){
	for (int i = l; i <= r; ++i) if (s == arr[i]) return true;
	return false;
}

void GachNgang() {
	cout << setfill('=');
	cout << setw(40) << "=" << "\n";
	return;
}

void AddTransaction() {
	return;
}

void AddRecurring() {
	return;
}

void WalletManagement() {
	return;
}

void Statistics() {
	return;
}

void Settings() {
	ClearScreen();
	cout << "Menu: \n";
	cout << "      " << "0. Back\n";
	cout << "      " << "1. Change username\n";
	cout << "      " << "2. Change password\n";
	cout << "Your option: ";
	string s; getline(cin, s);
	while (!CheckOption(s, 0, 2)) {
		cout << "Invalid option! Please type again : ";
		getline(cin, s);
	}
	int choice = int(s[0]) - int('0');
	if (choice == 1) {
		string name;
		cout << "Change username (At most 32 characters): "; getline(cin, name);
		while (name.size() > 32 || name.size() == 0) {
			if (name.size() > 32)
				cout << "Username too long, please type again!\n";
			else
				cout << "Username cannot be blank!\n";
			cout << "Change username : "; getline(cin, name);
		}
		Convert_String_to_Char(list_wallet.user_name, name, 32);
		list_wallet.SaveData();
	}
	else if(choice == 2){
		string pass;
		cout << "Change password (At most 32 characters) : "; getline(cin, pass);
		while (pass.size() > 32 || pass.size() == 0) {
			if (pass.size() > 32)
				cout << "Password too long, please type again!\n";
			else
				cout << "Password cannot be blank!\n";
			cout << "Change password : "; getline(cin, pass);
		}
		Convert_String_to_Char(list_wallet.password, pass, 32);
		list_wallet.SaveData();
	}
	ClearScreen();
	Dashboard();
	return;
}

void Dashboard() {
	cout << "Hi, "; cout << Convert_Char_to_String(list_wallet.user_name, 32) << "!\n";
	GachNgang();
	cout << "Total balance: " << list_wallet.Total_Balance({ 1, 1, 1 }, Today()) << "\n";
	GachNgang();
	cout << "List wallets: \n";
	for (int i = 0; i < list_wallet.size; ++i) {
		cout << "      " << i << ". " << Convert_Char_to_String(list_wallet.wallet[i].name, 20) << "\n";
	}
	GachNgang(); 
	cout << "Menu: \n";
	cout << "      " << "1. Add Transaction \n";
	cout << "      " << "2. Add Recurring \n";
	cout << "      " << "3. Wallet Management \n";
	cout << "      " << "4. Statistics \n";
	cout << "      " << "5. Settings \n";
	cout << "      " << "6. Exit \n";
	
	cout << "Your option: ";
	string s; getline(cin, s);
	while (!CheckOption(s, 1, 6)) {
		cout << "Invalid option! Please type again : ";
		getline(cin, s);
	}
	int choice = int(s[0]) - int('0');
	if(choice == 1) {
		AddTransaction();
	}
	else if(choice == 2) {
		AddRecurring();
	}
	else if(choice == 3) {
		WalletManagement();
	}
	else if(choice == 4) {
		Statistics();
	}
	else if (choice == 5) {
		Settings();
	} 
	else if (choice == 6) {
		ClearScreen();
		cout << "See you later...\n";
	}
	return;
}

void UI() {
	list_wallet.LoadData();
	if (list_wallet.first_time) {
		string name, pass;
		cout << "Create username (At most 32 characters): "; getline(cin, name);
		while (name.size() > 32 || name.size() == 0) {
			if (name.size() > 32)
				cout << "Username too long, please type again!\n";
			else
				cout << "Username cannot be blank!\n";
			cout << "Create username : "; getline(cin, name);
		}
		cout << "Create password (At most 32 characters) : "; getline(cin, pass);
		while (pass.size() > 32 || pass.size() == 0) {
			if (pass.size() > 32)
				cout << "Password too long, please type again!\n";
			else
				cout << "Password cannot be blank!\n";
			cout << "Create password : "; getline(cin, pass);
		}
		list_wallet.first_time = false;
		Convert_String_to_Char(list_wallet.user_name, name, 32);
		Convert_String_to_Char(list_wallet.password, pass, 32);
		list_wallet.SaveData();
	}
	else {
		string s, pass = Convert_Char_to_String(list_wallet.password, 32);
		cout << "Hi, "; cout << Convert_Char_to_String(list_wallet.user_name, 32) << "!\n";
		cout << "Enter password : "; getline(cin, s);
		while (pass != s) {
			cout << "Wrong password! Please type again : ";
			getline(cin, s);
		}
		cout << "Log in successfully!";
		this_thread::sleep_for(chrono::milliseconds(500)); cout << ".";
		this_thread::sleep_for(chrono::milliseconds(500)); cout << ".";
		this_thread::sleep_for(chrono::milliseconds(500)); cout << ".";
		this_thread::sleep_for(chrono::milliseconds(500));
		ClearScreen();
	}
	Dashboard();
	return;
}