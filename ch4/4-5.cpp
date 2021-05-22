#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::cin; using std::vector; using std::endl; using std::string;

void printvector(vector<int> amountvec, vector<string> list, vector<int> index)
{
    for (int i = 0; i < amountvec.size(); ++i) {
        cout << list[index[i]] << ": " << amountvec[i] << endl;
    }
}

int stringstuff(int& tot, vector<int>& amt)
{
    vector<string> list;
    string inputstring;

    bool breaker = true;
    while (breaker) {
        cout << "enter a word (e to stop): ";
        while (cin >> inputstring) {
            if (inputstring == "e") {
                breaker = false;
                break;
            }
            list.push_back(inputstring);
            break;
        }
    }

    tot = list.size();

    vector<int> indexes;
    bool unique = true;
    int totalwords = 0;
    for (int i = 0; i < tot; ++i) {
        for (int t = i + 1; t < tot; ++t) {
            if (list.at(i) == "e") {
                break;
            }
            if (list[i] == list[t]) {
                unique = false;
                if (totalwords == 0) {
                    totalwords += 2;
                }
                else {
                    ++totalwords;
                }
                list.at(t) = "e";
            }
        }
        if (unique && list.at(i) != "e") {
            amt.push_back(1);
            indexes.push_back(i);
        }
        if (totalwords != 0) {
            amt.push_back(totalwords);
            indexes.push_back(i);
        }
        totalwords = 0;
        unique = true;
    }

    printvector(amt, list, indexes);

    return 0;
}

int main()
{
    int total = 0;
    vector<int> amountoftimes;
    stringstuff(total, amountoftimes);
    cout << "Your total is " << total << endl;
    return 0;
}