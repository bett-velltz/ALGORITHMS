#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n;
   ll d;
   cin >> n >> d;
   vector<ll> x(n);
   for (int i = 0; i < n; ++i) {
       cin >> x[i];
   }

   int ans = 0;
   int i = 0;
   while (i < n) {
       ll l = x[i];
       ++ans;
       while (i < n && x[i] <= l + d) {
           ++i;
       }
   }
    cout << ans << '\n';
   return 0;
}

