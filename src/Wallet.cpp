#include"../include/Wallet.h"

void Wallet::Init(){
	id = 0;
	name = "";
	balance = 0;
	size_inc = size_exp = size_source = size_category = 0;
	max_size_inc = max_size_exp = max_size_source = max_size_category = 10;
	list_inc = new Income[max_size_inc];
	list_exp = new Expense[max_size_exp];
	inc_source = new Category[max_size_inc];
	exp_category = new Category[max_size_category];
	return;
}

void Wallet::Add_Source(string name_source) {
	return;
}

void Wallet::Add_Category(string name_category) {
	return;
}

const int extra_space = 20;
void Wallet::Add_Income(Date d, int amount, Category source, string des) {
	balance = balance + amount;
	Income inc = Info_to_Income(d, amount, source, des);
	if (size_inc < max_size_inc) {
		list_inc[size_inc] = inc;
		++size_inc;
	}
	else {
		Income* new_list = new Income[max_size_inc + extra_space];
		for (int i = 0; i < max_size_inc; ++i)
			new_list[i] = list_inc[i];
		delete[] list_inc;
		list_inc = new_list;
		max_size_inc = max_size_inc + extra_space;
		list_inc[size_inc] = inc;
		++size_inc;
	}
	return;
}

void Wallet::Add_Expense(Date d, int amount, Category category, string des){
	balance = balance - amount;
	Expense exp = Info_to_Expense(d, amount, category, des);
	if (size_exp < max_size_exp) {
		list_exp[size_exp] = exp;
		++size_exp;
	}
	else {
		Expense* new_list = new Expense[max_size_exp + extra_space];
		for (int i = 0; i < max_size_exp; ++i)
			new_list[i] = list_exp[i];
		delete[] list_exp;
		list_exp = new_list;
		max_size_exp = max_size_exp + extra_space;
		list_exp[size_exp] = exp;
		++size_exp;
	}
	return;
}
