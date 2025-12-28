#include "../include/InputChecker.h"
#include "../include/Wallet.h"
#include "../include/ListWallet.h"

// 0: True
// 1: False (Don gian)
// 2: (Wallet) Wrong id
// 3: (Wallet) Wrong name
// 4: Wrong amount
// 5: Too much amount
// 6: (Source) Wrong id
// 7: (Source) Wrong name
// 8: des too long
// 9: Wrong date format
// 10: Invalid date
const int max_amount = 100000000;
IncomeInfo CheckIncome(string wallet, string amount, string date, string source, string des)
{
	IncomeInfo info; info.Init();
	Income& inc = info.inc;
	if (wallet.size() == 0 || amount.size() == 0 || date.size() == 0 || source.size() == 0 || des.size() == 0) {
		info.case_in = 1;
		return info;
	}
	if (wallet[0] == '#') {
		info.case_in = 2;
		if (wallet.size() == 1) return info;
		for (int i = 1; i < wallet.size(); ++i) if (!('0' <= wallet[i] && wallet[i] <= '9'))
			return info;
		info.id_wallet = 0;
		for (int i = 1; i < wallet.size(); ++i) {
			int c = wallet[i] - int('0');
			info.id_wallet = info.id_wallet * 10 + c;
			if (info.id_wallet >= list_wallet.size) return info;
		}
	}
	else {
		info.case_in = 3;
		char str[20];
		Convert_String_to_Char(str, wallet, 20);
		for (int i = 0; i < list_wallet.size; ++i) if (CompareEqual(list_wallet.wallet[i].name, str, 20)) {
			info.id_wallet = i;
			break;
		}
		if (info.id_wallet == -1) return info;
	}
	info.case_in = 4;
	for (int i = 0; i < amount.size(); ++i) if (!('0' <= amount[i] && amount[i] <= '9'))
		return info;
	info.case_in = 5;
	for (int i = 0; i < amount.size(); ++i) {
		int c = amount[i] - int('0');
		inc.amount = inc.amount * 10 + c;
		if (inc.amount > max_amount) return info;
	}
	Wallet& wall = list_wallet.wallet[info.id_wallet];
	if (source[0] == '#') {
		info.case_in = 6;
		if (source.size() == 1) return info;
		for (int i = 1; i < source.size(); ++i) if (!('0' <= source[i] && source[i] <= '9'))
			return info;
		inc.source.id = 0;
		for (int i = 1; i < source.size(); ++i) {
			int c = source[i] - int('0');
			inc.source.id = inc.source.id * 10 + c;
			if (inc.source.id >= wall.size_inc) return info;
		}
		inc.source = wall.inc_source[inc.source.id];
	}
	else {
		info.case_in = 7;
		char str[20];
		Convert_String_to_Char(str, source, 20);
		inc.source.id = -1;
		for (int i = 0; i < wall.size_source; ++i) if (CompareEqual(wall.inc_source[i].name, str, 20)) {
			inc.source.id = i;
			break;
		}
		if (inc.source.id == -1) return info;
		inc.source = wall.inc_source[inc.source.id];
	}
	info.case_in = 8;
	if (des.size() > 50) return info;
	Convert_String_to_Char(inc.des, des, 50);
	info.case_in = 0;
	return info;
}
