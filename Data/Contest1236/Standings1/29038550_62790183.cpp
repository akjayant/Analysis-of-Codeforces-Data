#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int inf = 1e9;

int add(int x, int y) {
    return (1ll * x + 1ll * y) % mod;
}

int del(int x, int y) {
    return ((1ll * x - 1ll * y) % mod + mod) % mod;
}

int mul(int x, int y) {
    return (1ll * x * 1ll * y) % mod;
}

const int N = 305;

int n, a[N][N], cnt;

signed main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n;
    for(int j = 1; j <= n; j++) {
        if(j % 2) {
        for(int i = 1; i <= n; i++)
            a[i][j] = ++cnt;
            }
        else {
            for(int i = n; i >= 1; i--)
            a[i][j] = ++cnt;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}
