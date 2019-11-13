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
int n;
string s1,s2;
void solve(){
	cin>>n;
	cin>>s1>>s2;
	int id=-1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			id=i;
			break;
		}
	}
	if(id==-1){cout<<"YES"<<endl;return;}
	for(int i=id+1;i<s1.size();i++){
		if(s1[i]==s1[id] && s2[id]==s2[i]){
			swap(s1[i],s2[id]);
			break;
		}
	}
	if(s1==s2)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main(){
	int t;cin>>t;
	while(t--)solve();	
}
