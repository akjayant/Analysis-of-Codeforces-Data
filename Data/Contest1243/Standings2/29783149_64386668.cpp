#include <bits/stdc++.h>

using namespace std;

#define mx 400005
#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define si(x) scanf("%lld", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



int32_t main(){
    //read();
    fst;
    int n;
    while(cin >> n){
        int ans = n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) {
                ans = __gcd(n/i, ans);
                ans = __gcd(i, ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}