#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <exception>
#include <string.h>
using std::cout; using std::cin; using std::endl; using std::string; 
using std::iterator; using std::exception; using std::list; using std::advance;

void getI(int &i, const char * type, string prompt)
{
    while (true) {
        cout << prompt << endl;
        string check;
        cin >> check;

        try {
            i = stoi(check);
            break;
        } 
        catch (exception &e) {
            cout << "Exception: You didn't enter a number.\n" << endl;
        }
    }
}

void getD(double &d, const char * type, string prompt)
{
    while (true) {
        cout << prompt << endl;
        string check;
        cin >> check;
        try {
            d = stod(check);
            break;
        }
        catch (exception &e) {
            cout << "Exception: You didn't enter a number.\n" << endl;
        }
    }
}

void setStudentInfo(list<string> &namelst, double &mid, double &final)
{
    cout << "What is your name?" << endl;
    string name;
    cin >> name;
    namelst.push_back(name);

    getD(mid, "double", "Enter your midterm grade: ");
    getD(final, "double", "Enter your finals grade: ");
}

double hwmed(list<double> &hw, int &amt)
{   
    amt--;
    const int middle = amt / 2;

    auto lbegin1 = hw.begin(), lbegin2 = hw.begin(), lbegin3 = hw.begin();

    advance(lbegin1, middle);
    advance(lbegin2, middle - 1);
    advance(lbegin3, middle + 1);

    ((++amt) % 2 == 0) ? cout << (*lbegin2 + *lbegin3) / 2 << endl : cout << *lbegin1 << endl;

    return ((++amt) % 2 == 0) ? (*lbegin2 + *lbegin3) / 2 : *lbegin1;
}

double hwstorage(list<double> &hws) //issue here
{
    double throwawaydouble = 0;
    int hwamount;
    getNum(throwawaydouble, hwamount, "int", "Enter the amount of homework you were assigned: ");
   
    try {
        if (hwamount < 1) {
            throw hwamount;
        }
    } catch(int ex) {
        cout << "Exception: " << ex << " entered. Please enter at least one homework assignment";
    }

    double hwinput;
    int throwaway = 0;
    auto lbegin = hws.begin();

    cout << hwamount << endl;

    for (int i = 0; i < hwamount; i++) {
        getNum(hwinput, throwaway, "double", "Enter a homework grade");
        *lbegin = hwinput;
        lbegin++;
    }

    for (double values : hws) {
        cout << "a" << endl;
        cout << values << endl;
    }

    return hwmed(hws, hwamount);
}

double finalgrade(double &mlst, double &flst, double &hwmedian)
{
    return 0.2 * mlst + 0.4 * flst + 0.4 * hwmedian;
}

int checkifFailedandRemove(list<double> &gradeslst, list<string> &nlst, int &ind, int &amnt) //issue in function
{   
    auto lbegin1 = gradeslst.begin();
    auto lbegin2 = nlst.begin();
    advance(lbegin1, ind);
    advance(lbegin2, ind);
    if (*lbegin1 < 60) {
        nlst.erase(lbegin2);
        gradeslst.erase(lbegin1);
        ind--;
        amnt--;
    }

    return 0;
}

int main()
{
    list<string> nameslst;
    list<double> hwlst, finalgradeslst;

    int amntofstudents, actualamnt;
    double throwaway = 0;
    getNum(throwaway, amntofstudents, "int", "Enter how many students you want to enter: ");
   
    for (int i = 0; i < amntofstudents; i++) {
        double midtermgrade, finalsgrade;
        setStudentInfo(nameslst, midtermgrade, finalsgrade);

        double hwmedian = hwstorage(hwlst);
        hwlst.clear();

        double finalresult = finalgrade(midtermgrade, finalsgrade, hwmedian);
        finalgradeslst.push_back(finalresult);
    }
    
    actualamnt = amntofstudents;
    for (int i = 0; i < actualamnt; i++) {
        checkifFailedandRemove (finalgradeslst, nameslst, i, actualamnt);
    }
    cout << "actual amnt == " << actualamnt << endl;
    auto lbegin1 = nameslst.begin();
    auto lbegin2 = finalgradeslst.begin();
    cout << *lbegin1 << endl;
    cout << *lbegin2 << endl;
    for (int i = 0; i < actualamnt; i++) {
        cout << *lbegin1 << ": " << *lbegin2 << endl;
        lbegin1++;
        lbegin2++;
    }

    return 0;
}