#pragma once
#include"Date.h"
#include"Category.h"

struct Recurring {
	char name[20];
	Date start_date, end_date;
	int type;
	int amount;
	Category category;
};

Recurring Info_to_Recurring(string name, Date start_date, Date end_date, int type, int amount, Category category);