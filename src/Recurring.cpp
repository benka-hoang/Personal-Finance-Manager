#pragma once
#include"../include/ListWallet.h"
#include"../include/Recurring.h"

Recurring Info_to_Recurring(string name, Date start_date, Date end_date, int type, int amount, Category category)
{
	Recurring Re;
	Convert_String_to_Char(Re.name, name, 20);
	Re.start_date = start_date;
	Re.end_date = end_date;
	Re.type = type;
	Re.amount = amount;
	Re.category = category;
	return Re;
}
