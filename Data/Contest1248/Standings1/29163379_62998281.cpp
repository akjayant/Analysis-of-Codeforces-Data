#include <bits/stdc++.h>

using namespace std;

int f(string& s) {
    int bal = 0, cnt = 0, cur = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            bal++;
        }
        if (s[i] == ')') {
            bal--;
        }
        if (bal == cur) {
            cnt++;
        }
        if (bal < cur) {
            cur = bal;
            cnt = 1;
        }
    }
    if (bal != 0) {
        return 0;
    } else {
        return cnt;
    }
}

int main() {
    string s;
    int n, ans = -1, val;
    pair<int, int> p = {0, 0};
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        for (int i1 = 0; i1 < n; i1++) {
            swap(s[i], s[i1]);
            val = f(s);
            if (val > ans) {
                ans = val;
                p = {i, i1};
            }
            swap(s[i], s[i1]);
        }
    }
    cout << ans << endl << p.first + 1<< " " << p.second + 1;
}
