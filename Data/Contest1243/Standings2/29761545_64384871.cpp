#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=1e18*4;
const ld pai=acos(-1);
int n,z;
string s1,s2;
vpi v;
void find(int id,char x){
	int here=-1;
	for(int i=id+1;i<n;i++){
		if(s1[i]==x){
			swap(s1[i],s2[id]);
			v.pb({i,id});
			return ;
		}
		if(s2[i]==x){
			swap(s1[i],s2[i]);
			swap(s1[i],s2[id]);
			v.pb({i,i});
			v.pb({i,id});
			return ;
		}
	}
	z=1;
}
void solve(){
	z=0;
	v.clear();
	cin>>n>>s1>>s2;
	for(int i=0;i<n;i++){
		if(s1[i]==s2[i])C;
		find(i,s1[i]);
		if(z){cout<<"NO"<<endl;return;}
	}
	if(s1==s2){
		cout<<"YES"<<endl;
		cout<<v.size()<<endl;
		for(auto u:v)cout<<u.fi+1<<" "<<u.se+1<<endl;
	}
	else cout<<"NO"<<endl;
}
int main(){
	int t;cin>>t;
	while(t--)solve();	
}
