#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void f() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt = 0;
    char one = '-', two = '-';
    for (int i = 0; i < (int) s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (cnt == 0)
                one = s1[i], two = s2[i], cnt++;
            else if (cnt == 1) {
                if (s1[i] == one && s2[i] == two)
                    cnt++;
                else {
                    cout << "No" << endl;
                    return;
                }
            } else {
                cout << "No" << endl;
                return;
            }
        }
    }
    if (cnt != 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main() {
    int q;
    cin >> q;
    while (q--)
        f();
    return 0;
}
