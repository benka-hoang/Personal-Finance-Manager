#pragma once
#include"Wallet.h"

struct ListWallet{
	int size, max_size;
	Wallet* wallet;

	void Init();
	void Add_Wallet(string name);
};