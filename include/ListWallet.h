#pragma once
#include<fstream>
#include"Wallet.h"

struct ListWallet{
	int size, max_size;
	Wallet* wallet;

	void Init();
	void Add_Wallet(string name_wallet); //OK
	int Total_Income(Date start_date, Date end_date);
	int Total_Expense(Date start_date, Date end_date);
	int Total_Balance(Date start_date, Date end_date);

	void SaveData();
	void ReadData();
	// Truyen toan bo du lieu -> Binary File
};

inline ListWallet list_wallet;

// length = 20 / 50
void Convert_String_to_Char(char c[], const string &s, int length);
bool CompareEqual(char a[], char b[], int length);
void AssignChar(char a[], char b[], int length);
string Convert_Char_to_String(char c[], int length);