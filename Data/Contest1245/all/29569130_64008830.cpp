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

ll ar[100005];

int main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='m' || s[i]=='w'){
			cout<<0<<endl;
			return 0;
		}
	}
	ar[0]=1;
	ar[1]=1;
	for(int i=2;i<=n;i++){
		ar[i] = (ar[i-1]+ar[i-2])%mod;
	}
	int i=0;
	ll ans=1;
	// cout<<"hi"<<endl;
	while(i<n){
		if(s[i]!='u' && s[i]!='n'){
			i++;
			continue;
		}
		int c=0;
		// cout<<i<<' '<<cout<<endl;
		while(i+c<n && s[i+c]==s[i])
			c++;
		ans = (ans*ar[c])%mod;
		i = i+c;
	}
	cout<<ans<<endl;
	return 0;
}

