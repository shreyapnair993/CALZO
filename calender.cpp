#include <iostream>
#include <string>
using namespace std;

class calender { 
public:
    int dayNumber(int day, int month, int year)
    {
        static int A[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        year -= month < 3;
        return (year + year / 4 - year / 100 + year / 400 + A[month - 1] + day) % 7;
    } //Tomohiko Sakamoto's algorithm
    string getMonthName(int monthNumber) // to display every month in calender
    {
        string M[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        return (M[monthNumber]);
    }
    int numberOfDays(int monthNumber, int year)
    {
        switch (monthNumber)
        {
        case 0:
        case 2:
        case 4:
        case 6:
        case 7:
        case 9:
        case 11: return(31); // for months of 31 days
            break;
        case 1:
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
                return (29);
            else
                return (28);
            break; // for february
        case 3:
        case 5:
        case 8:
        case 10: return(30); // for months of 30 days
            break;
        }
    }
    void printCalendar(int year) // definition of printCalender function
    {
        cout << "\t Calendar - Year " << year;
        int days;
        int current = dayNumber(1, 1, year); // days month and year
        for (int i = 0; i < 12; i++)
        {
            days = numberOfDays(i, year);
            cout << endl << "\t ----X----" << getMonthName(i).c_str() << "----X---- \t\t" << endl;
            cout << "   Sun  Mon  Tue   Wed    Thu    Fri    Sat \n";
            int k;
            for (k = 0; k < current; k++)
                cout << "      ";
            for (int j = 1; j <= days; j++)
            {
                printf("%6d", j);
                if (++k > 6)
                {
                    k = 0;
                    cout << endl;
                }
            }
            if (k)
                cout << endl;
            current = k;
        }
        return;
    }

    void printMonth(int year, int month) {
        cout << "\t Calendar - Year " << year;
        int days;
        int current = dayNumber(1, month , year);
        // one month code 
        days = numberOfDays(month -1, year);
        cout << endl << "\t ----X----" << getMonthName(month-1).c_str() << "----X---- \t\t" << endl;
        cout << "   Sun  Mon  Tue   Wed    Thu    Fri    Sat \n";
        int k;
        for (k = 0; k < current; k++)
            cout << "      ";
        for (int j = 1; j <= days; j++)
        {
            printf("%6d", j);
            if (++k > 6)
            {
                k = 0;
                cout << endl;
            }
        }
        if (k)
            cout << endl;
        current = k;
    }
};

int main()
{
    calender a;
    int year;
    int month;
    cout << "Enter the year\n" << endl;

    cin >> year; // taking year value from user as input
    cout << "Enter month : " << endl;
    cin >> month;

    //a.printCalendar(year); // calling printCalender function 
    a.printMonth(year, month);
    return (0);
}