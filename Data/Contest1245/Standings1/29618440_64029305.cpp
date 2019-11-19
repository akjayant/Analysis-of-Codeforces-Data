#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int l, r;
ll dp[31][2][2][2];

int b(int x, int bit){
    return (x >> bit) & 1;
}
ll solve(int bit, int g, int h, int m){
    if(bit == -1) return m == 1;
    ll &ret = dp[bit][g][h][m];
    if(ret != -1) return ret;
    ret = 0;
    // 0 1
    if((g || b(l, bit) == 0) && (h || b(r, bit) == 1)) ret += solve(bit - 1, g, h, 1);
    // 1 0
    if(m) ret += solve(bit - 1, g || b(l, bit) == 0, h || b(r, bit) == 1, m);
    // 0 0
    if(g || b(l, bit) == 0) ret += solve(bit - 1, g, h || b(r, bit) == 1, m);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        memset(dp, -1, sizeof dp);
        cin >> l >> r;
        ll ans = solve(30, 0, 0, 0) * 2;
        if(l == 0) ans++;
        cout << ans << endl;
    }
}
