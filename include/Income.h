#pragma once
#include"Date.h"
#include"Category.h"

struct Income {
	Date d;
	int amount;
	Category source;
	char des[50];

	void Display();
	void DisplayUI(int id_wallet);
	void Init();
};

Income Info_to_Income(Date &d, int &amount, Category &source, string &des);