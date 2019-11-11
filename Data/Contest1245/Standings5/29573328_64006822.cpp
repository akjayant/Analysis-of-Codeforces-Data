#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int t, a, b, c, n;
string s;
vector<char> ans;
int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        ans.clear();
        ans.shrink_to_fit();
        ans.resize(n);
        fill(ans.begin(), ans.end(), 'D');
        cin >> a >> b >> c;
        cin >> s;
        int wins = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'R') {
                if (b > 0) {
                    --b;
                    ++wins;
                    ans[j] = 'P';
                }
            }
            if (s[j] == 'P') {
                if (c > 0) {
                    --c;
                    ++wins;
                    ans[j] = 'S';
                }
            }
            if (s[j] == 'S') {
                if (a > 0) {
                    --a;
                    ++wins;
                    ans[j] = 'R';
                }
            }
        }
        if (wins >= ((n + 1) / 2)) {
            cout << "YES" << endl;
            for (auto an : ans) {
                if (an == 'D') {
                    if (a > 0) {
                        an = 'R';
                        --a;
                    } else if (b > 0) {
                        an = 'P';
                        --b;
                    } else if (c > 0) {
                        an = 'S';
                        --c;
                    }
                }
                cout << an;
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}