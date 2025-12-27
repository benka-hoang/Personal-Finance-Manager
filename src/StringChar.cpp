#include"../include/StringChar.h"

void Convert_String_to_Char(char c[], const string &s, int length) {
	for (int i = 0; i < s.size(); ++i)
		c[i] = s[i];
	for (int i = s.size(); i < length; ++i)
		c[i] = ' ';
	return;
}

bool CompareEqual(char a[], char b[], int length) {
	for (int i = 0; i < length; ++i) if (a[i] != b[i])
		return false;
	return true;
}

void AssignChar(char a[], char b[], int length) {
	for (int i = 0; i < length; ++i)
		a[i] = b[i];
	return;
}

string Convert_Char_to_String(char c[], int length) {
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
