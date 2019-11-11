#include<iostream>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

void solve() {
    int N, A, B, C;
    string S;
    cin >> N >> A >> B >> C >> S;
    int win = 0;
    string alice(N, '#');
    rep(i, 0, N) {
        if (S[i] == 'R') {
            if (B > 0) {
                ++win;
                --B;
                alice[i] = 'P';
            }
        }
        else if (S[i] == 'S') {
            if (A > 0) {
                ++win;
                --A;
                alice[i] = 'R';
            }
        }
        else {
            if (C > 0) {
                ++win;
                --C;
                alice[i] = 'S';
            }
        }
    }
    if (win < (N + 1) / 2) {
        cout << "NO" << endl;
        return;
    }
    rep(i, 0, N) {
        if (alice[i] == '#') {
            if (A > 0) {
                alice[i] = 'R';
                --A;
            }
            else if (B > 0) {
                alice[i] = 'P';
                --B;
            }
            else {
                alice[i] = 'S';
                --C;
            }
        }
    }
    cout << "YES" << endl;
    cout << alice << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    rep(i, 0, T) solve();
    return 0;
}