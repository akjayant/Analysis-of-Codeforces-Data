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

ll t,n,m,k,x,y,a,b,c,d,ans,val;
int main(){
	IOS;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>k;
		x=a/c+((a%c)?1:0);
		y=b/d+((b%d)?1:0);
		if(x+y>k) cout<<-1<<"\n";
		else cout<<x<<" "<<y<<"\n";
	}

	return 0;
}