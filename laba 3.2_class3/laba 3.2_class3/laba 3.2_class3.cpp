
#include "Header.h"

int main()
{
    system("chcp 1251");

    int n = readint("Количество книг: ");

    Library** books = new Library * [n];

    for (int i = 0; i < n; i++)
    {
        string name, author;
        float cost;

        cout << endl << "Книга номер " << i + 1 << endl;
        name = readstr("Введите имя: ");
        author = readstr("Введите возраст: ");
        cost = readfloat("Введите стаж: ");


        books[i] = Library::create(name.c_str(), author.c_str(), cost);
    }

    cout << endl << "=== Список книг ===" << endl;

    for (int i = 0; i < n; i++)
    {
        books[i]->print();
    }

    cout << endl << "__Приватные поля__" << endl;
    if (n > 0)
    {
        show(*books[0]);
    }

    for (int i = 0; i < n; i++)
    {
        destroy(books[i]);
    }

    delete[] books;
}



