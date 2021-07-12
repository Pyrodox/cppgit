#include <iostream>
#include <list>
#include <string>
using std::cout; using std::list; using std::string;
using std::istream; using std::cin; using std::getline;

class String_list {
    public:
        String_list();
        list<string> getholder() const { return holder; };
        istream& read(istream& in) {
            string temp;
            in >> temp;
            holder.push_back(temp);

            return in;
        };
        list<string>::iterator hb;
        list<string> split(const string&);
    private:
        list<string> holder;
};

list<string> String_list::split(const string& s)
{
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()) {
        while (i != s.size() && isspace(s[i]))
            ++i;
        string_size j = i;
        while (j != s.size() && !isspace(s[j]))
            j++;

        if (i != j) {
            holder.push_back(s.substr(i, j - i));
            i = j;
        }    
    }

    return holder;
}

String_list::String_list() { }

int main()
{
    String_list lstclass;
    string temp;
    while(getline(cin, temp)) {
        lstclass.split(temp);
    }
    list<string> listt = lstclass.getholder();

    for (list<string>::iterator it = listt.begin(); it != listt.end(); ++it) {
        cout << *it << "\n";
    }

    cout << "\n";

    for (lstclass.hb = listt.begin(); lstclass.hb != listt.end(); ++lstclass.hb) {
        cout << *(lstclass.hb) << "\n";
    }

    cout << "\n";

    for (lstclass.hb = --listt.end(); lstclass.hb != --listt.begin(); --lstclass.hb) {
        cout << *(lstclass.hb) << "\n";
    }

    return 0;
}