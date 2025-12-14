#pragma once
#include"../include/Expense.h"

Expense Info_to_Expense(Date &d, int &amount, Category &category, string &des) {
	Expense exp = { d, amount, category, des };
	return exp;
}