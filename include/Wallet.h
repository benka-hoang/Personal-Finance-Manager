#pragma once
#include<string>
#include"Income.h"
#include"Expense.h"

struct Wallet {
	int id;
	string name;
	Income* list_inc;
	Expense* list_exp;
	Category* inc_source;
	Category* exp_category;
};