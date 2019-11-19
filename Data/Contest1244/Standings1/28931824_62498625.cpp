#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(string &s) {
    int n = s.size();
    if (n % 2)
        return false;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (check(s)) {
        if (k % 2 == 0) {
            cout << s << endl;
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'B')
                    cout << 'W';
                else
                    cout << 'B';
            }
        }
        return 0;
    }
    s = s + s + s;
    vector<int> ch(n * 3);
    vector<pair<int, int>> a;
    for (int i = 0; i < n * 3 - 1; ++i) {
        if (s[i] == s[i + 1]) {
            a.push_back(make_pair(i, i));
            ch[i] = 1;
            while (i + 1 < n * 3 && s[i + 1] == s[i]) {
                ++i;
                ch[i] = 1;
            }
            a.back().second = i;
        }
    }
    for (int i = 0; i < (int)a.size() - 1; ++i) {
        int d = a[i + 1].first - a[i].second;
        for (int j = 0; j < min(d / 2, k); ++j) {
            s[a[i].second + 1 + j] = s[a[i].second];
            ch[a[i].second + 1 + j] = 1;
            s[a[i + 1].first - 1 - j] = s[a[i + 1].first];
            ch[a[i + 1].first - 1 - j] = 1;
            assert(a[i].second + 1 + j <= a[i + 1].first - 1 - j);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ch[i + n])
            cout << s[i + n];
        else if (ch[i + 2 * n])
            cout << s[i + 2 * n];
        else if (ch[i])
            cout << s[i];
        else {
            if (k % 2 == 0)
                cout << s[i];
            else {
                if (s[i] == 'B')
                    cout << 'W';
                else
                    cout << 'B';
            }
        }
    }
    cout << endl;
    return 0;
}
