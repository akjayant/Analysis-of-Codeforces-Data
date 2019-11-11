#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int MAXN = 2e5;
int d[MAXN];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string t;
        int r1, p1, s1;
        cin >> r1 >> p1 >> s1;
        cin >> t;
        int r = 0, p = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] == 'R') {
                r++;
            } else if (t[i] == 'P') {
                p++;
            } else {
                s++;
            }
        }
        int win = 0;
        char res[n];
        for (int i = 0; i < n; ++i) {
            res[i] = '.';
        }
        for (int i = 0; i < n; ++i) {
            if (t[i] == 'R') {
                if (p1 > 0) {
                    res[i] = 'P';
                    win++;
                    p1--;
                }
            } else if (t[i] == 'P') {
                if (s1 > 0) {
                    res[i] = 'S';
                    win++;
                    s1--;
                }
            } else {
                if (r1 > 0) {
                    res[i] = 'R';
                    r1--;
                    win++;
                }
            }
        }

        if (win >= (n + 1) / 2) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                if (res[i] == '.') {
                    if (p1 > 0) {
                        cout << "P";
                        p1--;
                    } else if (s1 > 0) {
                        cout << "S";
                        s1--;
                    } else if (r1 > 0) {
                        cout << "R";
                        r1--;
                    }
                } else {
                    cout << res[i];
                }
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}