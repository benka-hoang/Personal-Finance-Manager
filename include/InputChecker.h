#pragma once
#include"Income.h"
#include"Expense.h"
#include"Recurring.h"
#include<string>

struct IncomeInfo {
	int case_in;
	int id_wallet;
	Income inc;

	void Init() {
		case_in = -1, id_wallet = -1;
		inc.Init();
	}
};

struct ExpenseInfo {
	int case_in;
	int id_wallet;
	Expense exp;

	void Init() {
		case_in = -1, id_wallet = -1;
		exp.Init();
	}
};

struct RecurringInfo {
	int case_in;
	int id_wallet;

	Recurring recurr;

	void Init() {
		case_in = -1, id_wallet = -1;
		recurr.Init();
	}
};

IncomeInfo CheckIncome(string wallet, string amount, string date, string source, string des);
ExpenseInfo CheckExpense(string wallet, string amount, string date, string category, string des);
RecurringInfo CheckRecurr(string wallet, string name, string start_date, string end_date, string type, string amount, string category);
void Output_Notification_Income(int case_in);
void Output_Notification_Recurring(int case_in);