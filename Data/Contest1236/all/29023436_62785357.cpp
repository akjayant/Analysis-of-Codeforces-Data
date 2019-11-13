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




	int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
        ll t;
        cin>>t;
        while(t--){
            ll a,b,c;
            cin>>a>>b>>c;
            ll x=a,y=c/2;
            ll ans=0;
            if(y<=b){
                ans+=y;
                if(x<=(b-y)/2)
                    ans+=x;
                else{
                    ans+=(b-y)/2;
                }
                ans*=3;
            }
            else{
                ans+=3*b;
            }
            cout << ans << "\n";
        }
		return 0;
	}

