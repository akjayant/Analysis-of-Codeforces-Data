#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout <<#x<<":"<<x<<endl;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl '\n'
#define mod 1000000007
#define int long long
signed main(){
    fast;
	int n,m;cin>>n>>m;
	vector<ll> v(100005);
	v[0] = 2;
	v[1] = 2;
	v[2] = 2;
	for(int i=3;i<100005;i++){
		v[i] = v[i-1]+ v[i-2] ;
		v[i]%=mod;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans+=v[i];
		ans%=mod;
	}
	for(int i=1;i<m;i++){
		ans+=v[i];
		ans%=mod;
	}
	cout<<ans;
}
