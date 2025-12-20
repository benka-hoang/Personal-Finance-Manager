#pragma once
#include<string>
#include"Date.h"
#include"Income.h"
#include"Expense.h"
#include"Recurring.h"

struct Wallet {
	int id;
	char name[20];
	int balance;
	int size_inc, max_size_inc;
	int size_exp, max_size_exp;
	int size_source, max_size_source;
	int size_category, max_size_category;
	Income* list_inc;
	Expense* list_exp;
	Category* inc_source;
	Category* exp_category;
	
	void Display_Income();
	void Display_Expense();
	void Display_Source();
	void Display_Category();

	void Init();
	void Add_Source(string name_source);
	void Add_Category(string name_category);
	
	void Add_Income(Date d, int amount, Category source, string des);
	void Add_Expense(Date d, int amount, Category category, string des);

	void Delete_Income_Source(string name);
	void Delete_Expense_Category(string name);

	void Edit_Income_Source(string name_source, string name_edit);
	void Edit_Expense_Category(string name_category, string name_edit);

	void Add_Recurring(Recurring recur);

	int Total_Income(Date start_date, Date end_date);
	int Total_Expense(Date start_date, Date end_date);
	int Total_Balance(Date start_date, Date end_date);

	int Total_Income_Current_Month();
	int Total_Expense_Current_Month();
	int Total_Balance_Current_Month();

	int* Annual_Income_Source(int n, int* year);
	int* Annual_Expense_Category(int n, int* year);
	int Annual_Income(int n, int* year);
	int Annual_Expense(int n, int* year);
	int Annual_Balance(int n, int* year);
};