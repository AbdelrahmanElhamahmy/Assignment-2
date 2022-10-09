#include "customer.h"

Customer::Customer()
{

}

Customer::Customer(string name, int id, int age, int m, Appointment apt) : Person(name, id, age)
{
    mID = m;
    appointment = apt;
}

void Customer::setmID(int m)
{
    mID = m;
}

void Customer::setAppointment(Appointment apt)
{
    appointment = apt;
}

int Customer::getmID()
{
    return mID;
}

Appointment Customer::getAppointment()
{
    return appointment;
}

bool Customer::operator<(const Customer& currCust)
{
    if (appointment.h < currCust.appointment.h)
    {
        return true;
    }

    else if (appointment.h == currCust.appointment.h)
    {
        if (appointment.mins < currCust.appointment.mins)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool Customer::operator>(const Customer& currCust)
{
    if (appointment.h > currCust.appointment.h)
    {
        return true;
    }

    else if (appointment.h == currCust.appointment.h)
    {
        if (appointment.mins > currCust.appointment.mins)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool Customer::operator==(const Customer& currCust)
{
    if (appointment.h == currCust.appointment.h && appointment.mins == currCust.appointment.mins)
    {
        return true;
    }

    return false;
}