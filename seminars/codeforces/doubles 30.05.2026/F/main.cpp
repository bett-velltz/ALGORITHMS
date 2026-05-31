#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    vector<int> x(4, 0);
    vector<int> y(4, 0);
    for (int i = 0; i < 4; ++i) {
        cin >> x[i] >> y[i];
    }
    //0, 1, 2
    double s1 = 0.5 * abs((x[0] - x[2])*(y[1] - y[2]) - (x[1] - x[2])*(y[0] - y[2]));
    //0, 1, 3
    double s2 = 0.5 * abs((x[0] - x[3])*(y[1] - y[3]) - (x[1] - x[3])*(y[0] - y[3]));
    //0, 2, 3
    double s3 = 0.5 * abs((x[0] - x[3])*(y[2] - y[3]) - (x[2] - x[3])*(y[0] - y[3]));
    //1, 2, 3
    double s4 = 0.5 * abs((x[1] - x[3])*(y[2] - y[3]) - (x[2] - x[3])*(y[1] - y[3]));

    if ((s1 == s2+s3+s4) || (s2 == s1+s3+s4) || (s3 == s2+s1+s4) || (s4 == s2+s3+s1)) {
        cout << 3 << '\n';
    } else {
        cout << 4 << '\n';
    }
    return 0;
}