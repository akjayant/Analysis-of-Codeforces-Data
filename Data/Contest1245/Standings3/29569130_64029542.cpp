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


ll adj[2005][2005];

typedef pair<ll, int> pi;

int main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin>>n;
	vector <pair<int,int> > v;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back(mp(x,y));
	}
	ll cr[n+2],kr[n+2];
	priority_queue <pi, vector<pi>, greater<pi>  > vc;
	ll ar[n+2];
	ll br[n+2]={0};
	ll fr[n+2]={0};
	for(int i=0;i<n;i++){
		cin>>cr[i];
		ar[i]=cr[i];
		br[i] = i;
		vc.push(mp(cr[i],i));
	}
	for(int i=0;i<n;i++)
		cin>>kr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj[i][j] = (kr[i]+kr[j])*(abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se));
			// cout<<adj[i][j]<<' ';
		}
		// cout<<endl;
	}
	// sort(vc.begin(),vc.end());
	
	for(int i=0;i<n;i++){
		int s=vc.top().se;
		vc.pop();
		while(fr[s]==1){
			s=vc.top().se;
			vc.pop();
		}
		fr[s]=1;
		// cout<<"s "<<s<<endl;
		for(int j=0;j<n;j++){
			if(s==j || fr[j]==1)
				continue;
			if(ar[j]>(adj[j][s])){
				ar[j] = adj[j][s];
				br[j] = s;
				vc.push(mp(ar[j],j));
			}
		}
	}
	ll ans=0,c=0,e=0;
	for(int i=0;i<n;i++){
		ans+= ar[i];
		if(br[i]!=i)
			e++;
		else
			c++;
	}
	cout<<ans<<endl;
	cout<<c<<endl;
	for(int i=0;i<n;i++)
		if(br[i]==i)
			cout<<i+1<<' ';
	cout<<endl;
	cout<<e<<endl;
	for(int i=0;i<n;i++)
		if(br[i]!=i)
			cout<<i+1<<' '<<br[i]+1<<endl;
	return 0;
}

