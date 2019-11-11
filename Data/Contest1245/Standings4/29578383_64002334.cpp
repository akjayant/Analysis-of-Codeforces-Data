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
ll cur, sum, res, ans, x, y, z;
ll a[N], b[N], c[N];
vector<ll> vt;


int main() { 
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		ll a,b,c;
		cin>>a>>b>>c;
		ll x,y,z;
		string s;
		cin>>s;
		x=y=z=0;
		for(int i=0 ; i<n ; i++){
			if(s[i]=='R')
				x++;
			else if(s[i]=='P')
				y++;
			else
				z++;
		}
		ll ans = 0;
		
		ll temp1 = min(b, x);
		ans += temp1;
		
		b -= temp1;
		x -= temp1;
		
		ll temp2 = min(c, y);
		ans += temp2;
		
		c -= temp2;
		y -= temp2;
		
		ll temp3 = min(a, z);
		ans += temp3;
		
		a -= temp3;
		z -= temp3;
		
		ll m = (n+1)/2;
		if(ans<m){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		
		for(int i=0 ; i<n ; i++){
			if(s[i]=='R' && temp1 > 0){
				cout<<'P';
				temp1--;
			}
			else if(s[i]=='P' && temp2 > 0){
				cout<<'S';
				temp2--;
			}
			else if(s[i]=='S' && temp3 > 0){
				cout<<'R';
				temp3--;
			} else if(b>0){
				cout<<'P';
				b--;
			}
			else if(c > 0){
				cout<<'S';
				c--;
			}
			else if(a > 0){
				cout<<'R';
				a--;
			}
			
		}
		cout<<"\n";
	}
	
    return 0; 
} 
