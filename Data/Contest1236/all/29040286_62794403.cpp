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
#define sz size()
#define pll pair<ll,ll>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)
#define pi 3.14159265358979323846264338
#define spa cout<<endd
#define inf 2000
ll power(ll a , ll b,ll modi) {
    ll res = 1 ;
    while(b) {
        if(b%2)
            res = (res * a) % modi ;
        b/=2 ; a = (a*a) % modi ;
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
ll mod = 1000000007;

int main() { 
	ll n;
	cin>>n;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(j&1){
				cout<<(n*(j-1)) + i;
			} else {
				cout<<j*n - i + 1;
			}		
			cout<<" ";
		}
		cout<<endl;
	}
    return 0; 
} 
