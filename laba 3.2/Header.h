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
    static int count;
public:

    Library(const char* n, const char* a, float c);
    ~Library();

    void setcost(float a);
    char* getauthor() { return author; };
    
    static Library* create(const char* n, const char* a, float c);
    
    static int getcount();
    void print();
};

string readstr(string mes);
float readfloat(string mes);