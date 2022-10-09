#include <iostream>
using namespace std;
struct Appointment
{
    int h;
    int mins;

    Appointment()
    {

    }

    Appointment(int hrs, int mns)
    {
        h = hrs;
        mins = mns;
    }

    int geth()
    {
        return h;
    }

    int getmins()
    {
        return mins;
    }
};


class Person
{
    string name;
    int id;
    int age;

public:
    Person();
    Person(string n, int idd, int sen);
    void setName(string n);
    void setId(int idd);
    void setAge(int sen);
    string getName();
    int getId();
    int getAge();
    void print();
};

