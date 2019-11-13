#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;

void solve() {
    int N;
    string S, T;
    cin >> N >> S >> T;
    int cnt = 0;
    rep(i, 0, N) {
        if (S[i] != T[i]) {
            ++cnt;
        }
    }
    if (cnt == 0) {
        cout << "Yes" << endl;
        return;
    }
    if (cnt != 2) {
        cout << "No" << endl;
        return;
    }
    vector<int> cnt1(26, 0), cnt2(26, 0);
    rep(i, 0, N) {
        if (S[i] != T[i]) {
            ++cnt1[S[i] - 'a'];
            ++cnt2[T[i] - 'a'];
        }
    }
    int two1 = 0, two2 = 0;
    rep(i, 0, 26) {
        if (cnt1[i] == 2) ++two1;
        if (cnt2[i] == 2) ++two2;
    }
    if (two1 == 1 && two2 == 1) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int K;
    cin >> K;
    rep(i, 0, K) solve();
    return 0;
}