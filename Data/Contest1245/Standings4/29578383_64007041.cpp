#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define endd "\n"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test ll t;cin>>t;while(t--)
#define input freopen("inp.txt","r",stdin)
#define output freopen("out1.txt","w",stdout)
#define loop(i,n) for(ll i=0;i<n;i++)
#define rloop(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,n) for(ll i=1;i<=n;i++)
#define RFOR(i,n) for(ll i=n;i>0;i--)
#define cloop(i,x,y) for(ll i=(x);i<=(y);++i)
#define bug(a) cout << #a << " = " << a << endl;
#define fbug(a, x, y) { cout << #a << ": "; cloop(i, x, y) cout << a[i] << ' '; cout << endl; }
#define sz size()
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)
#define pi 3.14159265358979323846264338
#define mset(x,t) memset(x,t,sizeof x);
#define spa cout<<endd
#define com(x)#x
#define inf 2000
ll power(ll a , ll b,ll modi)
{
    ll res = 1 ;
    while(b)
    {
        if(b%2) {
            res = (res * a) % modi ;
        }
        b/=2 ;
        a = (a*a) % modi ;
    }
    return res ;
}
ll dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
ll diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
ll dx[]= {-1,1,0,0};
ll dy[]= {0,0,-1,1};
 
//*******************************TEMPLATE ENDS HERE *******************//
 
#define N 1000005
ll n, m, k;
ll cur, sum, res, x, y, z;
ll dp[N], b[N], c[N];
vector<ll> vt;
string s;
ll mod = 1000000007;

ll fun(ll i){
	if(i<0){
		return 1;
	}
	if(dp[i]!=-1)
		return dp[i];
		
	ll ans = fun(i-1);
	if(i>0 && (s[i]=='u' || s[i]=='n') && s[i]==s[i-1]){
		ans += fun(i-2);
	}
	if(ans >= mod)
		ans -= mod;
	return dp[i] = ans;
}
int main() { 
	memset(dp, -1, sizeof(dp));
	
	cin>>s;
	n = s.length();
	for(int i=0 ; i<n ; i++){
		if(s[i]=='w' || s[i]=='m'){
			cout<<"0";
			return 0;
		}
	}
	
	cout<<fun(n-1);
    return 0; 
} 
