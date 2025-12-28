#include "../include/Date.h"
#include <string>
#include <chrono>
#include <ctime>
#include <algorithm>

void Write(ofstream& out, int num, int t) {
	int c[10]; int n = 0;
	while (num > 0) {
		c[++n] = num % 10;
		num = num / 10;
	}
	while (n < t) {
		++n;
		c[n] = 0;
	}
	while (n > t) --n;
	for (int i = n; i >= 1; --i) out << c[i];
	out << " ";
	return;
}

bool isLeap(int year) {
	if (year % 4 != 0) return false;
	if (year % 100 != 0) return true;
	if (year % 400 == 0) return true;
	return false;
}

int DatetoId(Date *d) {
	int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long long id = 0;
	for (int y = 1; y < d->year; y++) {
		if (isLeap(y)) id = id + 366; else id = id + 365;
	}
	for (int m = 1; m < d->month; m++) {
		id += mdays[m - 1];
		if (m == 2 && isLeap(d->year)) id++;
	}
	id += d->day;
	return id;
}

Date IdtoDate(int id) {
	int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date d;
	d.year = 1;
	while (true) {
		int daysInYear = isLeap(d.year) ? 366 : 365;
		if (id > daysInYear) {
			id -= daysInYear;
			d.year++;
		}
		else break;
	}
	d.month = 1;
	while (true) {
		int daysInMonth = mdays[d.month - 1];
		if (d.month == 2 && isLeap(d.year)) daysInMonth++;
		if (id > daysInMonth) {
			id -= daysInMonth;
			d.month++;
		}
		else break;
	}
	d.day = id;
	return d;
}

// 
Date ConvertDate(Date* d) {
	int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date new_date = *d;
	int day_this_month = mdays[d->month - 1];
	if (isLeap(d->year) && d->month == 2)
		day_this_month++;
	new_date.day = min(d->day, day_this_month);
	return new_date;
}

void outputDateWithFormat(ofstream& out, Date *d, string s) {
	//ymd
	const string Month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
		"Aug", "Sep", "Oct", "Nov", "Dec" };
	int cnt[3] = { 0, 0, 0 };
	char stt[10]; int n = 0;
	bool gach = false;
	for (int i = 0; i < int(s.size()); ++i) {
		if (s[i] == 'y') cnt[0]++;
		if (s[i] == 'M') cnt[1]++;
		if (s[i] == 'd') cnt[2]++;
		if (s[i] == '-') gach = true;
		if (s[i] != ' ' && s[i] != '-' && (i == 0 || s[i] != s[i - 1])) {
			++n;
			stt[n] = s[i];
		}
	}
	for (int i = 1; i <= 3; ++i) {
		if (stt[i] == 'y') {
			Write(out, d->year, cnt[0]);
		}
		if (stt[i] == 'd') {
			Write(out, d->day, cnt[2]);
		}
		if (stt[i] == 'M') {
			if (cnt[1] == 3) out << Month[d->month] << " ";
			else
				Write(out, d->month, cnt[1]);
		}
		if (gach && i != 3)
			out << "- ";
	}
	out << "\n";
	return;
}

int Compare(Date *a, Date *b) {
	return DatetoId(b) - DatetoId(a);
}

void Tomorrow(Date *d) {
	*d = IdtoDate(DatetoId(d) + 1);
	return;
}
void Yesterday(Date *d) {
	*d = IdtoDate(DatetoId(d) - 1);
	return;
}

void Increase(Date *d, int k) {
	*d = IdtoDate(DatetoId(d) + k);
	return;
}

void Decrease(Date *d, int k) {
	*d = IdtoDate(DatetoId(d) - k);
	return;
}

int ComputeSameYear(Date *d) {
	Date dd = { d->year, 1, 1 };
	return Compare(&dd, d);
}
Date Date1970 = { 1970, 1, 1 };
int Compute1970(Date *d) {
	return Compare(&Date1970, d);
}

string DateofWeek(Date *d) {
	const string Days[7] = { "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday", "Sunday" };
	return Days[(DatetoId(d) - 1) % 7];
}

bool DateEqual(Date *a, Date *b) {
	return (a->day == b->day && a->month == b->month && a->year == b->year);
}

Date Today() {
	// Get current time as time_point
	auto now = std::chrono::system_clock::now();

	// Convert to time_t (C-style time)
	std::time_t tt = std::chrono::system_clock::to_time_t(now);

	// Convert to local time (struct tm)
	std::tm local_tm;
	localtime_s(&local_tm, &tt);  // Visual Studio uses localtime_s
	Date d = { local_tm.tm_mday , local_tm.tm_mon + 1 , local_tm.tm_year + 1900 };

	return d;
}

bool Belong_to_Years(Date * d, int n, int * year){
	for (int i = 0; i < n; ++i) if (year[i] == d->year)
		return true;
	return false;
}

bool Belong_to_Month(Date d)
{
	int days_of_month[12]={31, 28, 31, 30, 31, 30 ,31 , 31, 30, 31, 30, 31};
	if(d.month<1||d.month>12) return false;
	int max_day=days_of_month[d.month-1];
	if(d.month==2&&isLeap(d.year)) max_day=29;
	if(d.day>max_day) return false;
	return true;
}

Date ConvertStringToDate(string s)
{
	Date d;
	d.day=0;
	d.month=0;
	d.year=0;
	int start=0;
	while(s[start]!='/')
	{
		d.day=d.day*10+int(s[start])-int('0');
		start++;
	}
	start++;
	while(s[start]!='/')
	{
		d.month=d.month*10+int(s[start])-int('0');
		start++;
	}
	start++;
	while(start<s.size())
	{
		d.year=d.year*10+int(s[start])-int('0');
		start++;
	}
	return d;
}

bool CheckDate(Date d)
{
	if(d.year<0) return false;
	if(d.day<0||!Belong_to_Month(d)) return false;
	return true;
}

bool CheckDateFormat(string s){
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '/')
		++cnt;
	if (cnt != 2) return false;
	for (int i = 0; i < s.size(); ++i) if (!('0' <= s[i] && s[i] <= '9' || s[i] == '/'))
		return false;
	if (s[0] == '/' || s[int(s.size()) - 1] == '/')
		return false;
	for (int i = 0; i < int(s.size()) - 1; ++i) if (s[i] == '/' && s[i + 1] == '/')
		return false;
	return true;
}