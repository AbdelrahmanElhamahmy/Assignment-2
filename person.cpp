# include "person.h"


Person::Person(string n, int idd, int sen)
{
    name = n;
    id = idd;
    age = sen;
}

void Person::setName(string n)
{
    name = n;
}

void Person::setId(int idd)
{
    id = idd;
}

void Person::setAge(int sen)
{
    age = sen;
}

string Person::getName()
{
    return name;
}

int Person::getId()
{
    return id;
}

int Person::getAge()
{
    return age;
}

void Person::print()
{
    cout << "Name is " << name << endl;
    cout << "Age is " << age << endl;
    cout << "ID is " << id << endl;

    return;
}
