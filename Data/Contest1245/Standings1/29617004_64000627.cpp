#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int r, p, s;
        cin >> r >> p >> s;
        string seq;
        cin >> seq;
        int wins = 0;
        vector<char> t(n);
        for(int i = 0; i < n; i++) {
            if(seq[i] == 'R' and p > 0) {
                t[i] = 'P';
                p--;
                wins++;
            }
            if(seq[i] == 'P' and s > 0) {
                t[i] = 'S';
                s--;
                wins++;
            }
            if(seq[i] == 'S' and r > 0) {
                t[i] = 'R';
                r--;
                wins++;
            }
        }
        if(wins >= (n + 1) / 2) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                if(not t[i]) {
                    if(r > 0) {
                        t[i] = 'R';
                        r--;
                    } else if(p > 0) {
                        t[i] = 'P';
                        p--;
                    } else if(s > 0) {
                        t[i] = 'S';
                        s--;
                    }
                }
            }
            for(char c : t) cout << c;
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
