#include "person.h"

class Mechanic : public Person
{
    int counter;
    Appointment* appointments;
public:
    Mechanic();
    bool isAvailable(Appointment appointment);
    void setCounter(int count);
    void setAppointment(Appointment appointment);
    int getCounter();
    Appointment* getAppointment();
};
