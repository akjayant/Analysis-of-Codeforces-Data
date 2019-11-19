/*
Author: Arjan Singh Bal, IIITM Gwalior
"Everything in this world is magic, except to the magician"
*/

#include                        <bits/stdc++.h>
#ifdef LOCAL
#include                        "pprint.hpp"
#endif

using namespace std;

#define prn(...) __f(__VA_ARGS__)
template <typename Arg1>
void __f(Arg1&& arg1)
{
    cout<<arg1<<"\n";
}
template <typename Arg1, typename... Args>
void __f(Arg1&& arg1, Args&&... args)
{
    cout<<arg1<<" "; __f(args...);
}

#define read(...) __g(__VA_ARGS__)
template <typename Arg1>
void __g(Arg1&& arg1)
{
    cin>>arg1 ;
}
template <typename Arg1, typename... Args>
void __g(Arg1&& arg1, Args&&... args)
{
    cin>>arg1; __g(args...);
}

#define ll                      long long
#define pii                     pair<int, int>
#define pli                     pair<ll, int>
#define pil                     pair<int, ll>
#define pll                     pair<ll, ll>
#define pdd                     pair<double, double>
#define vi                      vector<int>
#define vc                      vector<char>
#define vll                     vector<ll>
#define vb                      vector<bool>
#define vd                      vector<double>
#define vs                      vector<string>
#define ff                      first
#define ss                      second
#define pb                      push_back
#define eb                      emplace_back
#define ppb                     pop_back
#define pf                      push_front
#define ppf                     pop_front
#define vpii                    vector<pii>
#define umap                    unordered_map
#define all(x)                  x.begin(),x.end()
#define clr(a,b)                memset(a,b,sizeof a)
#define fr(i,n)                 for(int i=0; i<n;++i)
#define fr1(i,n)                for(int i=1; i<=n; ++i)
#define precise(x)              cout<<fixed<<setprecision(x)

const int N=1e5+1;

int n;
vi adj[N], path;
int deg[N], col[N], bcol[N];
ll cost[3][N];
bool seen[N]={};
ll ans=1e18;
vi vec={0, 1, 2};

void cal()
{
	ll cur=0;
	fr(i, n){
		int ccol=vec[i%3];
		col[path[i]]=ccol;
		cur+=cost[ccol][path[i]];
	}
	if(cur>=ans) return ;
	ans=cur;
	fr1(i, n){
		bcol[i]=col[i];
	}
}

int main()
{
	//freopen("in.txt" , "r" , stdin) ;
	//freopen("out.txt" , "w" , stdout) ;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	fr(i, 3){
		fr1(j, n){
			cin>>cost[i][j];
		}
	}

	fr(i, n-1){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
		++deg[a];
		++deg[b];
	}

	int v1;

	fr1(i, n){
		if(deg[i]>=3){
			prn(-1);
			return 0;
		}
		if(deg[i]==1) v1=i;
	}

	seen[v1]=1;
	path.pb(v1);

	while(path.size()<n){
		v1=path.back();
		for(auto i:adj[v1])
			if(seen[i]) continue;
			else v1=i;
		seen[v1]=1;
		path.pb(v1);
	}

	cal();

	while(next_permutation(all(vec))){
		cal();
	}

	prn(ans);

	fr1(i, n){
		cout<<bcol[i]+1<<" ";
	}
	
	return 0;
}