#include"../include/Wallet.h"
#include"../include/ListWallet.h"

void Wallet::Display_Income(){
	cout << "List of Income :\n";
	for (int i = 0; i < size_inc; ++i) {
		cout << i << ". "; list_inc[i].Display();
	}
	return;
}

void Wallet::Display_Expense(){
	cout << "List of Expense :\n";
	for (int i = 0; i < size_exp; ++i) {
		cout << i << ". "; list_exp[i].Display();
	}
	return;
}

void Wallet::Display_Source(){
	cout << "List of Source : \n";
	for (int i = 0; i < size_source; ++i) {
		cout << "     "; cout << i << ". "; inc_source[i].Display();
	}
	return;
}

void Wallet::Display_Category(){
	cout << "List of Category : \n";
	for (int i = 0; i < size_category; ++i) {
		cout << "     "; cout << i << ". "; exp_category[i].Display();
	}
	return;
}

void Wallet::Init(){
	id = 0;
	for (int i = 0; i < 20; ++i)
		name[i] = ' ';
	balance = 0;
	size_inc = size_exp = size_source = size_category = 0;
	max_size_inc = max_size_exp = max_size_source = max_size_category = 10;
	list_inc = new Income[max_size_inc];
	list_exp = new Expense[max_size_exp];
	inc_source = new Category[max_size_inc];
	exp_category = new Category[max_size_category];
	for (int i = 0; i < max_size_inc; ++i) list_inc[i].Init();
	for (int i = 0; i < max_size_exp; ++i) list_exp[i].Init();
	for (int i = 0; i < max_size_source; ++i) inc_source[i].Init();
	for (int i = 0; i < max_size_category; ++i) exp_category[i].Init();
	Add_Source("Others");
	Add_Category("Others");
	return;
}

const int extra_space = 20;

void Wallet::Add_Source(string name_source) {
	if(size_source<max_size_source)
	{
		inc_source[size_source].id=size_source;
		Convert_String_to_Char(inc_source[size_source].name, name_source, 20);
		size_source++;
	}
	else
	{
		Category* new_list = new Category [max_size_source+extra_space];
		for(int i=0;i<max_size_source;++i)
		{
			new_list[i]=inc_source[i];
		}
		delete[] inc_source;
		inc_source=new_list;
		max_size_source=max_size_source+extra_space;
		inc_source[size_inc].id=size_inc;
		Convert_String_to_Char(inc_source[size_source].name, name_source, 20);
		size_source++;
	}
	return;
}

void Wallet::Add_Category(string name_category) {
	if(size_category<max_size_category)
	{
		exp_category[size_category].id=size_category;
		Convert_String_to_Char(exp_category[size_category].name, name_category, 20);
		size_category++;
	}
	else
	{
		Category* new_list = new Category [max_size_category+extra_space];
		for(int i=0;i<max_size_category;++i) 
		{
			new_list[i]=exp_category[i];
		}
		delete[] exp_category;
		exp_category=new_list;
		max_size_category=max_size_category+extra_space;
		exp_category[size_category].id=size_category;
		Convert_String_to_Char(exp_category[size_category].name, name_category, 20);
		size_category++;
	}
	return;
}

void Wallet::Add_Income(Date d, int amount, Category source, string des) {
	balance = balance + amount;
	Income inc = Info_to_Income(d, amount, source, des);
	if (size_inc == max_size_inc) {
		Income* new_list = new Income[max_size_inc + extra_space];
		for (int i = 0; i < max_size_inc; ++i)
			new_list[i] = list_inc[i];
		delete[] list_inc;
		list_inc = new_list;
		max_size_inc = max_size_inc + extra_space;
	}
	int id = DatetoId(&d); int pos = size_inc;
	for (int i = 0; i < size_inc; ++i) if (DatetoId(&list_inc[i].d) >= id) {
		pos = i;
		break;
	}
	for (int i = size_inc - 1; i >= pos; --i) list_inc[i + 1] = list_inc[i];
	list_inc[pos] = inc;
	++size_inc;
	return;
}

