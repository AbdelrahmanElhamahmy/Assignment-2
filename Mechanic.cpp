# include "Mechanic.h"

Mechanic::Mechanic()
{
    counter = 0;
    appointments = new Appointment[100];
}

bool Mechanic::isAvailable(Appointment appointment)
{
    for (int i = 0; i < counter; ++i)
    {
        if (appointment.h == appointments[i].h && appointment.mins == appointments[i].mins)
        {
            return false;
        }
    }

    return true;
}

void Mechanic::setCounter(int count)
{
    counter = count;
}

void Mechanic::setAppointment(Appointment appointment)
{
    appointments[counter++] = appointment;
}

int Mechanic::getCounter()
{
    return counter;
}

Appointment* Mechanic::getAppointment()
{
    return appointments;
}