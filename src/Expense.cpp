#pragma once
#include"../include/ListWallet.h"
#include"../include/Expense.h"

Expense Info_to_Expense(Date &d, int &amount, Category &category, string &des) {
	Expense exp;
	exp.d = d;
	exp.amount = amount;
	exp.category = category;
	Convert_String_to_Char(exp.des, des, 50);
	return exp;
}

void Expense::Display() {
	cout << "Expense Information : ---------\n";
	cout << "     Date : "; d.OutputConsole();
	cout << "     Amount : "; cout << amount << "\n";
	cout << "     Source : "; category.Display();
	cout << "     Descrip : "; cout << des << "\n";
	return;
}
