//amitgomi
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define sc(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
 
///////////////////////////////////////////////////////////
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// ordered_set st;
// st.order_of_key(l);
// double PI=3.1415926535897932384626;
// ll bin_expo(ll a,ll b, ll m){ ll res =1; a %= m; while(b!=0){ if(b%2==1) res = (res*a)%mod; a = (a*a)%mod; b = b/2; } return res; }
// ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); } 
///////////////////////////////////////////////////////////////////////////////////////////////////

int ar[100005];
vector <pair<ll,ll> > v;
ll frs[100005];
ll brs[100005];
ll frc[100005];
ll brc[100005];

ll ffnd(ll sum){
	int l=0,r = v.size()-1;

	while(l<r){
		int mid = (l+r+1)/2;
		if(frs[mid]<=sum){
			l = mid;
		}
		else
			r= mid-1;
	}
	ll res = v[l].fi;
	res += (sum-frs[l])/frc[l];
	return res;
}
ll bfnd(ll sum){
	int l=0,r = v.size()-1;

	while(l<r){
		int mid = (l+r)/2;
		if(brs[mid]<=sum){
			r = mid;
		}
		else
			l= mid+1;
	}
	ll res = v[r].fi;
	res -= (sum-brs[r])/brc[r];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n,k;
	cin>>n>>k;
	map<ll,ll> mp;
	for(int i=0;i<n;i++){
		cin>>ar[i];
		mp[ar[i]]++;
	}
	for(auto it:mp){
		v.push_back(it);
		// cout<<it.fi<<' '<<it.se<<endl;
	}
	// cout<<endl;
	
	ll sum=0,cnt=0;
	for(int i=0;i<v.size();i++){
		if(i!=0)
			sum += cnt*(v[i].fi-v[i-1].fi);
		frs[i] = sum;
		cnt += v[i].se;
		frc[i] = cnt;
	}

	sum=0,cnt=0;
	for(int i=v.size()-1;i>=0;i--){
		if(i!=v.size()-1)
			sum += cnt*(v[i+1].fi-v[i].fi);
		brs[i] = sum;
		cnt += v[i].se;
		brc[i] = cnt;
	}


	ll ans = v[v.size()-1].fi-v[0].fi;
	for(int i=0;i<v.size();i++){
		if(k-frs[i]<0)
			break;
		ll x = bfnd(k-frs[i]);
		ans = max(0LL,min(ans,x-v[i].fi));
	}
	for(int i=v.size()-1;i>=0;i--){
		if(k-brs[i]<0)
			break;
		ll x = ffnd(k-brs[i]);
		// cout<<i<<' '<<x<<endl;
		ans = max(0LL,min(ans,v[i].fi-x));
	}
	cout<<ans<<endl;
	return 0;
}