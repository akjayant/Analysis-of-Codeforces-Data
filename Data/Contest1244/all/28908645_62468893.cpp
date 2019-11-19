#include<bits/stdc++.h>
#define ll        	long long 
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)  for(ll int i=a;i<b;i++)
#define rrep(i,a,b) for(ll int i=a;i>=b;i--)
#define all(a)      (a).begin(),(a).end()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define tr(i, cont) for(auto i=cont.begin();i!=cont.end();i++)
#define ios        	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define trace(x)                 cerr << #x << ": " << x << "\n";
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n";
#define endl "\n"
using namespace std;

int main(){
	ios;
	ll tc;
	cin>>tc;
	while(tc--){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll f1=n,l1=-1;
		rep(i,0,s.size()){
			if(s[i]=='1'){
				f1=min(f1,i);
				l1=max(l1,i);
			}
		}
		if(l1==-1){
			cout<<n<<endl;
		}
		else{
			cout<<max(2*(n-f1),2*(l1+1))<<endl;
		}
	}
}
