#include <bits/stdc++.h>

#define maxn 200005
#define mod 1000000007
#define inf 0x3f3f3f3f
#define start ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
using namespace std;

int pq(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

signed main() {
    start;
    int n, m;
    cin >> n >> m;
    cout << (pq((pq(2, m) - 1 + mod) % mod, n) % mod);
    return 0;
}