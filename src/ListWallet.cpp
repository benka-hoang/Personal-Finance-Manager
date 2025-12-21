#include "../include/ListWallet.h"

void ListWallet::Init() {
	size = 0;
	max_size = 10;
	wallet = new Wallet[max_size];
	Add_Wallet("Others");
	for (int i = 1; i < max_size; ++i)
		wallet[i].Init();
	return;
}

const int extra_space = 20;
void ListWallet::Add_Wallet(string name_wallet) {
	if(size<max_size)
	{
		wallet[size].Init();
		wallet[size].id=size;
		Convert_String_to_Char(wallet[size].name, name_wallet, 20);
		// Tao ham chuyen string -> char
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
		Convert_String_to_Char(wallet[size].name, name_wallet, 20);
		size++;
	}
	return;
}

int ListWallet::Total_Income(Date start_date, Date end_date)
{
	int total_income=0;
	for(int i=0;i<size;++i)
	{
		total_income+=wallet[i].Total_Income(start_date, end_date);
	}
	return total_income;
}

int ListWallet::Total_Expense(Date start_date, Date end_date)
{
	int total_expense=0;
	for(int i=0;i<size;++i)
	{
		total_expense+=wallet[i].Total_Expense(start_date, end_date);
	}
	return total_expense;
}

int ListWallet::Total_Balance(Date start_date, Date end_date)
{
	return ListWallet::Total_Income(start_date, end_date) - ListWallet::Total_Expense(start_date, end_date);
}

void ListWallet::SaveData(){
	ofstream fout;
	fout.open("data/data.bin", ios::binary);
	fout.write((char*)&size, 4);
	fout.write((char*)&max_size, 4);
	for (int i = 0; i < max_size; ++i) {
		fout.write((char*)&wallet[i].id, 4);
		fout.write((char*)&wallet[i].balance, 4);
		fout.write((char*)&wallet[i].size_inc, 4);
		fout.write((char*)&wallet[i].max_size_inc, 4);
		fout.write((char*)&wallet[i].size_exp, 4);
		fout.write((char*)&wallet[i].max_size_exp, 4);
		fout.write((char*)&wallet[i].size_source, 4);
		fout.write((char*)&wallet[i].max_size_source, 4);
		fout.write((char*)&wallet[i].size_category, 4);
		fout.write((char*)&wallet[i].max_size_category, 4);
	}
	for (int i = 0; i < max_size; ++i) {
		fout.write(wallet[i].name, 20);
	}
	for (int i = 0; i < max_size; ++i) {
		fout.write((char*)wallet[i].list_inc, sizeof(Income) * wallet[i].max_size_inc);
		fout.write((char*)wallet[i].list_exp, sizeof(Expense) * wallet[i].max_size_exp);
		fout.write((char*)wallet[i].inc_source, sizeof(Category) * wallet[i].max_size_source);
		fout.write((char*)wallet[i].exp_category, sizeof(Category) * wallet[i].max_size_category);
	}
	cout << "Save data successfully!" << "\n";
	fout.close();
	return;
}

void ListWallet::LoadData(){
	ifstream fin;
	fin.open("data/data.bin", ios::binary);
	fin.read((char*)&size, 4);
	fin.read((char*)&max_size, 4);
	list_wallet.wallet = new Wallet[max_size];
	for (int i = 0; i < max_size; ++i) {
		fin.read((char*)&wallet[i], 10 * sizeof(int));
	}
	for (int i = 0; i < max_size; ++i) {
		fin.read(wallet[i].name, 20);
	}
	for (int i = 0; i < max_size; ++i) {
		Wallet &w = wallet[i];
		w.list_inc = new Income[w.max_size_inc];
		w.list_exp = new Expense[w.max_size_exp];
		w.inc_source = new Category[w.max_size_source];
		w.exp_category = new Category[w.max_size_category];
		fin.read((char*)w.list_inc, sizeof(Income) * w.max_size_inc);
		fin.read((char*)w.list_exp, sizeof(Expense) * w.max_size_exp);
		fin.read((char*)w.inc_source, sizeof(Category) * w.max_size_source);
		fin.read((char*)w.exp_category, sizeof(Category) * w.max_size_category);
	}
	cout << "Load data successfully!" << "\n";
	fin.close();
	return;
}

void Convert_String_to_Char(char c[], const string &s, int length) {
	for (int i = 0; i < s.size(); ++i)
		c[i] = s[i];
	for (int i = s.size(); i < length; ++i)
		c[i] = ' ';
	return;
}

bool CompareEqual(char a[], char b[], int length){
	for (int i = 0; i < length; ++i) if (a[i] != b[i])
		return false;
	return true;
}

void AssignChar(char a[], char b[], int length){
	for (int i = 0; i < length; ++i)
		a[i] = b[i];
	return;
}

string Convert_Char_to_String(char c[], int length){
	int pos = length - 1;
	for (int i = length - 1; i >= 0; --i) if (c[i] != ' ') {
		pos = i;
		break;
	}
	string s;
	for (int i = 0; i <= pos; ++i)
		s.push_back(c[i]);
	return s;
}
