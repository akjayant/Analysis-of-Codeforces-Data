#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second 
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rep(i,a,b) for( ll i = a ; i < b ; i+=1 )
#define pp pair<ll,ll> 
#define sz(v) (ll)(v.size())
#define hell (ll)1000000007
#define slld(x) scanf("%lld",&x)
const ll N = 100005 ;
ll t = 1 ;
void solve() 
{
    ll n ;
    cin >> n ;
    string s ;
    cin >> s;
    ll ans = n ;
    rep( i , 0 , n ){
        if(s[i]=='1'){
            ans=max(ans,2*(i+1));
            ans=max(ans,2*(n-i));
        }
    }
    cout << ans << "\n" ;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t ;
    while(t--){
        solve();
    }
    return 0 ;
}
