#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
//#include <windows.h>
#include <algorithm>

using namespace std;


struct student {
	string fio;
	string clas;
	int kolvo;
};

string get_s[];
string get_nms[];
string get_p[];
string get_c[];

vector <student> gen_arr(int n);
void print_sort_arr(vector <student> arr, int n);

int proverka_na_int();

void algo(int n);
bool palidrom(string s);
void input_palidrom();
//vector<string> f, vector<string> nms, vector<string> p, vector<string> c,