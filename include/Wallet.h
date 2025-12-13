#pragma once
#include<string>
#include"Date.h"
#include"Income.h"
#include"Expense.h"

struct Wallet {
	int id;
	string name;
	int balance;
	Income* list_inc;
	Expense* list_exp;
	Category* inc_source;
	Category* exp_category;

	void Add_Source(string name_source);
	void Add_Category(string name_category);
	void Add_Income(Date d, int amount, Category source, string des);
};