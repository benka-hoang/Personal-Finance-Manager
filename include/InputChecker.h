#pragma once
#include"Income.h"
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

IncomeInfo CheckIncome(string wallet, string amount, string date, string source, string des);
void Output_Notification_Income(int case_in);