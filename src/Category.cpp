#pragma once;
#include<iostream>
#include"../include/ListWallet.h"
#include"../include/Category.h"

void Category::Display(){
	cout << id << " " << Convert_Char_to_String(name, 20) << "\n";
	return;
}

void Category::Init() {
	id = 0;
	for (int i = 0; i < 20; ++i)
		name[i] = ' ';
	return;
}