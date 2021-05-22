#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::sort; using std::cout; using std::streamsize; 
using std::endl; using std::string; using std::setprecision; using std::vector;
//did 3-0, 3-5, 3-6 (fixed number of homework grades and breaks if no final or midterm grade entered, or if negative numbers entered.)
int main()
{   
    vector<string> students;
    vector<int> final_grades;

    cout << "How many students do you want to enter?" << endl;
    int num_students;
    cin >> num_students;

    for (int t = 0; t < num_students; ++t) {
        cout << "Please enter your first name: ";
        string name;    
        cin >> name;
        students.push_back(name);    

        cout << "Please enter your midterm and final exam grades: ";
        double midterm = -1, final = -1;    
        cin >> midterm >> final;
        if (midterm < 0 || final < 0) {
            cout << "no negative grades.";
            return 1;
        }

        cout << "Enter all your 5 homework grades." << endl;  
        vector<double> homework;    
        double x; 
        for (int i = 0; i < 5; ++i) {
            cin >> x;
            homework.push_back(x);
        }
   
        int size = homework.size();
        int mid = size / 2;    
        if (size == 0) {        
            cout << endl << "You must enter your grades.  "                        
            "Please try again." << endl;         
            return 1;    
        }    
        sort(homework.begin(), homework.end());
            
        double median;    
        median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

        streamsize prec = cout.precision();    
        cout << "Your final grade is " << setprecision(3)         
            << 0.2 * midterm + 0.4 * final + 0.4 * median << endl;
        final_grades.push_back(0.2 * midterm + 0.4 * final + 0.4 * median);
        setprecision(prec);    
    }
    return 0;
}