#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>



using namespace std;
class ooo {
private:
	unsigned int born_yr;
	string number_car;
	string another;
	string fio;
	string number_tel;
	unsigned int duty_time;

public:

	ooo()
		: born_yr(0), number_car(""), another(""), fio(""), number_tel(""), duty_time(0) {
	}

	ooo(unsigned int yr, string numc, string an, string fio, string num, unsigned int time)
		: born_yr(yr), number_car(numc), another(an), fio(fio), number_tel(num), duty_time(time){
	}

	ooo(const ooo& drugoi)
		: born_yr(drugoi.born_yr), number_car(drugoi.number_car), another(drugoi.another), fio(drugoi.fio), number_tel(drugoi.number_tel), duty_time(drugoi.duty_time) {
	}

	unsigned int getborn_yr() const { return born_yr; }
	string getnumber_car() const { return number_car; }
	string getanother() const { return another; }
	string getfio() const { return fio; }
	string getnumber_tel() const { return number_tel; }
	unsigned int getduty_time() const { return duty_time; }


	void show() const {
		cout << "ФИО:              " << fio << endl;
		cout << "Год рождения:     " << born_yr << endl;
		cout << "Номер машины:     " << number_car << endl;
		cout << "Примечание:       " << another << endl;
		cout << "Телефон:          " << number_tel << endl;
		cout << "Cтаж:  " << duty_time << " л." << endl;
		cout << "----------------------------------------" << endl;
	}

};


string get_s[];
string get_nms[];
string get_p[];
int proverka_na_int();
string get_a[];
string proverka_na_char();