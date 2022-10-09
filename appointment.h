#include <iostream>
using namespace std;

struct Appointment
{
    int h;
    int mins;

    Appointment();
    Appointment(int hrs, int mns);
    int geth();
    int getmins();
};
