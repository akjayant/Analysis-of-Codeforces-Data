#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long
#define ld long double

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define repA(i,A)   for(auto i:A)

#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl

#define mp make_pair
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)	A.rbegin(),A.rend()
#define ft first
#define sd second

#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V> 
#define Vpll vector<pll>

#define endl "\n"

const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e15;
#define PI 3.14159265

const ll N = 100005;

ll C[N][3];
V adj[N];
ll D[N];

ll B[N];
V A;

void dfs(ll x, ll p){
	// err1(x);	
	A.pb(x);
	for(auto i:adj[x]){
		if(i!=p)	dfs(i,x);	
	}
}

ll solve(ll a,ll b,ll c){
	ll ans = 0;
	ll n = A.size();
	rep(i,0,n){
		ans += C[A[i]][a];
		i+=2;
	}
	rep(i,1,n){
		ans += C[A[i]][b];
		i+=2;
	}
	rep(i,2,n){
		ans += C[A[i]][c];
		i+=2;
	}
	return ans;
}

void solve1(ll a, ll b,ll c){
	ll n = A.size();
	rep(i,0,n){
		B[A[i]] = a+1;
		i+=2;
	}
	rep(i,1,n){
		B[A[i]] = b+1;
		i+=2;
	}
	rep(i,2,n){
		B[A[i]] = c+1;
		i+=2;
	}
	rep(i,1,n+1)	cout<<B[i]<<" ";cout<<endl;
} 

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    rep(i,0,3)	rep(j,1,n+1)	cin>>C[j][i];
    rep(i,0,n-1){
    	ll u,v;
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	D[u]++;
    	D[v]++;
    }
    bool f=0;
    rep(i,1,n+1){
    	if(D[i]>2)	f=1;
    }
    if(f){
    	cout<<-1<<endl;
    	return 0;
    }
    ll st = -1;
    rep(i,1,n+1)	if(D[i]==1)	st = i;
    dfs(st,0);
    ll a,b,c;
    ll ans = INF;
    ll p;
    ll t = 0;
    a=0;b=1;c=2;
    p = solve(a,b,c); 
    if(p < ans)	ans = p, t = 1;	
    a=0;b=2;c=1;
    p = solve(a,b,c); 
    if(p < ans)	ans = p, t = 2;
    a=1;b=0;c=2;
    p = solve(a,b,c); 
    if(p < ans)	ans = p, t = 3;
    a=1;b=2;c=0;
    p = solve(a,b,c); 
    if(p < ans)	ans = p, t = 4;
    a=2;b=1;c=0;
    p = solve(a,b,c); 
    if(p < ans)	ans = p, t = 5;
    a=2;b=0;c=1;
    p = solve(a,b,c); 
    if(p < ans)	ans = p, t = 6;
    cout<<ans<<endl;
    // 
    if(t==1){
	    a=0;b=1;c=2;
	    solve1(a,b,c);
    } 
    if(t==2){
	    a=0;b=2;c=1;
	    solve1(a,b,c);
    }
    if(t==3){ 
	    a=1;b=0;c=2;
	    solve1(a,b,c);
    }
    if(t==4){ 
	    a=1;b=2;c=0;
	    solve1(a,b,c);
    }
    if(t==5){ 
	    a=2;b=1;c=0;
	    solve1(a,b,c);
    }
    if(t==6){ 
	    a=2;b=0;c=1;
	    solve1(a,b,c);
    } 

    return 0;
}