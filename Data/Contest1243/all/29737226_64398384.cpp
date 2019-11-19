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
const long long infl = LLONG_MAX;


int32_t main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll t,i,x=1,j,y,z,k,n;

cin>>n;
if(n==1){	 cout<<1;	return 0;		}

vector<ll>v;

for(i=1;(i*i)<=n;i++){
	if((n%i) == 0){
		v.pb(i);
		if((i*i)!=n)	v.pb(n/i);
	}
}
// unique_sort(v);
sort(all(v));
z=v.size();
x=0;
rep(i,0,z,1){
	if(v[i]!=1){
		// ce(v[i])
		x=__gcd(x,v[i]);
	}
}
// y=n-x;		while(y<0){		x--;	y=n-x;	}	
x=max(x,1LL);
cout<<x;
}
