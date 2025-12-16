#include "../include/ListWallet.h"

void ListWallet::Init() {
	size = 0;
	max_size = 10;
	wallet = new Wallet[max_size];
	return;
}

const int extra_space = 20;
void ListWallet::Add_Wallet(string name) {
	if(size<max_size)
	{
		wallet[size].Init();
		wallet[size].id=size;
		wallet[size].name=name;
		size++;
	}
	else
	{
		Wallet* new_list = new Wallet [max_size+extra_space]; 
		for(int i=0;i<max_size;++i)
		{
			new_list[i]=wallet[i];
		}
		delete[] wallet;
		wallet = new_list;
		max_size = max_size + extra_space;
		wallet[size].Init();
		wallet[size].id=size;
		wallet[size].name=name;
		size++;
	}
	return;
}