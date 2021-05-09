#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using std::cin; using std::setprecision; using std::cout; 
using std::string; using std::endl; using std::streamsize;

/* 3-1 Proof in Writing:
    The definition of a median is the value in the middle of a set of numbers. 
    Since we do not know how many numbers are left in the set of numbers, then that means
    we don't know how many values we've read and/or don't know the amount of numbers in the entire set.
    To be cautious, we must not get rid of any value that we've already read since that number could actually
    be the median (remember, we don't know how many values we've read and/or the amount of numbers in the set)
     or it could be used to average the median. Therefore, in a universal case in which this written proof
      should be applied to a median set of all real numbers, we must not get rid of any values that we've already read.*/
      
int main() {
    double midterm, final;  
    string name;
    int count = 0;    
    double sum = 0;  
    double x;
    streamsize prec = cout.precision();

    cout << "Please enter your first name: ";        
    cin >> name;    
    cout << "Hello, " << name << "!" << endl;
    
    cout << "Please enter your midterm and final exam grades: ";      
    cin >> midterm >> final;    
    
    cout << "Enter all your homework grades, "         
    "followed by end-of-file: ";
    while (cin >> x) {        
        ++count;        
        sum += x;    
    
    }
    double average = sum / count;
    setprecision(3);

    if (count > 0) {    
        cout << "Your final grade is " << 0.2 * midterm + 0.4 * final + average << endl; 
    }
    else {    
        cout << "no homework entered " << endl;
    }

    setprecision(prec);
     
    return 0;
}