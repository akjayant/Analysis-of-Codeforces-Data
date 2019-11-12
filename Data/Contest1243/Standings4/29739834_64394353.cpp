#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <stack>
#include <cmath>
#include <deque>
#include <queue>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void io_optimize() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    io_optimize();
    int k;
    cin >> k;
    while (k--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        set<int> spos[26], tpos[26];
        for (int i = 0; i < n; i++) {
            spos[s[i] - 'a'].insert(i);
            tpos[t[i] - 'a'].insert(i);
        }
        vector<pii> ans;

        for (int i = 0; i < 26; i++) {
            if ((tpos[i].size() + spos[i].size()) % 2 != 0) {
                cout << "No\n";
                goto cont;
            }
        }

        for (int i = 0; i < n; i++) {

            if (s[i] == t[i]) continue;

            for (int j = i + 1; j < n; j++) {
                if (t[j] == t[i]) {
                    ans.push_back({i, j});
                    swap(s[i], t[j]);
                    goto cont2;
                }
            }

            for (int j = i + 1; j < n; j++) {
                if (s[j] == t[i]) {
                    ans.push_back({j, j});
                    ans.push_back({i, j});
                    swap(s[j], t[j]);
                    swap(s[i], t[j]);
                    goto cont2;
                }
            }

            cont2:;
        }

        cout << "Yes\n" << ans.size() << "\n";
        for (auto p: ans) {
            cout << p.first + 1 << ' ' << p.second + 1 << '\n';
        }

        cont:;
    }
    return 0;
}