#pragma once
#include<fstream>
#include"StringChar.h"
#include"Wallet.h"

struct ListWallet{
	int size, max_size;
	Wallet* wallet;

	void Init();
	void Add_Wallet(string name_wallet); //OK
	int Total_Income(Date start_date, Date end_date);
	int Total_Expense(Date start_date, Date end_date);
	int Total_Balance(Date start_date, Date end_date);

	void Display();

	void SaveData();
	void LoadData();
	// Truyen toan bo du lieu -> Binary File
};

inline ListWallet list_wallet;

