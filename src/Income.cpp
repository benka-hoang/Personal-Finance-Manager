#pragma once
#include<iostream>
#include"../include/Income.h"

Income Info_to_Income(Date &d, int &amount, Category &source, string &des) {
	Income inc = { d, amount, source, des };
	return inc;
}

void Income::Display(){
	cout << "Income Information : ---------\n";
	cout << "     Date : "; d.OutputConsole();
	cout << "     Amount : "; cout << amount << "\n";
	cout << "     Source : "; source.Display();
	cout << "     Descrip : "; cout << des << "\n";
	return;
}
