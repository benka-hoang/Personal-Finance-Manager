#pragma once
#include<string>
#include<iomanip>
#include <chrono>
#include <thread>
#include<cstdlib>

using namespace std;

void GachNgang();
void ClearScreen();
bool CheckOption(string &s, int l, int r);
void Wait();

void Dashboard();
void UI();

void AddTransaction();
void AddRecurring();
void WalletManagement();
void CategoryManagement();
void Statistics();
void Settings();