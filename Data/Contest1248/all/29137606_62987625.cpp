#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int n, m;
ll a[maxn];

int main() {
    cin >> n >> m;
    a[0] = a[1] = 2;
    inc(i, 2, 100000) a[i] = (a[i - 1] + a[i - 2]) % mod;
    cout << (a[n] + a[m] - 2 + mod) % mod;
}