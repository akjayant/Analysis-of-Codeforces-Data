#include <bits/stdc++.h>
#define int long long
#define MOD (int)(1e18 + 7)

using namespace std;

const int N  = 110;
int F[N][2][2][2];
int l, r;

int getbit(int x,int i) {
    return 1 & (x >> i);
}

int cal(int bit, bool a, bool b, bool pre) {
    if(bit < 0) return 1 + pre;
    int & ans = F[bit][a][b][pre];
    if(ans != -1) return ans;
    ans = 0;
    int u = getbit(l, bit), v = getbit(r, bit);
    if(a || (u == 0)) {
        ans = (ans + cal(bit - 1, a, b || (v == 1), pre)) % MOD;
        if(b || (v == 1))
            ans = (ans + cal(bit - 1, a, b, true)) % MOD;
    }
    if(pre) {
        ans = (ans + cal(bit - 1, a || (u == 0), b || (v == 1), true)) % MOD;
    }
    //if(bit < 3) cout << (a || (u == 0)) << " " << bit << " " << a << " " << b << " " << pre << " " << ans << endl;
    return ans;
}


void solve() {
    //cout <<getbit(4, 1) << endl;
    cin >> l >> r;
    memset(F, 255, sizeof(F));
    cout << cal(40, false, false, false) << endl;
}

signed main() {
    //freopen("a.txt", "r", stdin);
    int nT;
    cin >> nT;
    while(nT--)
        solve();
}
