#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using std::cout; using std::cin; using std::vector; using std::endl; using std::string; using std::iterator;

void studentinfo(vector<string> &namev, vector<double> &midv, vector<double> &finalv)
{
    cout << "What is your name?" << endl;
    string name;
    cin >> name;
    namev.push_back(name);

    cout << "Enter your midterm grade and your final grade using a space to separate them." << endl;
    double midterm, final;
    cin >> midterm >> final;
    midv.push_back(midterm);
    finalv.push_back(final);
}

double hwstorage(vector<double> &hws)
{
    int hwamount;
    cout << "Enter the amount of homework you had: " << endl;
    cin >> hwamount;

    double hwinput;
    for (int value : hws) {
        cout << "Enter a homework grade" << endl;
        cin >> hwinput;
        hws.push_back(hwinput);
    }

    return hwmed(hws, hwamount);    
}

double hwmed(vector<double> &hw, int &amt)
{   
    return (amt % 2 == 0) ? (hw[(amt / 2) - 1] + hw[(amt / 2) + 1]) / 2 : hw[amt / 2];
}

double finalgrade(double &mvec, double &fvec, double &median)
{
    return 0.2 * mvec + 0.4 * fvec + 0.4 * median;
}

bool failandremove(double &grade, vector<string> &nvec, vector<double> &mvec, vector<double> &fvec, int iter)
{
    bool confirm;
    (grade < 60) ? confirm = true : confirm = false;

    vector<string>::iterator n = nvec.begin();
    vector<double>:: iterator m = mvec.begin();
    vector<double>::iterator f = fvec.begin();

    if (confirm) {
        nvec.erase(n + iter, n + iter + 1);
        mvec.erase(m + iter, m + iter + 1);
        fvec.erase(f + iter, f + iter + 1);
    }

    return true;
}

int main()
{
    vector<string> namesvec;
    vector<double> midtermsvec, finalsvec, hwfinal;
    int amntofstudents;

    
    
        studentinfo(namesvec, midtermsvec, finalsvec);
        double median = hwstorage(hwfinal);
        double finalresult = finalgrade(midtermsvec[0], finalsvec[0], median);
        failandremove(finalresult, namesvec, midtermsvec, finalsvec, 0);
        hwfinal.clear();
    
    return 0;
}