#include "Header.h";

Library::Library(const char* n, const char* a, float c) {
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);

	author = new char[strlen(a) + 1];
	strcpy_s(author, strlen(a) + 1, a);

	cost = c;

}

Library::~Library() {
	delete[] name;
	delete[] author;
}

Library* Library::create(const char* n, const char* a, float c) {
	return new Library(n, a, c);
}

void destroy(Library* с) {
	delete с;
};


void show(const Library& c) {
	cout << c.name << "от: " << c.author << "за: " << c.cost << "рублей " << endl;
};

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

int readint(string mes) {
	cout << mes;
	double p;
	while (true) {
		cin >> p;
		if ((cin.fail()) || (p - (int)p)) {
			cout << "Ошибка ввода \n";
			cin.clear();
			cin.ignore(10000000000, '\n');
		}
		else {
			cout << "Введено: " << p << "\n";
			return (int)p;
		}
	}
}
