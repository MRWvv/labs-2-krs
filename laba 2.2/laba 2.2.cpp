#include "Header.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    vector <ooo> data;

    cout << "¬ведите кол-во карточек" << endl;
    int n = proverka_na_int();
    cout << "¬ведите букву" << endl;
    string b = proverka_na_char();


    for (int i = 0; i < n; i++) {

        unsigned int born_yr = 1950 + rand() % 40;
        string number_car = to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
        string another = get_a[rand() % 5];
        string fio = get_s[rand() % 30] + " " + get_nms[rand() % 30] + " " + get_p[rand() % 30];
        string number_tel = "+79" + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
        unsigned int duty_time = 6 + rand() % 33;
        data.push_back(ooo(born_yr, number_car, another, fio, number_tel, duty_time));
    }

    cout << "\n=== —писок карточек ===\n" << endl;

    cout << "=========================================" << endl;
    cout << "—писок людей с фамилией на заданную букву" << endl;
    for (int i = 0; i < data.size(); i++) {
        if ((data[i].getfio()[0] == b[0]) || (data[i].getfio()[0] == toupper(b[0]))) {
            data[i].show();
        }

    }

    cout << endl;
    cin.get();
    cout << "—писок людей со стажем от 20 лет" << endl;

    for (int i = 0; i < data.size(); i++) {
        if (data[i].getduty_time() > 20) {
            data[i].show();
        }
    }


}