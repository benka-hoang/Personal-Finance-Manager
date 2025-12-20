#include "../include/ListWallet.h"

void ListWallet::Init() {
	size = 0;
	max_size = 10;
	wallet = new Wallet[max_size];
	Add_Wallet("Others");
	return;
}

const int extra_space = 20;
void ListWallet::Add_Wallet(string name_wallet) {
	if(size<max_size)
	{
		wallet[size].Init();
		wallet[size].id=size;
		Convert_String_to_Char(wallet[size].name, name_wallet, 20);
		// Tao ham chuyen string -> char
		size++;
	}
	else
	{
		Wallet* new_list = new Wallet [max_size+extra_space]; 
		for(int i=0;i<max_size;++i)
		{
			new_list[i]=wallet[i];
		}
		delete[] wallet;
		wallet = new_list;
		max_size = max_size + extra_space;
		wallet[size].Init();
		wallet[size].id=size;
		Convert_String_to_Char(wallet[size].name, name_wallet, 20);
		size++;
	}
	return;
}

int ListWallet::Total_Income(Date start_date, Date end_date)
{
	int total_income=0;
	for(int i=0;i<size;++i)
	{
		total_income+=wallet[i].Total_Income(start_date, end_date);
	}
	return total_income;
}

int ListWallet::Total_Expense(Date start_date, Date end_date)
{
	int total_expense=0;
	for(int i=0;i<size;++i)
	{
		total_expense+=wallet[i].Total_Expense(start_date, end_date);
	}
	return total_expense;
}

int ListWallet::Total_Balance(Date start_date, Date end_date)
{
	return ListWallet::Total_Income(start_date, end_date) - ListWallet::Total_Expense(start_date, end_date);
}

void Convert_String_to_Char(char c[], const string &s, int length) {
	for (int i = 0; i < s.size(); ++i)
		c[i] = s[i];
	for (int i = s.size(); i < length; ++i)
		c[i] = ' ';
	return;
}

bool CompareEqual(char a[], char b[], int length){
	for (int i = 0; i < length; ++i) if (a[i] != b[i])
		return false;
	return true;
}

void AssignChar(char a[], char b[], int length){
	for (int i = 0; i < length; ++i)
		a[i] = b[i];
	return;
}
