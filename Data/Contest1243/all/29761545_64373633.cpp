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
int a[100009];
void solve(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	reverse(a,a+n);
	int mx=0;
	for(int i=0;i<n;i++){
		mx=max(mx,min(i+1,a[i]));
	}
	cout<<mx<<endl;
}
int main(){
	int t;cin>>t;
	while(t--)solve();	
}
