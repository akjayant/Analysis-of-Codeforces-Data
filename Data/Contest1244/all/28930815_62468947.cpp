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

ll t,n,m,k,x,y,z,a[500005],ans,val;
int main(){
	IOS;
	cin>>t;
	while(t--){
		cin>>n;
		string s;
		cin>>s;
		z=0;
		rep(i,0,n){
			if(s[i]=='1'){
				x=i,z=1;
				break;
			}
		}
		inv(i,n-1,0)
			if(s[i]=='1'){
				y=i;
				break;
			}
		ans=0;
		ans=max(2*(n-x),2*(y+1));
		if(!z) cout<<n<<"\n";
		else cout<<ans<<"\n";
	}

	return 0;
}