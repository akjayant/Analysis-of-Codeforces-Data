#include<iostream>
#include<algorithm>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(all(A));
    ll x = 0, y = 0;
    rep(i, 0, N / 2) x += A[i];
    rep(i, N / 2, N) y += A[i];
    cout << x * x + y * y << endl;
    return 0;
}