#include "Header.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    park p;

    cout << "Введите кол-во водителей" << endl;
    int n = proverka_na_int();
    cout << "Введите букву" << endl;
    string b = proverka_na_char();

    for (int i = 0; i < n; i++) {

        unsigned int tab_nomer = 1000 + i;
        string fio = get_s[rand() % 30] + " " + get_nms[rand() % 30] + " " + get_p[rand() % 30];
        unsigned int born_yr = 1950 + rand() % 40;
        unsigned int stazh = rand() % 35;
        string number_car = to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
        string another = get_a[rand() % 5];
        p += voditel(tab_nomer, fio, born_yr, stazh, number_car, another);
    }

    cout << "\n=== Список водителей ===\n" << endl;
    cout << p << endl;

    cout << "=========================================" << endl;
    cout << "Водители со стажем более 20 лет" << endl;
    vector <voditel> staj = p.stazh_bolshe(20);
    if (staj.size() == 0) {
        cout << "Таких водителей нет" << endl;
    }
    else {
        print_spisok(staj);
    }

    cout << "=========================================" << endl;
    cout << "Водители, у которых фамилия начинается на " << b << endl;
    vector <voditel> po_b = p.po_bukve(b[0]);
    if (po_b.size() == 0) {
        cout << "Таких водителей нет" << endl;
    }
    else {
        print_spisok(po_b);
    }

    cout << "=========================================" << endl;
    cout << "Проверка перегруженных операций" << endl;

    if (p.getkolvo() > 0) {
        cout << "\nПервый водитель через operator[]:" << endl;
        cout << p[0];

        voditel copy;
        copy = p[0];
        cout << "После copy = p[0]:" << endl << copy;
        cout << boolalpha;
        cout << "copy == p[0]: " << (copy == p[0]) << endl;

        copy.setfio("Копиев Копий Копиевич");
        cout << "После смены ФИО copy == p[0]: " << (copy == p[0]) << endl;
        cout << "copy != p[0]: " << (copy != p[0]) << endl;

        cout << "\nНа сколько лет увеличить стаж:" << endl;
        int k = proverka_na_int();
        cout << "p[0] + " << k << ":" << endl << p[0] + k;
        cout << k << " + p[0]:" << endl << k + p[0];

        cout << "p[0] < copy: " << (p[0] < copy) << endl;
        cout << "p[0] > copy: " << (p[0] > copy) << endl;
        cout << "Разница стажа p[0] - (p[0] + " << k << "): " << p[0] - (p[0] + k) << endl;
    }

    p += voditel(9999, "Новый Водитель Иванович", 1980, 25, "12345");
    park p2 = p + voditel(8888, "Ещё Один Петрович", 1975, 10, "54321", "новичек");
    cout << "\nВодителей после += : " << p.getkolvo() << ", после + : " << p2.getkolvo() << endl;
    cout << "Средний стаж: " << p.sredniy_stazh() << endl;

    cin.get();
    cin.get();
}
