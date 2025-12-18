#pragma once
#include"../include/Expense.h"

Expense Info_to_Expense(Date &d, int &amount, Category &category, string &des) {
	Expense exp = { d, amount, category, des };
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
