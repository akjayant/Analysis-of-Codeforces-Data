#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int sz = 2e5 + 100;
const ll mod = 1e9 + 7;

int t, n;
string a, b;

int main() {

   cin >> t;

    while (t--) {

        cin >> n >> a >> b;

        vector <int> dif;

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                dif.push_back(i);
            }
        }

        if (dif.size() == 0) {
            cout << "YES\n";
        } else if (dif.size() > 2) {
            cout << "NO\n";
        } else {
            int fl = 0;
            for (int x: dif) {
                for (int y: dif) {
                    swap(a[x], b[y]);
                    if (a == b) {
                        fl = 1;
                    }
                    swap(a[x], b[y]);
                }
            }
            if (fl) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }


    return 0;
}