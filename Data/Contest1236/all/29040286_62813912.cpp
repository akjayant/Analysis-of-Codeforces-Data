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
map<ll,vector<ll>> um1;
map<ll,vector<ll>> um2;


int main() { 
	ll n,m,k;
	cin>>n>>m>>k;
	bool flag=false;
	for(int i=0 ; i<k ; i++){
		cin>>x>>y;
		x--;
		y--;
		um1[x].pb(y);
		um2[y].pb(x);
	}
	
	for(auto &x:um1){
		sort(all(x.ss));
	}
	for(auto &x:um2){
		sort(all(x.ss));
	}
	
	ll xs,ys,xe,ye;
	xs=ys=0;
	xe=n-1;
	ye=m-1;
	ll ans=0;
	
	int tmp=0;
	while(xs<=xe && ys<=ye)
	{
		if(tmp==0){
			if(um1[xs].size()>0){
				ll idx = (lower_bound(all(um1[xs]), ys)-um1[xs].begin());
				if(idx < um1[xs].size() && um1[xs][idx] <= ye) {
					ll val = um1[xs][idx];
					ans += (xe-xs+1)*(ye-val+1);
					ye = val-1;
				}
			}	
			xs++;
		}
		if(tmp==1){
			if(um2[ye].size()>0){
				ll idx = (lower_bound(all(um2[ye]), xs)-um2[ye].begin());
				if(idx < um2[ye].size() && um2[ye][idx] <= xe) {
					ll val = um2[ye][idx];
					ans += (xe-val+1)*(ye-ys+1);
					xe = val-1;
				}	
			}	
			ye--;
		}
		if(tmp==2){
			if(um1[xe].size()>0){
				ll idx = (upper_bound(all(um1[xe]), ye)-um1[xe].begin());
				idx--;
				if(idx >= 0 && um1[xe][idx] >= ys) {
					ll val = um1[xe][idx];
					ans += (xe-xs+1)*(val-ys+1);
					ys = val+1;
				}
			}	
			xe--;
		}
		if(tmp==3){
			if(um2[ys].size()>0){
				ll idx = (upper_bound(all(um2[ys]), xe)-um2[ys].begin());
				idx--;
				if(idx >= 0 && um2[ys][idx] >= xs) {
					ll val = um2[ys][idx];
					ans += (val-xs+1)*(ye-ys+1);
					xs = val+1;
				}		
			}	
			ys++;
		}
		tmp++;
		if(tmp>=4)
			tmp-=4;
	}
	if(ans==k){
		cout<<"Yes";
	} else {
		cout<<"No";
	}
    return 0; 
} 
