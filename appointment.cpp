#include "appointment.h"

Appointment::Appointment()
{
    h = 0;
    mins = 0;
}

Appointment::Appointment(int hrs, int mns)
{
    h = hrs;
    mins = mns;
}

int Appointment::geth()
{
    return h;
}

int Appointment::getmins()
{
    return mins;
}
