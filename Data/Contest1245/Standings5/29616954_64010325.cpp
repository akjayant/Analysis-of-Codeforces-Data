#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
    int t, n, a, b, c;
    string s;
    cin >> t;
    for (int q = 0; q < t; q++) {
        cin >> n >> a >> b >> c;
        cin >> s;
        vector<char> ans(static_cast<unsigned int>(n), ' ');
        int score = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R' && b != 0) {
                ans[i] = 'P';
                score++;
                b--;
            }
            if (s[i] == 'P' && c != 0) {
                ans[i] = 'S';
                score++;
                c--;
            }
            if (s[i] == 'S' && a != 0) {
                ans[i] = 'R';
                score++;
                a--;
            }
        }
        if (score < (n + 1) / 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (char ch : ans) {
                if (ch == ' ') {
                    if (a != 0) {
                        ch = 'R';
                        a--;
                    }
                    if (b != 0 && ch == ' ') {
                        ch = 'P';
                        b--;
                    }
                    if (c != 0 && ch == ' ') {
                        ch = 'S';
                        c--;
                    }
                }
                cout << ch;
            }
            cout << "\n";
        }
    }
}