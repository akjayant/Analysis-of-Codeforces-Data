#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int inf = 1e9 + 7;


int gcd(int a, int b) {
    while (b != 0) {
        int w = a % b;
        a = b;
        b = w;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c, n;
        cin >> n;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        int ans = 0;
        vector<char> answer(n);
        for (int j = 0; j < n; ++j) answer[j] = 'Z';
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'R') {
                if (b > 0) {
                    --b;
                    ++ans;
                    answer[j] = 'P';
                }
                continue;
            }
            if (s[j] == 'P') {
                if (c > 0) {
                    --c;
                    ++ans;
                    answer[j] = 'S';
                }
                continue;
            }
            if (s[j] == 'S') {
                if (a > 0) {
                    --a;
                    ++ans;
                    answer[j] = 'R';
                }
                continue;
            }
        }
        if (ans * 2 >= n) {
            cout << "YES" << endl;
            for (int j = 0; j < n; ++j) {
                if (answer[j] == 'Z') {
                    if (a > 0) {
                        --a;
                        cout << "R";
                    } else if (b > 0) {
                        --b;
                        cout << "P";
                    } else if (c > 0) {
                        --c;
                        cout << "S";
                    }
                } else {
                    cout << answer[j];
                }
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}