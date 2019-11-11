#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 100002
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
//#define db(x) cerr << "[" << #x << ": " << (x) << "] ";
#define db(x) ;
using namespace std;
typedef pair<char,ll> ci;
string s;
ll f[maxn];
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);   
    cin >> s;
    ll n = s.length();
    f[0] = f[1] = 1;
    For(i,2,n){
    	f[i] = (f[i-1] + f[i-2])%mod;
	}
    char cur = s[0];
    ll cnt = 1;
    vector<ci> vt;
    For(i,1,n){
    	if(i==n || s[i]!=s[i-1]){
    		vt.pb({s[i-1],cnt});
    		cnt = 1;
		}	else	{
			cnt++;
		}
	}
	vector<ll> care;
	bool mark = false;
	for(ci &e:vt){
		if(e.X=='u'||e.X=='n'){
			care.pb(e.Y);
		}
		if(e.X=='m' || e.X=='w'){
			mark = true;
			break;
		}
	}
	if(mark){
		cout << "0";
	}	else{		
		ll ans = 1;
		for(ll &v:care){
	//		cout << v << " ";
			ans *= f[v];
			ans %= mod;
		}
		cout << ans;
	}
}
