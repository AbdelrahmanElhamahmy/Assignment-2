#include "person.h"
#include "customer.h"
#include "mechanic.h"
#include "queue.h"


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
        while (hour<0 || hour >23)
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

    // Printing Customers before sorting in the queue
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

    // inserting customer into the queue by minimum appointment
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

    // Printing Customers sorted in the queue
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