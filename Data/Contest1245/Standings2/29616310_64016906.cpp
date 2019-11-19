// Kya dekhega re chokre
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define ln endl	

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
const double EPS = 1e-9;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int n;
	cin>>n;

	ll x[n], y[n];
	ll c[n], k[n];
	forn(i,n) cin>>x[i]>>y[i];
	forn(i,n) cin>>c[i];
	forn(i,n) cin>>k[i];

	priority_queue<pair<ll,p32> > q;

	bool present[n] = {0};

	forn(i,n){
		q.push(mp(-c[i],mp(i,-1)));
	}

	v32 pow;
	vp32 join;
	ll ans = 0;

	while(!q.empty()){
		pair<ll,p32> t = q.top();
		q.pop();

		if(t.se.se == -1){
			if(present[t.se.fi] == 1) continue;
			t.fi = -t.fi;
			ans += t.fi;
			present[t.se.fi] = 1;
			pow.pb(t.se.fi);

			int ind = t.se.fi;
			ll cost = t.se.se;
			forn(i,n){
				if(!present[i]){
					q.push(mp(-(k[i]+k[ind])*(abs(x[i]-x[ind])+abs(y[i]-y[ind])),mp(ind,i)));
				}
			}


		}
		else{
			if(present[t.se.fi] == 1 && present[t.se.se] == 1) continue;
			int ind = t.se.se;
			forn(i,n){
				if(!present[i]){
					q.push(mp(-(k[i]+k[ind])*(abs(x[i]-x[ind])+abs(y[i]-y[ind])),mp(ind,i)));
				}
			}
			present[t.se.fi] = 1;
			present[t.se.se] = 1;
			t.fi = -t.fi;
			ans += t.fi;
			join.pb(t.se);
		}

	}

	cout<<ans<<ln;
	cout<<pow.size()<<ln;
	forstl(r,pow) cout<<r+1<<" ";
	cout<<ln;
	cout<<join.size()<<ln;
	forstl(r,join) cout<<r.fi+1<<" "<<r.se+1<<ln;


	return 0;
}