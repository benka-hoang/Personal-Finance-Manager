#include"../include/UserInterface.h"
#include"../include/Date.h"
#include"../include/Category.h"
#include"../include/Income.h"
#include"../include/Expense.h"
#include"../include/Wallet.h"
#include"../include/ListWallet.h"
#include"../include/Recurring.h"
#include"../include/UserInterface.h"
#include"../include/InputChecker.h"
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

void GachTransaction() {
	cout << setfill('='); cout << setw(12) << "=";
	cout << "Add Transaction";
	cout << setfill('='); cout << setw(12) << "=";
	cout << "\n";
	return;
}
void AddTransaction() {
	ClearScreen();
	GachTransaction();
	cout << "Menu: \n";
	cout << "      " << "0. Back\n";
	cout << "      " << "1. Add Income\n";
	cout << "      " << "2. Add Expense\n";
	cout << "Your option: ";
	string s; getline(cin, s);
	while (!CheckOption(s, 0, 2)) {
		cout << "Invalid option! Please type again : ";
		getline(cin, s);
	}
	int choice = int(s[0]) - int('0');
	if (choice == 1) {
		ClearScreen();
		GachTransaction();
		string wallet, amount, date, source, des;
		cout << "Wallet : "; getline(cin, wallet);
		cout << "Date : "; getline(cin, date);
		cout << "Amount : "; getline(cin, amount);
		cout << "Source : "; getline(cin, source);
		cout << "Description : "; getline(cin, des);
		IncomeInfo info = CheckIncome(wallet, amount, date, source, des);

	}
	else if (choice == 2) {

	}
	return;
}

void AddRecurring() {
	return;
}

void WalletManagement() {
	return;
}

