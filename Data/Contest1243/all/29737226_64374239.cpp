#include <bits/stdc++.h>
using  namespace std;

#define endl '\n'
#define ll long long
#define re register
#define pb(x) push_back(x)
#define ce(x) cout << x << '\n';

using db = long double;
using pll = pair < ll, ll >;

#define rep(i,x,n,inc) for(i=x ; i<n ; i+=inc)
#define repr(i,x,n,inc) for( i=x ; i>n ; i+=inc)
#define all(a)      (a).begin(),(a).end()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))

#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define hell 1000000007
const db pi = acos(-1);
const long long infl = LLONG_MAX;

#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Fill(s,v) memset(s,v,sizeof(s))
#define cout_p(x, p) cout << fixed << setprecision((p)) << x << endl     //print with precision

#define tc(tt) \
    ll tt;    \
    cin >> tt; \
    for (ll _tt = 0; _tt < tt; _tt++) // testcase 

int32_t main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll t,i,x,j,y,z,k,n;

tc(tt){
	cin>>n;	k=0;
	ll a[n];
	rep(i,0,n,1)	cin>>a[i];
	sort(a,a+n);	
	ll mi=a[0],c;
	rep(i,0,n,1){
		c=a[i];
		k=max(k,min(c,n-i));
	}
	ce(k)
}
}
