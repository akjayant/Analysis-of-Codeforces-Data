#include <iostream>
#include <algorithm>
#include <set>
#include "vector"
#include "queue"
#include <math.h>

using namespace std;

int main() {
    int k, n;
    string s, t;
    cin >> k;
    for (int q = 0; q < k; q++) {
        cin >> n;
        cin >> s;
        cin >> t;
        vector<int> count(26);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']++;
        }
        bool mark = true;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                mark = false;
                break;
            }
        }
        if (!mark) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == s[i]) {
                        char ch = s[j];
                        s[j] = t[i];
                        t[i] = ch;
                        ans.emplace_back(j+1, i+1);
                        break;
                    }
                }
            }
            if (s[i] != t[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (t[j] == s[i]) {
                        char ch = s[n-1];
                        s[n-1] = t[j];
                        t[j] = ch;
                        ans.emplace_back(n, j+1);
                        ch = s[n-1];
                        s[n-1] = t[i];
                        t[i] = ch;
                        ans.emplace_back(n, i+1);
                        break;
                    }
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto p : ans) {
            cout << p.first << " " << p.second << "\n";
        }
    }

}
