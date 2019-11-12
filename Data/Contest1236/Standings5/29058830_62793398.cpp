#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second

const int mod = 1e9 + 7;

int expo(int b, int p) {
    if(p == 0) {
        return 1;
    }
    if(p & 1) {
        return ((b * expo((b * b) % mod, p / 2) % mod) % mod);
    }
    else {
        return (expo((b * b) % mod, p / 2) % mod);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int ans = expo(2, m);
    ans = (ans - 1 + mod) % mod;
    ans = expo(ans, n);
    
    cout << ans << endl;
	
	return 0;
}
