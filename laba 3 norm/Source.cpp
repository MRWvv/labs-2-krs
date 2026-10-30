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

string get_a[] = { "нету примечаний", "хороший послужной список", "есть штрафы", "новичек", "старший водитель" };


string voditel::familiya() const {
    return fio.substr(0, fio.find(' '));
}

voditel& voditel::operator=(const voditel& drugoi) {
    tab_nomer = drugoi.tab_nomer;
    fio = drugoi.fio;
    born_yr = drugoi.born_yr;
    stazh = drugoi.stazh;
    number_car = drugoi.number_car;
    another = drugoi.another;
    return *this;
}

bool voditel::operator==(const voditel& drugoi) const {
    return (tab_nomer == drugoi.tab_nomer) && (fio == drugoi.fio) && (born_yr == drugoi.born_yr)
        && (stazh == drugoi.stazh) && (number_car == drugoi.number_car) && (another == drugoi.another);
}

// добавить n лет к стажу
voditel voditel::operator+(unsigned int n) const {
    voditel res(*this);
    res.stazh += n;
    return res;
}

// разница стажа двух водителей
int voditel::operator-(const voditel& drugoi) const {
    return (int)stazh - (int)drugoi.stazh;
}

voditel operator+(unsigned int n, const voditel& v) {
    return v + n;
}

ostream& operator<<(ostream& o, const voditel& v) {
    o << "Табельный номер:  " << v.tab_nomer << endl;
    o << "ФИО:              " << v.fio << endl;
    o << "Год рождения:     " << v.born_yr << endl;
    o << "Стаж:             " << v.stazh << " л." << endl;
    o << "Номер машины:     " << v.number_car << endl;
    o << "Примечание:       " << v.another << endl;
    o << "----------------------------------------" << endl;
    return o;
}


// список водителей со стажем больше n лет
vector <voditel> park::stazh_bolshe(unsigned int n) const {
    vector <voditel> res;
    for (int i = 0; i < data.size(); i++) {
        if (data[i].getstazh() > n) {
            res.push_back(data[i]);
        }
    }
    return res;
}

// список водителей, у которых фамилия начинается на букву b
vector <voditel> park::po_bukve(char b) const {
    vector <voditel> res;
    for (int i = 0; i < data.size(); i++) {
        if ((data[i].getfio()[0] == b) || (data[i].getfio()[0] == toupper(b))) {
            res.push_back(data[i]);
        }
    }
    return res;
}

double park::sredniy_stazh() const {
    if (data.size() == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += data[i].getstazh();
    }
    return sum / data.size();
}

voditel& park::operator[](int i) {
    if ((i < 0) || (i >= data.size())) {
        throw out_of_range("Неверный индекс");
    }
    return data[i];
}

const voditel& park::operator[](int i) const {
    if ((i < 0) || (i >= data.size())) {
        throw out_of_range("Неверный индекс");
    }
    return data[i];
}

park& park::operator=(const park& drugoi) {
    data = drugoi.data;
    return *this;
}

park& park::operator+=(const voditel& v) {
    data.push_back(v);
    return *this;
}

park park::operator+(const voditel& v) const {
    park res(*this);
    res += v;
    return res;
}

ostream& operator<<(ostream& o, const park& p) {
    for (int i = 0; i < p.data.size(); i++) {
        o << i + 1 << "." << endl << p.data[i];
    }
    return o;
}


int proverka_na_int() {
    double p;
    while (true) {
        cin >> p;
        if ((cin.fail()) || (p - (int)p)) {
            cout << "Ошибка ввода \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cout << "Введено: " << p << "\n";
            return (int)p;
        }
    }
}

string proverka_na_char() {
    string b;
    while (true) {
        cin >> b;

        if (b.size() == 1) {
            cout << "Введено: " << b << "\n";
            return b;
        }

        cout << "Только один символ\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void print_spisok(vector <voditel> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }
}
