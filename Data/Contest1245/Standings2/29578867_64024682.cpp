#include <bits/stdc++.h>
#define int long long
using namespace std;

bitset <32> L, R;

int dp[40][2][2][2][2];

int f(int pos, int less1, int less2, int great1, int great2) {
        if(pos < 0) return 1;

        if(~dp[pos][less1][less2][great1][great2]) return dp[pos][less1][less2][great1][great2];

        int l1 = (less1) ? L[pos] : 0;
        int l2 = (less2) ? L[pos] : 0;
        int r1 = (great1) ? R[pos] : 1;
        int r2 = (great2) ? R[pos] : 1;

        if(l1 > r1 || l2 > r2) return 0;
        int res  =0;
        if(l1 == 0 && l2 == 0)
        res = f(pos - 1, less1 && l1 == 0, less2 && l2 == 0, great1 && r1 == 0, great2 && r2 == 0);

        if(l1 <= 1 && r1 >= 1 && l2 == 0) {
                res += f(pos - 1, less1 && l1 == 1, less2 && l2 == 0, great1 && r1 == 1, great2 && r2 == 0);
        }

        if(l2 <= 1 && r2 >= 1 && l1 == 0) {
                res += f(pos - 1, less1 && l1 == 0, less2 && l2 == 1, great1 && r1 == 0, great2 && r2 == 1);
        }

        return dp[pos][less1][less2][great1][great2] = res;
}


int32_t main() {
        int test; cin >> test;
        while(test--) {
                memset(dp, -1, sizeof dp);
                int a, b; cin >> a >> b;
                L = bitset <32> (a);
                R = bitset <32> (b);
                cout << f(31, 1, 1, 1, 1) << endl;
        }
}
