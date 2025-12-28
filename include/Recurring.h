#pragma once
#include"Date.h"
#include"Category.h"

struct Recurring {
	char name[20];
	Date start_date, end_date;
	int type;
	int amount;
	Category category;

	void Init() {
		for (int i = 0; i < 20; ++i) {
			name[i] = ' ';
		}
		start_date = { 1, 1, 1 };
		end_date = { 0, 0, 0 };
		type = 0;
		amount = 0;
		category.Init();
		return;
	}
};

Recurring Info_to_Recurring(string name, Date start_date, Date end_date, int type, int amount, Category category);