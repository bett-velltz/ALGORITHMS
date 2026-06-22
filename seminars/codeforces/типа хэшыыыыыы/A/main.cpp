#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<string, string> a; // начальное имя каждого пользователя с текущи м именем
    map<string, string> b; // текущее имя каждого пользователя с начальным

    for (int i = 0; i < q; ++i) {
        string old_s, new_s;
        cin >> old_s >> new_s;
        string parent;
        if (a.find(old_s) == a.end()) {
            parent = old_s;
        } else {
            parent =  a[old_s];
        }
        a[new_s] = parent;
        b[parent] = new_s;
    }
    cout << b.size() << '\n';
    for (const auto& [x,y] : b) {
        cout << x << ' ' << y << '\n';
    }
    return 0;
}