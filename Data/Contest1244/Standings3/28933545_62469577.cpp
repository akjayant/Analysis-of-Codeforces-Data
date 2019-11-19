#include <bits/stdc++.h>

using namespace std;

long long n, q, f, f1, f2, f3, f4, cnt, cnt1;
string s;

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> n;
        cin >> s;
        long long last = -1, fir = -1;
        for (int i1 = 0; i1 < s.size(); i1++) {
            if (s[i1] == '1') {
                last = i1;
                if (fir == -1) {
                    fir = i1;
                }
            }
        }
        if (last == -1) {
            cout << n << endl;
        } else {
            last++;
            fir++;
           // cout << fir << " x" << endl;
            cout << max((n - fir + 1) * 2, (last * 2)) << endl;
        }
    }
}