const string Others = "Others";
void Wallet::Delete_Income_Source(string name)
{
	char name_char[20];
	Convert_String_to_Char(name_char, name, 20);
	for(int i=0;i<size_inc;++i)
	{
		if(CompareEqual(list_inc[i].source.name, name_char, 20)) 
		{
			Convert_String_to_Char(list_inc[i].source.name, Others, 20);
			list_inc[i].source.id=0;
		}
	}
	int id = -1;
	for(int i=0;i<size_source;++i)
	{
		if(inc_source[i].name==name) 
		{
			for(int j=i;j<size_source-1;++j) 
			{
				AssignChar(inc_source[j].name, inc_source[j + 1].name, 20);
				inc_source[j].id=j;
			}
			id = i;
		}
	}
	if (id == -1) return;
	size_source--;
	for (int i = 0; i < size_inc; ++i) if (list_inc[i].source.id > id) {
		list_inc[i].source.id--;
	}
}

void Wallet::Edit_Income_Source(string name_inc, string name_edit)
{
	char name_inc_char[20], name_edit_char[20];
	Convert_String_to_Char(name_inc_char, name_inc, 20);
	Convert_String_to_Char(name_edit_char, name_edit, 20);
	for(int i=0;i<size_source;++i)
	{
		if (CompareEqual(inc_source[i].name, name_inc_char, 20))
			AssignChar(inc_source[i].name, name_edit_char, 20);
	}
	for(int i=0;i<size_inc;++i)
	{
		if (CompareEqual(list_inc[i].source.name, name_inc_char, 20))
			AssignChar(list_inc[i].source.name, name_edit_char, 20);
	}
}

void Wallet::Add_Expense(Date d, int amount, Category category, string des) {
	balance = balance - amount;
	Expense exp = Info_to_Expense(d, amount, category, des);
	if (size_exp == max_size_exp) {
		Expense* new_list = new Expense[max_size_exp + extra_space];
		for (int i = 0; i < max_size_exp; ++i)
			new_list[i] = list_exp[i];
		delete[] list_exp;
		list_exp = new_list;
		max_size_exp = max_size_exp + extra_space;
	}
	int id = DatetoId(&d); int pos = size_exp;
	for (int i = 0; i < size_exp; ++i) if (DatetoId(&list_exp[i].d) >= id) {
		pos = i;
		break;
	}
	for (int i = size_exp - 1; i >= pos; --i) list_exp[i + 1] = list_exp[i];
	list_exp[pos] = exp;
	++size_exp;
	return;
}

void Wallet::Delete_Expense_Category(string name)
{
	char name_char[20];
	Convert_String_to_Char(name_char, name, 20);
	for(int i=0;i<size_exp;++i)
	{
		if(CompareEqual(list_exp[i].category.name, name_char, 20)){
			Convert_String_to_Char(list_exp[i].category.name, Others, 20);
			list_exp[i].category.id=0;
		}
	}
	int id = -1;
	for(int i=0;i<size_category;++i)
	{
		if(exp_category[i].name==name)
		{
			for(int j=i;j<size_category-1;++j) 
			{
				AssignChar(exp_category[j].name, exp_category[j + 1].name, 20);
				exp_category[j].id=j;
			}
			id = i;
		}
	}
	if (id == -1) return;
	size_category--;
	for (int i = 0; i < size_exp; ++i) if (list_exp[i].category.id > id) {
		list_exp[i].category.id--;
	}
}

void Wallet::Edit_Expense_Category(string name_category, string name_edit)
{
	char name_exp_char[20], name_edit_char[20];
	Convert_String_to_Char(name_exp_char, name_category, 20);
	Convert_String_to_Char(name_edit_char, name_edit, 20);
	for(int i=0;i<size_category;++i)
	{
		if (CompareEqual(exp_category[i].name, name_exp_char, 20))
			AssignChar(exp_category[i].name, name_edit_char, 20);
	}
	for(int i=0;i<size_exp;++i)
	{
		if (CompareEqual(list_exp[i].category.name, name_exp_char, 20))
			AssignChar(list_exp[i].category.name, name_edit_char, 20);
	}
}

