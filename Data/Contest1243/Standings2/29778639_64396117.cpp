#include<bits/stdc++.h>
#define dd(x) cout<<#x<<" = "<<x<<" "
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define sz(x) int(x.size())
#define All(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef priority_queue<int> BQ;
typedef priority_queue<int,vector<int>,greater<int> > SQ;
const int maxn=1e5+10,mod=1e9+7,INF=0x3f3f3f3f;

int main()
{
	ll n;
	cin>>n;
	vector<ll> p;
	ll x=n;
	for (ll i=2;i*i<=x;++i){
		if (x%i==0){
			p.pb(i);
			while (x%i==0)
				x/=i;
		}
	}
	if (x!=n&&x>1)
		p.pb(x);
	if (!sz(p))
		cout<<n;
	else if (sz(p)>1)
		cout<<1;
	else
		cout<<p[0];
	return 0;
}