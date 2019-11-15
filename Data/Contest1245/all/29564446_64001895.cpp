#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long 

using namespace std;

int t, n;
char c[1234];
char sol[1234];
int R, P, S;

int main() {
    // ifstream cin("tst.in");
    // ofstream cout("tst.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n;
        int need = n / 2;
        for (int i = 1; i <= n; i++)
            sol[i] = '.';
        if (n % 2 == 1)
            need++;
        cin >> R >> P >> S;
        int cnt = 0;
        string aux = "";
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            if (c[i] == 'R') {
                if (P > 0) {
                    sol[i] = 'P';
                    P--;
                    cnt++;
                }
            } else if (c[i] == 'P') {
                if (S > 0) {
                    sol[i] = 'S';
                    S--;
                    cnt++;
                }
            } else if (c[i] == 'S') {
                if (R > 0) {
                    sol[i] = 'R';
                    R--;
                    cnt++;
                }
            }
        }

        if (cnt < need) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                if (sol[i] == '.') {
                    if (R > 0) {
                        sol[i] = 'R';
                        R--;
                    } else if (P > 0) {
                        sol[i] = 'P';
                        P--;
                    } else {
                        sol[i] = 'S';
                        S--;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
                cout << sol[i];
            cout << '\n';
        }
    }
    return 0;
}