const Date limit_date = { 31, 12, 9999 };
void Wallet::Add_Recurring(Recurring Recurr)
{
	Date temp = Recurr.start_date;
	if (Recurr.end_date.day == 0 && Recurr.end_date.month == 0 && Recurr.end_date.year == 0)
	{
		Recurr.end_date = limit_date;
	}
	while (DatetoId(&temp) <= DatetoId(&Recurr.end_date))
	{
		Date cur = ConvertDate(&temp);
		if (Recurr.type == 1)
		{
			Add_Income(cur, Recurr.amount, Recurr.category, Convert_Char_to_String(Recurr.name, 20));
		}
		else if (Recurr.type == -1)
		{
			Add_Expense(cur, Recurr.amount, Recurr.category, Recurr.name);
		}
		temp.month++;
		if (temp.month == 13)
		{
			temp.month = 1;
			temp.year++;
		}
	}
}

int Wallet::Total_Income(Date start_date, Date end_date) {
	int total_inc = 0;
	for (int i = 0; i < size_inc; ++i)
	{
		if (DatetoId(&list_inc[i].d) >= DatetoId(&start_date) && DatetoId(&list_inc[i].d) <= DatetoId(&end_date))
		{
			total_inc += list_inc[i].amount;
		}
	}
	return total_inc;
}

int Wallet::Total_Expense(Date start_date, Date end_date) {
	int total_exp = 0;
	for (int i = 0; i < size_exp; ++i)
	{
		if ((DatetoId(&list_exp[i].d) >= DatetoId(&start_date)) && (DatetoId(&list_exp[i].d) <= DatetoId(&end_date)))
		{
			total_exp += list_exp[i].amount;
		}
	}
	return total_exp;
}
int Wallet::Total_Balance(Date start_date, Date end_date) {
	return Wallet::Total_Income(start_date, end_date) - Wallet::Total_Expense(start_date, end_date);
}

int Wallet::Total_Income_Current_Month()
{
	Date end_date = Today();
	Date start_date;
	start_date.day = 1;
	start_date.month = end_date.month;
	start_date.year = end_date.year;
	return Total_Income(start_date, end_date);
}

int Wallet::Total_Expense_Current_Month()
{
	Date end_date = Today();
	Date start_date;
	start_date.day = 1;
	start_date.month = end_date.month;
	start_date.year = end_date.year;
	return Total_Expense(start_date, end_date);
}

int Wallet::Total_Balance_Current_Month()
{
	Date end_date = Today();
	Date start_date;
	start_date.day = 1;
	start_date.month = end_date.month;
	start_date.year = end_date.year;
	return Total_Balance(start_date, end_date);
}

int * Wallet::Annual_Income_Source(int n, int * year){
	int *sum_inc_source = new int[size_source];
	for (int i = 0; i < size_source; ++i)
		sum_inc_source[i] = 0;
	for (int i = 0; i < size_inc; ++i) if (Belong_to_Years(&list_inc[i].d, n, year)) {
		sum_inc_source[list_inc[i].source.id] += list_inc[i].amount;
	}
	return sum_inc_source;
}

int * Wallet::Annual_Expense_Category(int n, int * year){
	int *sum_exp_source = new int[size_source];
	for (int i = 0; i < size_source; ++i)
		sum_exp_source[i] = 0;
	for (int i = 0; i < size_exp; ++i) if (Belong_to_Years(&list_exp[i].d, n, year)) {
		sum_exp_source[list_exp[i].category.id] += list_exp[i].amount;
	}
	return sum_exp_source;
}

int Wallet::Annual_Income(int n, int * year) {
	int sum = 0;
	for (int i = 0; i < size_inc; ++i) if (Belong_to_Years(&list_inc[i].d, n, year)) {
		sum = sum + list_inc[i].amount;
	}
	return sum;
}

int Wallet::Annual_Expense(int n, int * year) {
	int sum = 0;
	for (int i = 0; i < size_inc; ++i) if (Belong_to_Years(&list_exp[i].d, n, year)){
		sum = sum + list_exp[i].amount;
	}
	return sum;
}

int Wallet::Annual_Balance(int n, int * year){
	int sum = Annual_Income(n, year) - Annual_Expense(n, year);
	return sum;
}
