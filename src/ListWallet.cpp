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
		wallet[size].name=name_wallet;
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
		wallet[size].name=name_wallet;
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
