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
	info.case_in = 9;
	if (!CheckDateFormat(date)) return info;
	info.case_in = 10;
	inc.d = ConvertStringToDate(date);
	if (!CheckDate(inc.d)) return info;
	info.case_in = 0;
	return info;
}

ExpenseInfo CheckExpense(string wallet, string amount, string date, string category, string des)
{
	ExpenseInfo info; info.Init();
	Expense& exp = info.exp;
	if (wallet.size() == 0 || amount.size() == 0 || date.size() == 0 || category.size() == 0 || des.size() == 0) {
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
		exp.amount = exp.amount * 10 + c;
		if (exp.amount > max_amount) return info;
	}
	Wallet& wall = list_wallet.wallet[info.id_wallet];
	if (category[0] == '#') {
		info.case_in = 6;
		if (category.size() == 1) return info;
		for (int i = 1; i < category.size(); ++i) if (!('0' <= category[i] && category[i] <= '9'))
			return info;
		exp.category.id = 0;
		for (int i = 1; i < category.size(); ++i) {
			int c = category[i] - int('0');
			exp.category.id = exp.category.id * 10 + c;
			if (exp.category.id >= wall.size_exp) return info;
		}
		exp.category = wall.exp_category[exp.category.id];
	}
	else {
		info.case_in = 7;
		char str[20];
		Convert_String_to_Char(str, category, 20);
		exp.category.id = -1;
		for (int i = 0; i < wall.size_category; ++i) if (CompareEqual(wall.exp_category[i].name, str, 20)) {
			exp.category.id = i;
			break;
		}
		if (exp.category.id == -1) return info;
		exp.category = wall.exp_category[exp.category.id];
	}
	info.case_in = 8;
	if (des.size() > 50) return info;
	Convert_String_to_Char(exp.des, des, 50);
	info.case_in = 9;
	if (!CheckDateFormat(date)) return info;
	info.case_in = 10;
	exp.d = ConvertStringToDate(date);
	if (!CheckDate(exp.d)) return info;
	info.case_in = 0;
	return info;
}

