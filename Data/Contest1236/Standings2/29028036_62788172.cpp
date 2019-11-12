#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define sz(v) (int) v.size()
#define pr(v) For(i, 0, sz(v)) {cout<<v[i]<<" ";} cout<<endl;
#define slld(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define For(i, st, en) for(ll i=st; i<en; i++)
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
#define MOD 1000000007
#define INF 1000000000000000007
#define MAXN 200005

// it's swapnil07 ;)

int powmod(int a, int b){
    a = a%MOD;
    int res = 1;
    while(b){
        if(b&1)
            res = (res*a)%MOD;
        a = (a*a)%MOD;
        b = b >> 1;
    }
    return res;
}

signed main(){
    fast
    #ifdef SWAPNIL07
        freopen("/home/swapnil/Desktop/c++/input.txt","r",stdin);
        freopen("/home/swapnil/Desktop/c++/output.txt","w",stdout);
    #endif
    int n, m; cin>>n>>m;
    int ans = (powmod(2, m)-1+MOD)%MOD;
    ans = powmod(ans, n);
    cout<<ans;
    return 0;
}