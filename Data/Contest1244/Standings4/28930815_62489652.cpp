//BADBUOY//
#include <bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ll    long long
#define ld    long double
#define sz(s) (ll)s.size() 
#define vl    vector < ll >
#define pll   pair < ll, ll >
#define ml    map < ll, ll >
#define MOD   1000000007
#define MAXN  50005 
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define inv(i,a,b)  for(ll i=a;i>=b;i--)
#define all(a)  (a).begin(),(a).end()
using namespace std;

ll t,n,m,k,x,y,z,p,w,d,ans,val;
int main(){
	IOS;
	cin>>n>>p>>w>>d;
	z=(p-n*d+w-d-1)/(w-d);
	z=max(z,0LL);
	y=(d-(d-(p%d))%d)%d;
	rep(i,0,1e7+5){
		if(z>n) break;
		if(((w-d)*z)%d==y&&(w-d)*z>=(p-n*d)){
			m=(z*(w-d)+n*d-p)/d;
			if(z+m>n) break; 
			val=1; break;
		}
		z++;
	}
	if(val&&z*w+(n-z-m)*d==p){
		cout<<z<<" "<<(n-z-m)<<" "<<m;
	}
	else cout<<-1;

	return 0;
}