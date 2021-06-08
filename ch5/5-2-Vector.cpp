#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <string.h>
using std::cout; using std::cin; using std::vector; 
using std::endl; using std::string; using std::exception;

int getNum(double &d, int &i, const char * type, string prompt)
{
    while (true) {

        cout << prompt << endl;
        string check;
        cin >> check;

        try {
            if (strcmp(type, "double") == 0) {
                d = stod(check);
                break;
            }
            else {
                i = stoi(check);
                break;
            }
        }
        catch (exception &e) {
            cout << "Exception: You didn't enter a number.\n" << endl;
        }
    }

    return 0;
}

int setStudentInfo(vector<string> &namev, double &mid, double &final)
{
    cout << "What is your name?" << endl;
    string name;
    cin >> name;
    namev.push_back(name);

    int throwaway = 0;
    getNum(mid, throwaway, "double", "Enter your midterm grade: ");
    getNum(final, throwaway, "double", "Enter your finals grade: ");

    return 0;
}

double hwmed(vector<double> &hw, int &amt)
{   
    amt--;
    const int middle = amt / 2;

    return ((++amt) % 2 == 0) ? (hw[middle - 1] + hw[middle + 1]) / 2 : hw[middle];
}

double hwstorage(vector<double> &hws)
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

    hws.reserve(hwamount);
    double hwinput;
    int throwaway = 0;

    for (int i = 0; i < hwamount; i++) {
        getNum(hwinput, throwaway, "double", "Enter a homework grade");
        hws[i] = hwinput;
    }

    return hwmed(hws, hwamount);
}

double finalgrade(double &mvec, double &fvec, double &hwmedian)
{
    return 0.2 * mvec + 0.4 * fvec + 0.4 * hwmedian;
}

int checkifFailedandRemove(vector<double> &gradesvec, vector<string> &nvec, int &ind, int &amnt)
{   
    if (gradesvec[ind] < 60) {
        nvec.erase(nvec.begin() + ind);
        gradesvec.erase(gradesvec.begin() + ind);
        ind--;
        amnt--;
    }

    return 0;
}

int main()
{
    vector<string> namesvec;
    vector<double> hwvec, finalgradesvec;

    int amntofstudents, actualamnt;
    double throwaway = 0;
    getNum(throwaway, amntofstudents, "int", "Enter how many students you want to enter: ");
   
    for (int i = 0; i < amntofstudents; i++) {
        double midtermgrade, finalsgrade;
        setStudentInfo(namesvec, midtermgrade, finalsgrade);

        double hwmedian = hwstorage(hwvec);
        hwvec.clear();

        double finalresult = finalgrade(midtermgrade, finalsgrade, hwmedian);
        finalgradesvec.push_back(finalresult);
    }

    actualamnt = amntofstudents;
    for (int i = 0; i < actualamnt; i++) {
        checkifFailedandRemove(finalgradesvec, namesvec, i, actualamnt);
    }

    for (int i = 0; i < actualamnt; i++) {
        cout << namesvec[i] << ": " << finalgradesvec[i] << endl; 
    }

    return 0;
}