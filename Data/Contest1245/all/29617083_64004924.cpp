#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string Bob;
        cin >> Bob;
        int r = 0, p = 0, s = 0;
        for (int i = 0; i < (int)Bob.length(); ++i) {
            if (Bob[i] == 'R') ++r;
            if (Bob[i] == 'P') ++p;
            if (Bob[i] == 'S') ++s;
        }
        int R = min(r, b);
        vector<char> left;
        for (int i = 0; i < b - R; ++i) left.push_back('P');
        int P = min(p, c);
        for (int i = 0; i < c - P; ++i) left.push_back('S');
        int S = min(s, a);
        for (int i = 0; i < a - S; ++i) left.push_back('R');
        int res = R + P + S;
        if (res * 2 >= n) {
            cout << "YES" << endl;
            string ans = "";
            int iter = 0;
            for (int i = 0; i < (int)Bob.length(); ++i) {
                if (Bob[i] == 'R') {
                    if (R > 0) {
                        ans += 'P';
                        --R;
                    } else {
                        ans += left[iter++];
                    }
                }
                if (Bob[i] == 'P') {
                    if (P > 0) {
                        ans += 'S';
                        --P;
                    } else {
                        ans += left[iter++];
                    }
                }
                if (Bob[i] == 'S') {
                    if (S > 0) {
                        ans += 'R';
                        --S;
                    } else {
                        ans += left[iter++];
                    }
                }
            }
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

