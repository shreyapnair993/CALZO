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
        int CALZO;

    

    cout << "----CALZO----" << std::endl;

    do {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1). Chinese Zodiac" << endl;
        cout << "2). Western Zodiac" << endl;
        cout << "3). Calender" << endl;
        cout << "4). Quit Program" << endl;
        cin >> CALZO;

        if (!cin || CALZO <= 0 || CALZO > 5) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nI'm sorry but that is not an option. Please answer 1, 2, 3 or 4." << endl;
        }


//Start Chinese Zodiac Option
        if (CALZO == 1) {

            int iCbirth;
            int iCzodiac;

            while ((cout << "\nEnter year born." << endl) && !(cin >> iCbirth)) {
                cout << "\nI'm sorry but that is an invalid answer. Please answer using numbers." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }

            iCzodiac = iCbirth-((iCbirth/12)*12);

            if (iCzodiac == 0){
                cout << "\nYour Chinese Zodiac is the Monkey." << endl;
            }
            else if (iCzodiac == 1){
                cout << "\nYour Chinese Zodiac is the Rooster." << endl;
            }
            else if (iCzodiac == 2){
                cout << "\nYour Chinese Zodiac is the Dog." << endl;
            }
            else if (iCzodiac == 3){
                cout << "\nYour Chinese Zodiac is the Pig." << endl;
            }
            else if (iCzodiac == 4){
                cout << "\nYour Chinese Zodiac is the Rat." << endl;
            }
            else if (iCzodiac == 5){
                cout << "\nYour Chinese Zodiac is the Ox." << endl;
            }
            else if (iCzodiac == 6){
                cout << "\nYour Chinese Zodiac is the Tiger." << endl;
            }
            else if (iCzodiac == 7){
                cout << "\nYour Chinese Zodiac is the Rabbit." << endl;
            }
            else if (iCzodiac == 8){
                cout << "\nYour Chinese Zodiac is the Dragon." << endl;
            }
            else if (iCzodiac == 9){
                cout << "\nYour Chinese Zodiac is the Snake." << endl;
            }
            else if (iCzodiac == 10){
                cout << "\nYour Chinese Zodiac is the Horse." << endl;
            }
            else if (iCzodiac == 11){
                cout << "\nYour Chinese Zodiac is the Goat." << endl;
            }
        }
//End Chinese Zodiac Option


//Start Western Zodiac Option
        if (CALZO == 2) {

            int iMonth;
            int iDay;

            while ((cout << "\nEnter month born." << endl) && !(cin >> iMonth)) {
                cout << "\nI'm sorry but that is an invalid answer. Please answer using numbers." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            while ((cout << "\nEnter day born." << endl) && !(cin >> iDay)) {
                cout << "\nI'm sorry but that is an invalid answer. Please answer using numbers." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }

            if (iMonth == 12) {
                if (iDay >= 22) {
                    cout << "\nYour Western Zodiac sign is Capricorn." << endl;
                }
                else if (iDay <= 21) {
                    cout << "\nYour Western Zodiac sign is Sagittarius." << endl;
                }
            }
            else if (iMonth == 11) {
                if (iDay >= 23) {
                    cout << "\nYour Western Zodiac sign is Sagittarius." << endl;
                }
                else if (iDay <= 22) {
                    cout << "\nYour Western Zodiac sign is Scorpio." <<endl;
                }
            }
            else if (iMonth == 10) {
                if (iDay >= 23) {
                    cout << "\nYour Western Zodiac sign is Scorpio." << endl;
                }
                else if (iDay <= 22) {
                    cout << "\nYour Western Zodiac sign is Libra." <<endl;
                }
            }
            else if (iMonth == 9) {
                if (iDay >= 23) {
                    cout << "\nYour Western Zodiac sign is Libra." << endl;
                }
                else if (iDay <= 22) {
                    cout << "\nYour Western Zodiac sign is Virgo." <<endl;
                }
            }
            else if (iMonth == 8) {
                if (iDay >= 23) {
                    cout << "\nYour Western Zodiac sign is Virgo." << endl;
                }
                else if (iDay <= 22) {
                    cout << "\nYour Western Zodiac sign is Leo." <<endl;
                }
            }
            else if (iMonth == 7) {
                if (iDay >= 23) {
                    cout << "\nYour Western Zodiac sign is Leo." << endl;
                }
                else if (iDay <= 22) {
                    cout << "\nYour Western Zodiac sign is Cancer." <<endl;
                }
            }
            else if (iMonth == 6) {
                if (iDay >= 22) {
                    cout << "\nYour Western Zodiac sign is Cancer." << endl;
                }
                else if (iDay <= 21) {
                    cout << "\nYour Western Zodiac sign is Gemini." <<endl;
                }
            }
            else if (iMonth == 5) {
                if (iDay >= 22) {
                    cout << "\nYour Western Zodiac sign is Gemini." << endl;
                }
                else if (iDay <= 21) {
                    cout << "\nYour Western Zodiac sign is Taurus." <<endl;
                }
            }
            else if (iMonth == 4) {
                if (iDay >= 21) {
                    cout << "\nYour Western Zodiac sign is Taurus." << endl;
                }
                else if (iDay <= 20) {
                    cout << "\nYour Western Zodiac sign is Aries." <<endl;
                }
            }
            else if (iMonth == 3) {
                if (iDay >= 21) {
                    cout << "\nYour Western Zodiac sign is Aries." << endl;
                }
                else if (iDay <= 20) {
                    cout << "\nYour Western Zodiac sign is Pisces." <<endl;
                }
            }
            else if (iMonth == 2) {
                if (iDay >= 20) {
                    cout << "\nYour Western Zodiac sign is Pisces." << endl;
                }
                else if (iDay <= 19) {
                    cout << "\nYour Western Zodiac sign is Aquarius." <<endl;
                }
            }
            else if (iMonth == 1) {
                if (iDay >= 21) {
                    cout << "\nYour Western Zodiac sign is Aquarius." << endl;
                }
                else if (iDay <= 20) {
                    cout << "\nYour Western Zodiac sign is Capricorn." <<endl;
                }
            }
        }
//End Western Zodiac Option



    if( CALZO == 3){
         calender a;
    int year;
    int month;
    cout << "Enter the year\n" << endl;

    cin >> year; // taking year value from user as input
    cout << "Enter month : " << endl;
    cin >> month;

    //a.printCalendar(year); // calling printCalender function 
    a.printMonth(year, month);
    }
    } while (CALZO != 4);

    cout << "\nThank you for playing, Good bye." << endl;

    return (0);
}