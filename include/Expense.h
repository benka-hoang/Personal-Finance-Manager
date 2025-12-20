#pragma once
#include"Date.h"
#include"Category.h"

struct Expense {
	Date d;
	int amount;
	Category category;
	char des[50];

	void Display();
};

Expense Info_to_Expense(Date &d, int &amount, Category &category, string &des);