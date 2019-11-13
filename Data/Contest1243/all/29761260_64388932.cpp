#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    for (int test = 0; test<tests; test++) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;

        int i1 = 0;
        while (i1 < n) {
            if (s1[i1] != s2[i1])
                break;
            i1++;
        }

        if (i1 == n) {
            cout << "NO" << endl;
            continue;
        }

        int i2 = i1 + 1;

        while (i2 < n) {
            if (s1[i2] != s2[i2])
                break;
            i2++;
        }

        if (i2 == n) {
            cout << "NO" << endl;
            continue;
        }

        char buf;

        buf = s1[i1];
        s1[i1] = s2[i2];
        s2[i2] = buf;

        if (s1 == s2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}