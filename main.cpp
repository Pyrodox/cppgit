#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
using std::cout; using std::string; using std::endl; using std::cin; 
using std::setprecision; using std::streamsize; using std::vector; using std::sort;

int main() {
    vector<string> listofnames;
    vector<double> gradeslist;

    int studentgrades;
    cout << "How many students' grades do you want to enter?" << endl;
    cin >> studentgrades;
    if (studentgrades < 1) {
        return 1;
    }

    for (int t = 0; t < studentgrades; ++t ) {
        cout << "Please enter your first name: ";
        string name;
        cin >> name;
        listofnames.push_back(name);

        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;
    

        cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
        double x;
        vector<double> homework;
        for (int i = 0; i < 6; ++i) {
            cout << "Enter a homework grade: " << endl;
            cin >> x;
            homework.push_back(x);
        }

        typedef vector<double>::size_type vec_sz;
        vec_sz size = homework.size();

        sort(homework.begin(), homework.end());

        double median = (homework[3] + homework[2]) / 2;

        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
        << 0.2 * midterm + 0.4 * final + 0.4 * median << endl;
        gradeslist.push_back(0.2 * midterm + 0.4 * final + 0.4 * median);
        setprecision(prec);

    }
    return 0;
}