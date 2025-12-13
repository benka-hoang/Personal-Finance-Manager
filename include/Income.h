#pragma once
#include"Date.h"
#include"Category.h"

struct Income {
	Date d;
	int amount;
	Category source;
	string des;
};