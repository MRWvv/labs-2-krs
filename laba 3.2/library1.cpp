#include "Header.h";


int Library::count = 0;

Library::Library(const char* n, const char* a, float c) {
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);

	author = new char[strlen(a) + 1];
	strcpy_s(author, strlen(a) + 1, a);

	cost = c;

	count++;
}

Library::~Library() {
	delete[] name;
	delete[] author;
	count--;
}

void Library::setcost(float a) {
	cost = a;
}

Library* Library::create(const char* n, const char* a, float c) {
	return new Library(n, a, c);
}

int Library::getcount() {
	return count;
}
;

void Library::print()
{
	cout << "Название - " << name << endl;
	cout << "Автор - " << author << endl;
	cout << "Цена - " << cost << endl;
}

string readstr(string mes)
{
	bool err = true;
	while (err)
	{
		string x;
		cout << mes;
		getline(cin, x);

		if (x.empty())
		{
			cout << "Строка не должна быть пустой!" << endl;
			continue;
		}

		bool err = false;
		return x;
	}
}

float readfloat(string mes)
{
	float x;
	while (true)
	{
		cout << mes;
		cin >> x;
		if (cin.fail() || x <= 0)
		{
			cout << "Некорректный ввод" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			return x;
		}
	}
}