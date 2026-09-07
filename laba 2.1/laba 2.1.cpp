#include "Header.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Ввести число струтур" << endl;
	int i = proverka_na_int();
	cout << "Нажать Enter для генерации" << endl;
	cin.get();
	cin.get();

	vector <student> arr;
	arr = gen_arr(i);
	print_sort_arr(arr, i);
	
	cout << "Ввести кол-во элементов Фибоначчи" << endl;
	int ii = proverka_na_int();
	cout << "Нажать Enter для генерации" << endl;
	cin.get();
	cin.get();
	algo(ii);

	cout << "Ввести 5 строк" << endl;
	input_palidrom();
}
