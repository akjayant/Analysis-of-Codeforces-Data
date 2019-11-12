#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define ll long long int
#define ld unsigned long long int
#define pi pair<ll,ll>
#define pb push_back
#define pf push_front
#define pu push
#define po pop
#define fi first
#define se second
#define mk make_pair
#define ve vector
#define lr(n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define be begin
#define sz(a) (ll)a.size()
#define INF 1e18

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

ll mod = 1e9+7;

ll fun(ll x, ll y){
    ll rem=1;
    while(y!=0){
        if(y%2==1){
            rem=(rem*x)%mod;
        }
        x=(x*x)%mod;
        y/=2;
    }
    return rem;
}


	int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
        ll n,m;
        cin>>n>>m;
        ll ans=(fun(2,m)-1+mod)%mod;
        ans=fun(ans,n);
        cout << ans << "\n";
		return 0;
	}

