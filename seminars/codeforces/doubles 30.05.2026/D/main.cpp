#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]-1] = i+1;
    }
    int q;
    cin >> q;
    string f = "First";
    string s = "Second";

    for (int i = 0; i < q; ++i) {
       int a, b;
       cin >> a >> b;
       --a; --b;
       if (pos[a] > pos[b]) cout << s << '\n';
       else cout << f << '\n';
    }
    return 0;
}