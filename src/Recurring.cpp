#pragma once
#include"../include/Recurring.h"

Recurring Info_to_Recurring(string name, Date start_date, Date end_date, int type, int amount, Category category)
{
	Recurring Re = { name, start_date, end_date, type, amount, category };
	return Re;
}
