#include "Header.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    
    cout << "Объектов на входе в main: " << Library::getcount() << endl;

    Library arr[3] = {
        Library("Пикник у обочины","Cтругацкие", 999),Library("Трудно быть богом","Cтругацкие", 11.11),Library("ЕГЭ математика 2025","Поркшеян В.М.", 9999)
    };

    cout << "После создания статического массива: " << Library::getcount() << endl;

    string n = readstr("Введите название ");
    string a = readstr("Введите автора ");
    float c = readfloat("Введите цену ");

    Library* person = new Library(n.c_str(), a.c_str(), c);
    cout << endl << "Динамический объект: " << endl;
    person->print();

    int s;
    cout << "Ввести 1 для изменения цены" << endl;
    cout << s;
    if (s == 1) {
        person->setcost(readfloat(""));
        cout << endl;

        person->print();
    }
    

    cout << "После динамического создания объекта: "
        << Library::getcount() << endl;

    delete person;

    cout << "После удаления динамического объекта: " << Library::getcount() << endl;
}