void Statistics() {
	ClearScreen();
	cout<<"===============Statistics==============="<<endl;
	cout << "Menu: \n";
	cout << "      " << "0. Back\n";
	cout << "      " << "1. Time-based statistics\n";
	cout << "      " << "2. Wallet-based statistics\n";
	cout << "      " << "3. Annual overview\n";
	cout << "Your option: ";
	string s; getline(cin, s);
	while(!CheckOption(s, 0, 3)) {
		cout<<"Invalid option! Please type again : ";
		getline(cin, s);
	}
	int choice = int(s[0])-int('0');
	if(choice==0) {
		ClearScreen();
		Dashboard();
	}
	if(choice == 1) {
		ClearScreen();
		cout<<"===============Statistics==============="<<endl;
		cout<<"Display income, expense and balance from Date A to Date B."<<endl;
		cout<<"Type in date A (DD/MM/YYYY): "<<endl;
		string s;
		getline(cin, s);
		Date d1=ConvertStringToDate(s);
		while(!CheckDate(d1))
		{
			cin.ignore();
			getline(cin, s);
			d1=ConvertStringToDate(s);
		}
		Date d2;
		cout<<"Type in date B: "<<endl;
		cout<<"Do you want to use today's date? (y/n) ";
		char c; cin>>c;
		while(c!='y'&&c!='n') 
		{
			cout<<"Invalid choice! Please type again : ";
			cin>>c;
		}
		if(c=='y')
		{
			d2=Today();
		}
		else if(c=='n')
		{
			cout<<"Type in date B (DD/MM/YYYY): "<<endl;
			string s2;
			cin.ignore();
			getline(cin, s2);
			d2=ConvertStringToDate(s2);
			while(!CheckDate(d2))
			{
				cin.ignore();
				getline(cin, s2);
				d2=ConvertStringToDate(s2);
			}
		}
		cout<<"Total income from "<<d1.day<<"/"<<d1.month<<"/"<<d1.year<<" to "<<d2.day<<"/"<<d2.month<<"/"<<d2.year<<" is "<<list_wallet.Total_Income(d1, d2)<<endl;
		cout<<"Total expense from "<<d1.day<<"/"<<d1.month<<"/"<<d1.year<<" to "<<d2.day<<"/"<<d2.month<<"/"<<d2.year<<" is "<<list_wallet.Total_Expense(d1, d2)<<endl;
		cout<<"Total balance from "<<d1.day<<"/"<<d1.month<<"/"<<d1.year<<" to "<<d2.day<<"/"<<d2.month<<"/"<<d2.year<<" is "<<list_wallet.Total_Balance(d1, d2)<<endl;
		if (c == 'y') {
            cin.ignore();
        }
        cout << "Choose 0 to back! "; 
        string s_choice;
        getline(cin, s_choice);

        // Check nhập đúng số 0
        while(!CheckOption(s_choice, 0, 0)) {
            cout << "Invalid option! Please type again (0 to back): ";
            getline(cin, s_choice);
        }

        // 2. Sửa đúng tên biến: s_choice
        int back_choice = int(s_choice[0]) - int('0');
        
        if(back_choice == 0) {
            Statistics(); // Gọi lại hàm để hiện Menu
            return;
		}
	}
	else if (choice == 2) {
		ClearScreen();
		cout<<"===============Statistics==============="<<endl;
		cout<<"Filter income and expense for wallets."<<endl;
		cout<<"Type in date A (DD/MM/YYYY): "<<endl;
		string s;
		getline(cin, s);
		Date d1=ConvertStringToDate(s);
		while(!CheckDate(d1))
		{
			cin.ignore();
			getline(cin, s);
			d1=ConvertStringToDate(s);
		}
		Date d2;
		cout<<"Type in date B: "<<endl;
		cout<<"Do you want to use today's date? (y/n) ";
		char c; cin>>c;
		while(c!='y'&&c!='n') 
		{
			cout<<"Invalid choice! Please type again : ";
			cin>>c;
		}
		if(c=='y')
		{
			d2=Today();
		}
		else if(c=='n')
		{
			cout<<"Type in date B (DD/MM/YYYY): "<<endl;
			string s2;
			cin.ignore();
			getline(cin, s2);
			d2=ConvertStringToDate(s2);
			while(!CheckDate(d2))
			{
				cin.ignore();
				getline(cin, s2);
				d2=ConvertStringToDate(s2);
			}
		}
		cout<<"From "<<d1.day<<"/"<<d1.month<<"/"<<d1.year<<" to "<<d2.day<<"/"<<d2.month<<"/"<<d2.year<<endl;
		cout<<"Time-based Wallets' Income"<<endl;
		for(int i=0;i<list_wallet.size;++i)
		{
			cout<<"      "<<i<<". "<<Convert_Char_to_String(list_wallet.wallet[i].name, 20)<<": "<<list_wallet.wallet[i].Total_Income(d1, d2)<<endl;
		}
		cout<<endl;
		cout<<"Time-base Wallets' Expense"<<endl;
		for(int i=0;i<list_wallet.size;++i)
		{
			cout<<"      "<<i<<". "<<Convert_Char_to_String(list_wallet.wallet[i].name, 20)<<": "<<list_wallet.wallet[i].Total_Expense(d1, d2)<<endl;
		}
		cout<<endl;
		cout<<"Current month Wallets' Income"<<endl;
		for(int i=0; i < list_wallet.size; ++i)
		{
			cout<<"      "<<i<<". "<<Convert_Char_to_String(list_wallet.wallet[i].name, 20)<<": "<<list_wallet.wallet[i].Total_Income_Current_Month()<<endl;
		}
		cout<<endl;
		cout<<"Current month Wallets' Expense"<<endl;
		for(int i=0;i<list_wallet.size;++i)
		{
			cout<<"      "<<i<<". "<<Convert_Char_to_String(list_wallet.wallet[i].name, 20)<<": "<<list_wallet.wallet[i].Total_Expense_Current_Month()<<endl;
		}
		cout<<endl;
		if (c == 'y') {
            cin.ignore();
        }
        cout << "Choose 0 to back! "; 
        string s_choice;
        getline(cin, s_choice);

        // Check nhập đúng số 0
        while(!CheckOption(s_choice, 0, 0)) {
            cout << "Invalid option! Please type again (0 to back): ";
            getline(cin, s_choice);
        }

        int back_choice = int(s_choice[0]) - int('0');
        
        if(back_choice == 0) {
            Statistics(); // Gọi lại hàm để hiện Menu
            return;
		}
	}
	else if (choice == 3) {
		ClearScreen();
		cout<<"===============Statistics==============="<<endl;
		cout<<"Annual overview's menu"<<endl;
		cout<<"      " << "0. Back\n";
		cout<<"      " << "1. Net balance changes\n";
		cout<<"      " << "2. Income sources\n";
		cout<<"      " << "3. Expense categories\n";
		cout << "Your option: ";
		string s_choice;
		getline(cin, s_choice);
		while(!CheckOption(s_choice, 0, 3))
		{
			cout<<"Invalid choice! Please type again : ";
			getline(cin, s_choice);
		}
		int Choice = int(s_choice[0]-'0');
		if(Choice==0)
		{
			ClearScreen();
			Statistics();
		}
		else if(Choice==1)
		{
			cout<<"===========Net balance changes===========";
			cout<<"How many years do you want to select? ";
			int size; cin>>size;
			int* year = new int [size];
			cout<<"Select years you want to examine"<<endl;
			for(int i = 0; i<size;++i) cin>>year[i];
			int income=0;
			for(int i=0;i<list_wallet.size;++i) income+=list_wallet.wallet[i].Annual_Income(size, year);
			int expense=0;
			for(int i=0;i<list_wallet.size;++i) expense+=list_wallet.wallet[i].Annual_Expense(size, year);
			int balance=income-expense;
			cout<<"For the selected years,"<<endl;
			cout << "      " <<"Total income: "<<income<<endl;
			cout << "      " <<"Total expense: "<<expense<<endl;
			cout << "      " <<"Net balance: "<<balance<<endl;
			delete[] year;
			cout << "Choose 0 to back to Statistics Menu! "; 
			string s_choice;
			cin.ignore();
			getline(cin, s_choice);

			// Check nhập đúng số 0
			while(!CheckOption(s_choice, 0, 0)) {
				cout << "Invalid option! Please type again (0 to back): ";
				getline(cin, s_choice);
			}

			int back_choice = int(s_choice[0]) - int('0');
			
			if(back_choice == 0) {
				Statistics();
				return;
			}
		}
		else if(Choice==2)
		{
			cout<<"=========Annual Income Sources=========="<<endl;
			cout<<"How many years do you want to select? ";
			int size; cin>>size;
			int* year = new int [size];
			cout<<"Select years you want to examine"<<endl;
			for(int i = 0; i<size;++i) cin>>year[i];
			int income=0;
			for(int i=0;i<list_wallet.size;++i) income+=list_wallet.wallet[i].Annual_Income(size, year);
			cout<<"Total income for the selected years: "<<income<<endl;
			for(int i=0;i<list_wallet.size;++i)
			{
				cout<<"Wallet ["<<i<<"]. "<<Convert_Char_to_String(list_wallet.wallet[i].name, 20)<<endl;
				for(int j=0;j<list_wallet.wallet[i].size_source;++j)
				{
					cout<<"      "<<j<<". "<<Convert_Char_to_String(list_wallet.wallet[i].inc_source[j].name, 20)<<": "<<list_wallet.wallet[i].Annual_Income_Source(size, year)[j]<<endl;
				}
			}
			cout << "Choose 0 to back to Statistics Menu! "; 
			string s_choice;
			cin.ignore();
			getline(cin, s_choice);

			// Check nhập đúng số 0
			while(!CheckOption(s_choice, 0, 0)) {
				cout << "Invalid option! Please type again (0 to back): ";
				getline(cin, s_choice);
			}

			int back_choice = int(s_choice[0]) - int('0');
			
			if(back_choice == 0) {
				Statistics();
				return;
			}
		}
		else if(Choice==3)
		{
			cout<<"=========Annual Expense Sources=========="<<endl;
			cout<<"How many years do you want to select? ";
			int size; cin>>size;
			int* year = new int [size];
			cout<<"Select years you want to examine"<<endl;
			for(int i = 0; i<size;++i) cin>>year[i];
			int expense=0;
			for(int i=0;i<list_wallet.size;++i) expense+=list_wallet.wallet[i].Annual_Expense(size, year);
			cout<<"Total expense for the selected years: "<<expense<<endl;
			for(int i=0;i<list_wallet.size;++i)
			{
				cout<<"Wallet ["<<i<<"]. "<<Convert_Char_to_String(list_wallet.wallet[i].name, 20)<<endl;
				for(int j=0;j<list_wallet.wallet[i].size_category;++j)
				{
					cout<<"      "<<j<<". "<<Convert_Char_to_String(list_wallet.wallet[i].exp_category[j].name, 20)<<": "<<list_wallet.wallet[i].Annual_Expense_Category(size, year)[j]<<endl;
				}
			}
			cout << "Choose 0 to back to Statistics Menu! "; 
			string s_choice;
			cin.ignore();
			getline(cin, s_choice);

			// Check nhập đúng số 0
			while(!CheckOption(s_choice, 0, 0)) {
				cout << "Invalid option! Please type again (0 to back): ";
				getline(cin, s_choice);
			}

			int back_choice = int(s_choice[0]) - int('0');
			
			if(back_choice == 0) {
				Statistics();
				return;
			}
		}
	}
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