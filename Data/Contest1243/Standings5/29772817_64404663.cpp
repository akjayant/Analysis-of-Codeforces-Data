#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define int long long
#define mod 100000007

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int n; cin >> n;
        int g = 0;
        for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                        int y = n / i;
                        g = __gcd(g, i);
                        g = __gcd(g, y);
                }
        }
        cout << (g == 0? n: g);
return 0;
}
