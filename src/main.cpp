#include<iostream>
#include<fstream>
#include"../include/Date.h"
#include"../include/Category.h"
#include"../include/Income.h"
#include"../include/Expense.h"
#include"../include/Wallet.h"
#include"../include/ListWallet.h"

using namespace std;

int main() {
	ListWallet list_wallet;
	list_wallet.Init();
	int id = 2;
	list_wallet.wallet[id].Add_Source("Luong");
	return 0;
}