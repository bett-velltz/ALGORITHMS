//
// Created by 1 on 18.05.2026.
//
#include <iostream>
#include <vector>

using namespace std;

string it = "it";
string function (int count) {
    string hate = "I hate ";
    string love = "I love ";
    if (count == 0) {
        return "";
    }
    if (count == 1) {
        string res = "I hate ";
        return res;
    }
    else if (count % 2 == 1) {
        string res = function(count - 1) + "that " + hate;
        return res;
    }
    else {
        string res = function(count - 1) + "that " + love;
        return res;
    }
}

int main() {
    int n;
    cin >> n;

    cout << function(n) << it << '\n';
    return 0;
}
