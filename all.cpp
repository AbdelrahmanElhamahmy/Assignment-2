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
    Person()
    {
    }

    Person(string n, int idd, int sen)
    {
        name = n;
        id = idd;
        age = sen;
    }

    void setName(string n)
    {
        name = n;
    }

    void setId(int idd)
    {
        id = idd;
    }

    void setAge(int sen)
    {
        age = sen;
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    int getAge()
    {
        return age;
    }

    void print()
    {
        cout << "Name is " << name << endl;
        cout << "Age is " << age << endl;
        cout << "ID is " << id << endl;

        return;
    }
};


class Customer : public Person
{
    int mID;
    Appointment appointment;

public:
    Customer()
    {

    }

    Customer(string name, int id, int age, int m, Appointment apt) : Person(name, id, age)
    {
        mID = m;
        appointment = apt;
    }

    void setmID(int m)
    {
        mID = m;
    }

    void setAppointment(Appointment apt)
    {
        appointment = apt;
    }

    int getmID()
    {
        return mID;
    }

    Appointment getAppointment()
    {
        return appointment;
    }

    bool operator<(const Customer& currCust)
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

    bool operator>(const Customer& currCust)
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

    bool operator==(const Customer& currCust)
    {
        if (appointment.h == currCust.appointment.h && appointment.mins == currCust.appointment.mins)
        {
            return true;
        }

        return false;
    }
};


class Mechanic : public Person
{
    int counter;
    Appointment* appointments;
public:
    Mechanic()
    {
        counter = 0;
        appointments = new Appointment[100];
    }

    bool isAvailable(Appointment appointment)
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

    void setCounter(int count)
    {
        counter = count;
    }

    void setAppointment(Appointment appointment)
    {
        appointments[counter++] = appointment;
    }

    int getCounter()
    {
        return counter;
    }

    Appointment* getAppointment()
    {
        return appointments;
    }
};


template <class temp>
class Queue
{
    temp* arr;
    int start, end, size;
public:

    Queue()
    {
        start = end = size = 0;
        arr = new temp[100];
    }

    void push(temp x) 
    {
        arr[end] = x;
        end++;
        size++;
    }

    temp pop()       
    {
        if (start == end)
        {
            cout << "Queue is empty" << endl;
            return temp();
        }

        size--;
        return arr[start++];
    }

    int getSize()
    {
        return size;
    }
};


string getMechanicName(int m, Mechanic* mechanics, int id)
{
    for (int i = 0; i < m; i++)
    {
        if (mechanics[i].getId() == id)
        {
            return mechanics[i].getName();
        }
    }

    return "";
}

int main()
{

    cout << "Enter the number of mechanics : ";
    int m;
    cin >> m;

    Mechanic* mechanics = new Mechanic[m];

    for (int i = 0; i < m; i++)
    {
        mechanics[i].setCounter(0);
        string name;

        cout << "Enter the name of mechanic " << i + 1 << ": ";
        cin >> name;

        mechanics[i].setName(name);
        mechanics[i].setId(i);
    }

    int currMechi = 0;

    cout << "Enter the number of customers : ";
    int customersNumber;
    cin >> customersNumber;

    Customer* customers = new Customer[customersNumber];

    for (int i = 0; i < customersNumber; i++)
    {
        cout << "Enter name of customer number " << i + 1 << ": ";
        string name;
        cin >> name;

        customers[i].setName(name);

        cout << "At what hour should customer number " << i + 1 << "'s appointment be: ";
        int hour;
        cin >> hour;
        while (hour < 0 || hour >23)
        {
            cout << "Enter a valid time 0-23: ";
            cin >> hour;
        }

        cout << "At what minute should customer number " << i + 1 << "'s appointment be: ";
        int mins;
        cin >> mins;

        while (mins < 0 || mins >59)
        {
            cout << "Enter a valid minute 0-59: ";
            cin >> mins;
        }

        Appointment appointment = Appointment(hour, mins);

        customers[i].setAppointment(appointment);

        while (mechanics[currMechi].isAvailable(appointment) == false)
        {
            currMechi++;
            if (currMechi == m)
            {
                currMechi = 0;
            }
        }

        customers[i].setmID(mechanics[currMechi].getId());
        mechanics[currMechi++].setAppointment(appointment);

        if (currMechi == m)
        {
            currMechi = 0;
        }
    }


    for (int i = 0; i < customersNumber; i++)
    {
        Customer currCust = customers[i];
        int id = currCust.getmID();

        cout << currCust.getName() << " should be assigned to " << getMechanicName(m, mechanics, id);

        Appointment appointment = currCust.getAppointment();

        cout << " At " << appointment.h << ":" << appointment.mins << endl;
    }


    cout << endl;
    cout << endl;

    Queue<Customer> q;

    bool* flags = new bool[customersNumber];

    for (int i = 0; i < customersNumber; i++)
    {
        flags[i] = false;
    }


    for (int i = 0; i < customersNumber; i++)
    {
        int customerIndex;
        Customer smalletCustomer;
        Appointment appointment = Appointment(24, 0);
        smalletCustomer.setAppointment(appointment);

        for (int j = 0; j < customersNumber; j++)
        {
            if (customers[j] < smalletCustomer && flags[j] == false)
            {
                customerIndex = j;
                smalletCustomer = customers[j];
            }
        }

        flags[customerIndex] = true;
        q.push(smalletCustomer);
    }

 
    while (q.getSize() > 0)
    {
        Customer currCust = q.pop();
        int id = currCust.getmID();

        cout << currCust.getName() << " should be assigned to " << getMechanicName(m, mechanics, id);

        Appointment appointment = currCust.getAppointment();

        cout << " At " << appointment.h << ":" << appointment.mins << endl;
    }

    return 0;
}