#pragma once
#include<string>
#include"Date.h"
#include"Income.h"
#include"Expense.h"

struct Wallet {
	int id;
	string name;
	int balance;
	int size_inc, max_size_inc;
	int size_exp, max_size_exp;
	int size_source, max_size_source;
	int size_category, max_size_category;
	Income* list_inc;
	Expense* list_exp;
	Category* inc_source;
	Category* exp_category;
	

	void Init();
	void Add_Source(string name_source);
	void Add_Category(string name_category);
	void Add_Income(Date d, int amount, Category source, string des);
	void Delete_Income_Source(string name);
	void Edit_Income_Source(string name_source, string name_edit);
	void Add_Expense(Date d, int amount, Category category, string des);
	void Delete_Expense_Category(string name);
	void Edit_Expense_Category(string name_category, string name_edit);
	void Add_Recurring(string name_recur, Date start_date, Date end_date, int type, int amount, Category category);
	void Auto_Update(); //update all wallets
};