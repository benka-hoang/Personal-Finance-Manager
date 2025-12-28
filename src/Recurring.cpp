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

void Recurring::DisplayUI(int id_wallet){
	cout << "Recurring Information :\n";
	cout << "      Wallet : "; cout << id_wallet << " " << Convert_Char_to_String(list_wallet.wallet[id_wallet].name, 20) << "\n";
	cout << "      Name : "; cout << Convert_Char_to_String(list_wallet.wallet[id_wallet].name, 20) << "\n";
	cout << "      Start date : "; start_date.OutputConsole();
	cout << "      End date : "; 
	if (end_date.day == 0) cout << "Empty\n"; else
		end_date.OutputConsole();
	cout << "      Amount : "; cout << amount << "\n";
	cout << "      Category : "; cout << category.id << " " << Convert_Char_to_String(category.name, 20) << "\n";
	return;
}
