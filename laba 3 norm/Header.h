#pragma once
#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include <stdexcept>



using namespace std;
class voditel {
private:
	unsigned int tab_nomer;
	string fio;
	unsigned int born_yr;
	unsigned int stazh;
	string number_car;
	string another;

public:

	voditel()
		: tab_nomer(0), fio(""), born_yr(0), stazh(0), number_car(""), another("") {
	}

	voditel(unsigned int tab, string f, unsigned int yr, unsigned int st, string numc)
		: tab_nomer(tab), fio(f), born_yr(yr), stazh(st), number_car(numc), another("") {
	}

	voditel(unsigned int tab, string f, unsigned int yr, unsigned int st, string numc, string an)
		: tab_nomer(tab), fio(f), born_yr(yr), stazh(st), number_car(numc), another(an) {
	}

	voditel(const voditel& drugoi)
		: tab_nomer(drugoi.tab_nomer), fio(drugoi.fio), born_yr(drugoi.born_yr), stazh(drugoi.stazh), number_car(drugoi.number_car), another(drugoi.another) {
	}

	unsigned int gettab_nomer() const { return tab_nomer; }
	string getfio() const { return fio; }
	unsigned int getborn_yr() const { return born_yr; }
	unsigned int getstazh() const { return stazh; }
	string getnumber_car() const { return number_car; }
	string getanother() const { return another; }

	void settab_nomer(unsigned int tab) { tab_nomer = tab; }
	void setfio(string f) { fio = f; }
	void setborn_yr(unsigned int yr) { born_yr = yr; }
	void setstazh(unsigned int st) { stazh = st; }
	void setnumber_car(string numc) { number_car = numc; }
	void setanother(string an) { another = an; }

	string familiya() const;

	voditel& operator=(const voditel& drugoi);

	bool operator==(const voditel& drugoi) const;
	bool operator!=(const voditel& drugoi) const { return !(*this == drugoi); }
	bool operator<(const voditel& drugoi) const { return stazh < drugoi.stazh; }
	bool operator>(const voditel& drugoi) const { return stazh > drugoi.stazh; }

	voditel operator+(unsigned int n) const;
	int operator-(const voditel& drugoi) const;
	friend voditel operator+(unsigned int n, const voditel& v);

	friend ostream& operator<<(ostream& o, const voditel& v);
};


class park {
private:
	vector <voditel> data;

public:

	park() {
	}

	park(vector <voditel> d)
		: data(d) {
	}

	park(const park& drugoi)
		: data(drugoi.data) {
	}

	int getkolvo() const { return data.size(); }
	void add(voditel v) { data.push_back(v); }

	vector <voditel> stazh_bolshe(unsigned int n) const;
	vector <voditel> po_bukve(char b) const;
	double sredniy_stazh() const;

	voditel& operator[](int i);
	const voditel& operator[](int i) const;

	park& operator=(const park& drugoi);
	park& operator+=(const voditel& v);
	park operator+(const voditel& v) const;

	friend ostream& operator<<(ostream& o, const park& p);
};


extern string get_s[];
extern string get_nms[];
extern string get_p[];
extern string get_a[];
int proverka_na_int();
string proverka_na_char();
void print_spisok(vector <voditel> arr);
