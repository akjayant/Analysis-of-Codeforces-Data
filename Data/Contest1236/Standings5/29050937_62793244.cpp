// Thu Oct 17 19:10:16 IST 2019
#include<bits/stdc++.h>
using namespace std;
#define int long long

#if DEBUG && !ONLINE_JUDGE
    #include "/home/raghukul/Competitive/templates/debug.h"
#else
    #define debug(args...)
    #define DBG(x...)
#endif

const int M = 1e9 + 7;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%M;
        a = (a * a)%M;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false),cin.tie(0),cout.precision(17);
 	int n, m; 
 	cin >> n >> m;  
 	int ans = (binpow(2, m) - 1 + M)%M;
 	cout << binpow(ans, n) << endl;
    return 0;
}
