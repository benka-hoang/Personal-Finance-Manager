#pragma once
#include<iostream>
#include"../include/ListWallet.h"
#include"../include/Income.h"

Income Info_to_Income(Date &d, int &amount, Category &source, string &des) {
	Income inc; 
	inc.d = d;
	inc.amount = amount;
	inc.source = source;
	Convert_String_to_Char(inc.des, des, 50);
	return inc;
}

void Income::Display(){
	cout << "Income Information :\n";
	cout << "     Date : "; d.OutputConsole();
	cout << "     Amount : "; cout << amount << "\n";
	cout << "     Source : "; source.Display();
	cout << "     Description : "; cout << Convert_Char_to_String(des, 50) << "\n";
	return;
}

void Income::DisplayUI(int id_wallet) {
	cout << "Income Information :\n";
	cout << "     Wallet : "; cout << id_wallet << " " << Convert_Char_to_String(list_wallet.wallet[id_wallet].name, 20) << "\n";
	cout << "     Date : "; d.OutputConsole();
	cout << "     Amount : "; cout << amount << "\n";
	cout << "     Source : "; source.Display();
	cout << "     Description : "; cout << Convert_Char_to_String(des, 50) << "\n";
	return;
}

void Income::Init(){
	d = { 1, 1, 1 };
	amount = 0;
	source.Init();
	for (int i = 0; i < 50; ++i)
		des[i] = ' ';
	return;
}
