#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}
void solve() {
    int n, r, p, s;
    cin >> n >> r >> p >> s;

    string ss;
    cin >> ss;

    auto win = 0;
    vector<char> res;
    for(auto c : ss) {
        if(c == 'R' && p) {
            res.push_back('P');
            p--;
            win++;
        }
        else if(c == 'P' && s) {
            res.push_back('S');
            s--;
            win++;
        }
        else if(c == 'S' && r) {
            res.push_back('R');
            r--;
            win++;
        }
        else
            res.push_back('X');
    }

    if(win >= (double)n / 2)
        cout << "YES" << endl;
    else{
        cout << "NO" << endl;
        return;
    }
    for(auto c : res) {
        if(c == 'X') {
            if(r) {
                cout << 'R';
                r--;
            }
            else if(p) {
                cout << 'P';
                p--;
            }
            else if(s) {
                cout << 'S';
                s--;
            }
        }
        else
            cout << c;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for(auto i = 0; i < t; ++i)
        solve();
}