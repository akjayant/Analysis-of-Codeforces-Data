#include <iostream>
#include <bits/stdc++.h>
using  namespace std;

#define endl '\n'
#define ll long long
#define re register
#define pb(x) push_back(x)
#define ce(x) cout << x << endl;

using db = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

#define rep(i,x,n,inc) for(i=x ; i<n ; i+=inc)
#define repr(i,x,n,inc) for( i=x ; i>n ; i+=inc)
#define all(a)      (a).begin(),(a).end()
#define rall(x) (x).rbegin(), (x).rend()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))

#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define hell 1000000007
const db pi = acos(-1);
const long long infl = LLONG_MAX;
const int inf = 0x3f3f3f3f;

#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Fill(s,v) memset(s,v,sizeof(s))
#define cout_p(x, p) cout << fixed << setprecision((p)) << x << endl     //print with precision

ll n,m,k;

void dfs(ll i,ll j,vector<int> d[]){
	if(i==0 && j==0){
		d[0][0]=0;
		dfs(i+1,j,d);		dfs(i+1,j+1,d);		dfs(i,j+1,d);
		d[0][0]=1;
		dfs(i+1,j,d);		dfs(i+1,j+1,d);		dfs(i,j+1,d);
	}
	if(i==n){
		if(j==m)	k=(k+1)%hell;
		else return;
	}
	if(j==m){
		if(i==n)	k=(k+1)%hell;
		else return;
	}
	
	if(d[i-1][j]==1){
		if(d[i][j-1]==1){
			d[i][j]=0;
			dfs(i+1,j,d);		dfs(i+1,j+1,d);		dfs(i,j+1,d);
		}
		else {
			d[i][j]=0;
			dfs(i+1,j,d);		dfs(i+1,j+1,d);		dfs(i,j+1,d);
			d[i][j]=1;
			dfs(i+1,j,d);		dfs(i+1,j+1,d);		dfs(i,j+1,d);
		}
	}
	else{
		if(d[i][j-1]==1){
			d[i][j]=0;
			dfs(i+1,j,d);		dfs(i+1,j+1,d);		dfs(i,j+1,d);
			d[i][j]=1;
			dfs(i+1,j,d);		dfs(i+1,j+1,d);		dfs(i,j+1,d);
		}
		else {
			d[i][j]=1;
			dfs(i+1,j,d);		dfs(i+1,j+1,d);		dfs(i,j+1,d);
		}
	}
	return ;
}

int32_t main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t,i,x,j,y,z;
k=0;
cin>>n>>m;
x=max(n,m);
ll a[x+1];
a[0]=1;a[1]=1;a[2]=2;
for(i=3;i<=x;i++)    a[i]=(a[i-1]%hell+a[i-2]%hell)%hell;
k=(((a[n]+a[m]-1)%hell+hell)*2)%hell; 
ce(k)
}
