#pragma once
#include<iostream>
#include"../include/Income.h"

Income Info_to_Income(Date &d, int &amount, Category &source, string &des) {
	Income inc = { d, amount, source, des };
	return inc;
}