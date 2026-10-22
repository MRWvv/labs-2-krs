#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <string>
#include <cstring>

using namespace::std;


class Library {
private:
    char* name;
    char* author;
    float cost;

    Library(const char* n, const char* a, float c);
    ~Library();

public:

    char* getauthor() { return author; };

    static Library* create(const char* n, const char* a, float c);
    friend void destroy(Library* с);
    friend void show(const Library& c);

    void print();
};

string readstr(string mes);
float readfloat(string mes);
int readint(string mes);
