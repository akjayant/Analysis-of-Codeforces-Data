// qdd on Oct 20, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

template<class T> inline bool updmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template<class T> inline bool updmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

int getAns(const string& s) {
    vector<int> a(n);
    int minp = 0;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] == '(' ? 1 : -1;
        if (i > 0) a[i] += a[i - 1];
        minp = min(a[i], minp);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == minp) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), '(') * 2 != n) {
        cout << "0\n1 1\n";
        return 0;
    }
    int ans = getAns(s), x = 1, y = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(s[i], s[j]);
            if (updmax(ans, getAns(s))) {
                x = i + 1;
                y = j + 1;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << '\n';
    cout << x << ' ' << y << '\n';
    return 0;
}