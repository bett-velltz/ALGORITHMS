#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    string name1, name2, letters;
    cin >> name1 >> name2 >> letters;
    multiset<char> name;
    multiset<char> l;
    for (char c : name1) {
        name.insert(c);
    }
    for (char c : name2) {
        name.insert(c);
    }
    for (char c : letters) {
        l.insert(c);
    }

    if (name == l) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}