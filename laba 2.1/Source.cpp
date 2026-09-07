#include "Header.h"

string get_s[] = { "Иванов", "Петров", "Сидоров", "Смирнов", "Кузнецов",
        "Попов", "Васильев", "Соколов", "Михайлов", "Новиков",
        "Фёдоров", "Морозов", "Волков", "Алексеев", "Лебедев",
        "Семёнов", "Егоров", "Павлов", "Козлов", "Степанов",
        "Николаев", "Орлов", "Андреев", "Макаров", "Никитин",
        "Захаров", "Зайцев", "Соловьёв", "Борисов", "Яковлев" };

string get_nms[] = { "Александр", "Дмитрий", "Максим", "Сергей", "Андрей",
        "Алексей", "Артём", "Илья", "Кирилл", "Михаил",
        "Никита", "Егор", "Матвей", "Даниил", "Владислав",
        "Иван", "Евгений", "Николай", "Олег", "Роман",
        "Тимур", "Ярослав", "Глеб", "Лев", "Василий",
        "Георгий", "Антон", "Павел", "Виктор", "Степан" };

string get_p[] = { "Александрович", "Дмитриевич", "Максимович", "Сергеевич", "Андреевич",
        "Алексеевич", "Артемьевич", "Ильич", "Кириллович", "Михайлович",
        "Никитич", "Егорович", "Матвеевич", "Даниилович", "Владиславович",
        "Иванович", "Евгеньевич", "Николаевич", "Олегович", "Романович",
        "Тимурович", "Ярославович", "Глебович", "Львович", "Васильевич",
        "Георгиевич", "Антонович", "Павлович", "Викторович", "Степанович" };

string get_c[] = { "Мат. анализ","Cети", "Теор. вер.", "История", "Военка", "Геодезия", "Орг" };


vector <student> gen_arr(int n) {
    vector <student> arr;
    student s;
    string fullname;
    srand(time(0));

	for (int j = 0; j < n; j++) {
        s.fio = get_s[rand() % 30] + " " + get_nms[rand() % 30] + " " + get_p[rand() % 30];
        s.clas = get_c[rand() % 7];
        s.kolvo = rand() % 30;
        arr.push_back(s);
	}
    return arr;
}

void print_sort_arr(vector <student> arr,int n) {

    sort(arr.begin(), arr.end(),
        [](const student& a, const student& b) {
            return a.kolvo > b.kolvo;
        });

    for (size_t s = 0; s < n; s++) {
        cout << arr[s].fio << " | " << arr[s].clas << " | " << arr[s].kolvo << " пересдач" << endl;
    }
    cout << " " << endl;
}

int proverka_na_int() {
    int p;
    while (true) {
        cin >> p;
        if (cin.fail()) {
            cout << "Не верный ввод \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cout << "Ввод: " << p << "\n";
            return p;
        }
    }
}

void algo(int n) {
    vector <unsigned long long> arr = { 0,1 };
    for (int i = 2; i < n;i++) {
        arr.push_back(arr[i - 1] + arr[i - 2]);
    }
    for (int j = 0; j < arr.size();j++) {
        cout << j+1<< ": " << arr[j] << endl;
    }
    cout << endl;
    cout << n << "-ый/ий элемент последовательности --> " << arr[n - 1] << endl;
}

bool palidrom(string s) {
    if ((s.size() == 0) || (s.size() == 1)) {
        return true;
    }
    //if ((s[0] == s[s.size() - 1])) {
    ////    string ss = s.substr(1, s.length() - 2);
    ////    return palidrom(ss);
    ////}
    ////return false;

    return s[0] == s[s.size() - 1] && palidrom(s.substr(1, s.length() - 2));
}

void input_palidrom() {
    setlocale(LC_ALL, "Russian");
    vector <string> arr;
    string s;
    for (int i = 0; i < 5;i++) {
        cin >> s;
        arr.push_back(s);
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ": ";
        cout << boolalpha;
        cout << palidrom(arr[i]) << endl;
    }
}