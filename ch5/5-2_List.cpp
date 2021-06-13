#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <exception>
#include <chrono>
using std::cout; using std::cin; using std::endl; using std::string; using std::milli;
using std::iterator; using std::exception; using std::list; using std::advance;
//NOTE: TIMES ALWAYS VARY 
//10 inputs: 13.807 ms, 1000 inputs: 2420.17 ms, 10000 inputs: 24157.4 ms
void getI(int &i, string prompt)
{
    while (true) {
        cout << prompt;
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

void getD(double &d, string prompt)
{
    while (true) {
        cout << prompt;
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
    cout << "What is your name? ";
    string name;
    cin >> name;
    namelst.push_back(name);
    cout << "\n";

    getD(mid, "Enter your midterm grade: ");
    getD(final, "Enter your finals grade: ");
    cout << "\n";
}

double hwmed(list<double> &hw, int &amt)
{   
    const int middle = --amt / 2;

    auto lbegin1 = hw.begin(), lbegin2 = hw.begin();

    advance(lbegin1, middle);
    advance(lbegin2, middle + 1);
    
    return ((++amt) % 2 == 0) ? (*lbegin1 + *lbegin2) / 2 : *lbegin1;
}

double hwstorage(list<double> &hws)
{
    int hwamount;
    getI(hwamount, "Enter the amount of homework you were assigned: ");
   
    try {
        if (hwamount < 1) {
            throw hwamount;
        }
    } catch(int ex) {
        cout << "Exception: " << ex << " entered. Please enter at least one homework assignment";
    }

    double hwinput;
    auto lbegin = hws.begin();

    for (int i = 0; i < hwamount; i++) {
        getD(hwinput, "Enter a homework grade: ");
        hws.push_back(hwinput);
    }
    cout << "\n";

    return hwmed(hws, hwamount);
}

double finalgrade(double &mlst, double &flst, double &hwmedian)
{
    return 0.2 * mlst + 0.4 * flst + 0.4 * hwmedian;
}

void checkifFailedandRemove(list<double> &gradeslst, list<string> &nlst, int &ind, int &amnt)
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
}

int main()
{
    list<string> nameslst;
    list<double> hwlst, finalgradeslst;

    int amntofstudents, actualamnt;
    getI(amntofstudents, "Enter how many students you want to enter: ");
    cout << "\n";

    auto start = std::chrono::steady_clock::now();

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
        checkifFailedandRemove(finalgradeslst, nameslst, i, actualamnt);
    }

    auto lbegin1 = nameslst.begin();
    auto lbegin2 = finalgradeslst.begin();
    for (int i = 0; i < actualamnt; i++) {
        cout << *lbegin1 << ": " << *lbegin2 << endl;
        lbegin1++;
        lbegin2++;
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    cout << std::chrono::duration <double, milli> (diff).count() << " ms";

    return 0;
}