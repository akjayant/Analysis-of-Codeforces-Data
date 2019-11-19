//Your limitation—it’s only your imagination
//order_of_key(k): Number of items strictly smaller than k .
//find_by_order(k): K-th element in a set (counting from zero).
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define full(x,n) x,x+n+1
#define full(x) x.begin(),x.end()
#define finish return 0

#define putb push_back
#define f first
#define s second

#define ordered_set tree<ll,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define putf push_front
#define gainb pop_back

#define gainf pop_front
#define len(x) x.size()

//Dream it. Wish it. Do it

// 1/b%mod=b^(m-2)%mod

typedef double db;
typedef long long ll;

//Never forget health

const ll ary=1e5+5;
const ll mod=1e9+7;
const ll inf=1e18;

using namespace std;
using namespace __gnu_pbds;
ll n;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	ll ans=0;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			if(i>1){
				ans=__gcd(ans,i);
			}
			ans=__gcd(ans,n/i);
		}
	}
	cout<<ans;
}
//Push yourself, because no one else is going to do it for you
