#include"../include/Wallet.h"

void Wallet::Init(){
	id = 0;
	name = "";
	balance = 0;
	size_inc = size_exp = size_source = size_category = 0;
	max_size_inc = max_size_exp = max_size_source = max_size_category = 10;
	list_inc = new Income[max_size_inc];
	list_exp = new Expense[max_size_exp];
	inc_source = new Category[max_size_inc];
	exp_category = new Category[max_size_category];
	Add_Source("Others");
	Add_Category("Others");
	return;
}

const int extra_space = 20;

void Wallet::Add_Source(string name_source) {
	if(size_source<max_size_source)
	{
		inc_source[size_source].id=size_source;
		inc_source[size_source].name=name_source;
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
		inc_source[size_inc].name=name_source;
		size_source++;
	}
	return;
}

void Wallet::Add_Category(string name_category) {
	if(size_category<max_size_category)
	{
		exp_category[size_category].id=size_category;
		exp_category[size_category].name=name_category;
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
		exp_category[size_category].name=name_category;
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
	for (int i = 0; i < size_inc; ++i) if (DatetoId(&inc.d) >= id) {
		pos = i;
		break;
	}
	for (int i = size_inc - 1; i >= pos; --i) list_inc[i + 1] = list_inc[i];
	list_inc[pos] = inc;
	return;
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
	for (int i = 0; i < size_exp; ++i) if (DatetoId(&exp.d) >= id) {
		pos = i;
		break;
	}
	for (int i = size_exp - 1; i >= pos; --i) list_exp[i + 1] = list_exp[i];
	list_exp[pos] = exp;
	return;
}

const Date limit_date={31, 12, 9999};
void Wallet::Add_Recurring(string name_recur, Date start_date, Date end_date, int type, int amount, Category category, string des)
{
	Date temp = start_date;
	if(end_date.day==0&&end_date.month==0&&end_date.year==0)
	{
		end_date=limit_date;
	}
	while(DatetoId(&temp)<=DatetoId(&end_date))
	{
		temp=ConvertDate(&temp);
		if(type==1)
		{
			Add_Income(temp, amount, category, des);
		}
		else if(type==-1)
		{
			Add_Expense(temp, amount, category, des);
		}
		temp.month++;
		if(temp.month==13) 
		{
			temp.month=1;
			temp.year++;
		}
	}
}

void Wallet::Auto_Update()
{
	return;
}
