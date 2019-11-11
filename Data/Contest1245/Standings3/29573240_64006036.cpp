#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t t;
    cin >> t;
    for (size_t u = 0; u < t; ++u) {
        size_t n;
        cin >> n;

        int64_t a, b, c;
        cin >> a >> b >> c;

        string s;
        cin >> s;

        size_t w = 0;
        vector<char> ans(n);

        for (size_t i = 0; i < n; ++i) {
            switch (s[i]) {
                case 'R': {
                    if (b > 0) {
                        w++;
                        b--;
                        ans[i] = 'P';
                    }
                    break;
                }
                case 'P': {
                    if (c > 0) {
                        w++;
                        c--;
                        ans[i] = 'S';
                    }
                    break;
                }
                case 'S': {
                    if (a > 0) {
                        w++;
                        a--;
                        ans[i] = 'R';
                    }
                    break;
                }
            }
        }

        for (size_t i = 0; i < n; ++i) {
            if (ans[i] != 0) {
                continue;
            }
            switch (s[i]) {
                case 'R': {
                    if (a > 0) {
                        a--;
                        ans[i] = 'R';
                    }
                    break;
                }
                case 'P': {
                    if (b > 0) {
                        b--;
                        ans[i] = 'P';
                    }
                    break;
                }
                case 'S': {
                    if (c > 0) {
                        c--;
                        ans[i] = 'S';
                    }
                    break;
                }
            }
        }

        for (size_t i = 0; i < n; ++i) {
            if (ans[i] != 0) {
                continue;
            }
            switch (s[i]) {
                case 'R': {
                    if (c > 0) {
                        c--;
                        ans[i] = 'S';
                    }
                    break;
                }
                case 'P': {
                    if (a > 0) {
                        a--;
                        ans[i] = 'R';
                    }
                    break;
                }
                case 'S': {
                    if (b > 0) {
                        b--;
                        ans[i] = 'P';
                    }
                    break;
                }
            }
        }

        if ((int64_t) ((double) n / 2 + 0.5) <= w) {
            cout << "YES\n";
            for (char ch : ans) {
                cout << ch;
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}
