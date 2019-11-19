#include<iostream>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

void solve() {
    int N, M;
    cin >> N;
    vector<ll> P(N);
    ll odd_cnt1 = 0, even_cnt1 = 0;
    rep(i, 0, N) {
        cin >> P[i];
        if (P[i] % 2) odd_cnt1++;
        else even_cnt1++;
    }
    cin >> M;
    vector<ll> Q(M);
    ll odd_cnt2 = 0, even_cnt2 = 0;
    rep(i, 0, M) {
        cin >> Q[i];
        if (Q[i] % 2) odd_cnt2++;
        else even_cnt2++;
    }
    cout << odd_cnt1 * odd_cnt2 + even_cnt1 * even_cnt2 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    rep(i, 0, T) solve();
    return 0;
}