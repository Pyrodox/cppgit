#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <exception>
#include <string.h>
using std::cout; using std::cin; using std::vector; using std::endl; using std::string; using std::iterator; using std::exception;

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

int setStudentInfo(vector<string> &namev, vector<double> &midv, vector<double> &finalv)
{
    cout << "What is your name?" << endl;
    string name;
    cin >> name;
    namev.push_back(name);

    double midterm, final;
    int throwaway = 0;

    getNum(midterm, throwaway, "double", "Enter your midterm grade: ");
    midv.push_back(midterm);

    getNum(final, throwaway, "double", "Enter your finals grade: ");
    finalv.push_back(final);

    return 0;
}

double hwmed(vector<double> &hw, int &amt)
{   
    const int middle = amt / 2;

    return (amt % 2 == 0) ? (hw[middle - 1] + hw[middle + 1]) / 2 : hw[middle];
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

int checkifFailedandRemove(vector<double> &gradesvec, vector<string> &nvec, int iter, int amnt)
{   
    if (gradesvec[iter] < 60) {
        nvec.erase(nvec.begin() + iter);
        gradesvec.erase(gradesvec.begin() + iter);
        amnt--;
    }

    return amnt;
}

int main()
{
    vector<string> namesvec;
    vector<double> midtermsvec, finalsvec, hwvec, finalgradesvec;

    int amntofstudents, actualamnt;
    double throwaway = 0;
    getNum(throwaway, amntofstudents, "int", "Enter how many students you want to enter: ");
   
    for (int i = 0; i < amntofstudents; i++) {
        setStudentInfo(namesvec, midtermsvec, finalsvec);
        double hwmedian = hwstorage(hwvec);
        double finalresult = finalgrade(midtermsvec[i], finalsvec[i], hwmedian);
        finalgradesvec.push_back(finalresult);
        actualamnt = checkifFailedandRemove(finalgradesvec, namesvec, i, amntofstudents);
        hwvec.clear();
    }

    for (int i = 0; i < actualamnt; i++) {
        cout << namesvec[i] << ": " << finalgradesvec[i] << endl; 
    }

    return 0;
}