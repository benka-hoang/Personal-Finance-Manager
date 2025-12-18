#pragma once
#include"Wallet.h"

struct ListWallet{
	int size, max_size;
	Wallet* wallet;

	void Init();
	void Add_Wallet(string name_wallet);
	int Total_Income(Date start_date, Date end_date);
	int Total_Expense(Date start_date, Date end_date);
	int Total_Balance(Date start_date, Date end_date);
};