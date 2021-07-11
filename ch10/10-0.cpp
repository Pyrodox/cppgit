#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::endl; using std::vector; using std::string;

string letter_grade(double grade)
{    // range posts for numeric grades    
    static const double numbers[] = {        
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0    
    };    // names for the letter grades    
    
    static const char* const letters[] = {        
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };    // compute the number of grades given the size of the array    
    // and the size of a single element    
    
    static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);    
    // given a numeric grade, find and return the associated letter grade    
    
    for (size_t i = 0; i < ngrades; ++i) {        
        if (grade >= numbers[i]) {            
            return letters[i];
        }    
    }    
    
    return "?\?\?";
}

template<class In, class Pred>In find_if(In begin, In end, Pred f)
{    
    while (begin != end && !f(*begin)) {  
        ++begin;    
    }
    
    return begin;
}

bool is_negative(int n)
{   
    return n < 0;
}

struct Student_info {
    int i = 1;
};

double (*analysis)(const vector<Student_info>& a) { };

int next(int n)
{    
    return n + 1;
}

size_t strlen(const char* p)
{    
    size_t size = 0;    
    while (*p++ != '\0') {        
        ++size;
    }
    
    return size;
}

int main()
{    
    int x = 5;
    // p points to x
    int* p = &x;    
    cout << "x = " << x << endl;    
    // change the value of x through p    
    *p = 6;    
    cout << "x = " << x << endl;


    int (*fp)(int);
    fp = &next;
    fp = next;

    int i = 1;
    i = (*fp)(i);
    i = fp(i); //calling it two times; both mean the same thing
    cout << i << endl;


    double coords[3];
    const size_t NDim = 3;
    coords[NDim];
    *coords = 1.5;
    vector<double> v;copy(coords, coords + NDim, back_inserter(v));
    vector<double> v1(coords, coords + NDim);
    

    const char hello[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    strlen(hello);
    string s(hello);
    string s2(hello, hello + strlen(hello));

    return 0;
}