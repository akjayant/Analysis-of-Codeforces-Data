#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1010;
int a[MAXN];

int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<ll> q;
    for (int i = 2; i <= ll(sqrt(n)); ++i) {
        while (n != 1 && n % i == 0) {
            q.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        q.push_back(n);
    }
    int dif = 1;
    for (int i = 1; i < q.size(); ++i) {
        if (q[i] != q[i - 1]) {
            dif++;
        }
    }
    if (dif >= 2) {
        cout << 1;
        return 0;
    }
    cout << q[0];
}