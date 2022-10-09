#include "person.h"

class Customer : public Person
{
    int mID;
    Appointment appointment;

public:
    Customer();
    Customer(string name, int id, int age, int m, Appointment apt);
    void setmID(int m);
    void setAppointment(Appointment apt);
    int getmID();
    Appointment getAppointment();
    bool operator<(const Customer& currCust);
    bool operator>(const Customer& currCust);
    bool operator==(const Customer& currCust);
};
