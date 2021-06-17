#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using std::cin; using std::setprecision; using std::cout; 
using std::string; using std::endl; using std::streamsize;
//3-6: I forgot what it did in this case, since I am answering the "what does your..." right now after editing the program.
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