// 0: True
// 1: False (Don gian)
// 2: (Wallet) Wrong id
// 3: (Wallet) Wrong name
// 4: Wrong name (too long)
// 5: Invaild Date
// 6: Wrong type
// 7: Wrong amount
// 8: Too much amount
// 9: (Source) Wrong id
// 10: (Source) Wrong name
RecurringInfo CheckRecurr(string wallet, string name, string start_date, string end_date, string type, string amount, string category) {
	RecurringInfo info;
	info.Init();
	info.case_in = 1;
	if (wallet.size() == 0 || name.size() == 0 || start_date.size() == 0 || type.size() == 0 || amount.size() == 0
		|| category.size() == 0) {
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
	if (name.size() > 20) return info;
	Convert_String_to_Char(info.recurr.name, name, 20);

	Recurring& recurr = info.recurr;
	info.case_in = 5;
	if (!CheckDateFormat(start_date)) return info;
	recurr.start_date = ConvertStringToDate(start_date);
	if (end_date.size() != 0 && !CheckDateFormat(end_date)) return info;
	if (end_date.size() == 0) {
		recurr.end_date = { 0, 0, 0 };
	}
	else
		recurr.end_date = ConvertStringToDate(end_date);
	info.case_in = 6;
	if (type != "-1" && type != "+1") return info;
	if (type == "-1") {
		recurr.type = -1;
	}
	else
		recurr.type = +1;
	info.case_in = 7;
	for (int i = 0; i < amount.size(); ++i) if (!('0' <= amount[i] && amount[i] <= '9'))
		return info;
	info.case_in = 8;
	for (int i = 0; i < amount.size(); ++i) {
		int c = amount[i] - int('0');
		recurr.amount = recurr.amount * 10 + c;
		if (recurr.amount > max_amount) return info;
	}

	Wallet& wall = list_wallet.wallet[info.id_wallet];
	if (category[0] == '#') {
		info.case_in = 9;
		if (category.size() == 1) return info;
		for (int i = 1; i < category.size(); ++i) if (!('0' <= category[i] && category[i] <= '9'))
			return info;
		recurr.category.id = 0;
		int limit = wall.size_source;
		if (recurr.type == -1)
			limit = wall.size_category;
		cerr << recurr.type << " " << limit << "\n";
		for (int i = 1; i < category.size(); ++i) {
			int c = category[i] - int('0');
			recurr.category.id = recurr.category.id * 10 + c;
			if (recurr.category.id >= limit) return info;
		}
		if (recurr.type == -1)
			recurr.category = wall.exp_category[recurr.category.id];
		else
			recurr.category = wall.inc_source[recurr.category.id];
	}
	else {
		info.case_in = 10;
		char str[20];
		Convert_String_to_Char(str, category, 20);
		recurr.category.id = -1;
		if (recurr.type == +1) {
			for (int i = 0; i < wall.size_source; ++i) if (CompareEqual(wall.inc_source[i].name, str, 20)) {
				recurr.category.id = i;
				break;
			}
			if (recurr.category.id == -1) return info;
			recurr.category = wall.inc_source[recurr.category.id];
		}
		else {
			for (int i = 0; i < wall.size_category; ++i) if (CompareEqual(wall.exp_category[i].name, str, 20)) {
				recurr.category.id = i;
				break;
			}
			if (recurr.category.id == -1) return info;
			recurr.category = wall.exp_category[recurr.category.id];
		}
	}
	info.case_in = 0;
	return info;
}

void Output_Notification_Income(int case_in){
	if (case_in == 1) {
		cout << "Error input: Input fields cannot be empty. Please fill in all details." << '\n';
	}
	else if (case_in == 2) {
		cout << "Error input: Invalid Wallet ID. This ID does not exist." << '\n';
	}
	else if (case_in == 3) {
		cout << "Error input: Wallet Name not found. Please check the spelling." << '\n';
	}
	else if (case_in == 4) {
		cout << "Error input: Invalid Amount." << '\n';
	}
	else if (case_in == 5) {
		cout << "Error input: Amount too large. Max amount is " << max_amount << "." << '\n';
	}
	else if (case_in == 6) {
		cout << "Error input: Invalid Source ID. This Source ID does not exist in the selected Wallet." << '\n';
	}
	else if (case_in == 7) {
		cout << "Error input: Source Name not found. Please check the source name for this wallet." << '\n';
	}
	else if (case_in == 8) {
		cout << "Error input: Description is too long. Please limit to 50 characters." << '\n';
	}
	else if (case_in == 9) {
		cout << "Error input: Wrong Date format. Please use DD/MM/YYYY." << '\n';
	}
	else if (case_in == 10) {
		cout << "Error input: Invalid Date. Please check the day, month, and year values." << '\n';
	}
	return;
}

void Output_Notification_Recurring(int case_in) {
    if (case_in == 1) {
        cout << "Error input: Input fields cannot be empty. Please fill in all details." << '\n';
    }
    else if (case_in == 2) {
        cout << "Error input: Invalid Wallet ID. This ID does not exist." << '\n';
    }
    else if (case_in == 3) {
        cout << "Error input: Wallet Name not found. Please check the spelling." << '\n';
    }
    else if (case_in == 4) {
        // Logic: if (name.size() > 20)
        cout << "Error input: Recurring Name is too long. Please limit to 20 characters." << '\n';
    }
    else if (case_in == 5) {
        // Logic: CheckDateFormat(start_date) or CheckDateFormat(end_date)
        cout << "Error input: Invalid Date format. Please use DD/MM/YYYY." << '\n';
    }
    else if (case_in == 6) {
        // Logic: if (type != "-1" && type != "1")
        cout << "Error input: Invalid Type. Please enter '1' for Income or '-1' for Expense." << '\n';
    }
    else if (case_in == 7) {
        // Logic: Amount characters check
        cout << "Error input: Invalid Amount format. Amount must contain only digits." << '\n';
    }
    else if (case_in == 8) {
        // Logic: Amount > max_amount
        cout << "Error input: Amount too large. Max amount is " << max_amount << "." << '\n';
    }
    else if (case_in == 9) {
        // Logic: Category/Source ID check
        cout << "Error input: Invalid Category/Source ID. It does not exist in the selected Wallet." << '\n';
    }
    else if (case_in == 10) {
        // Logic: Category/Source Name lookup
        cout << "Error input: Category/Source Name not found. Please check the spelling." << '\n';
    }
    return;
}
