//raja1999

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define int ll

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

//std::ios::sync_with_stdio(false);
int ans=0;
vector<vi>adj(100005);
int col[100005],val[3][3],c[3][100005],deg[100005];
int dfs(int u,int p,int par,int cur){
	int i,id;
	ans+=c[cur][u];
	rep(i,3){
		if(i!=par&&i!=cur){
			id=i;
		}
	}
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			dfs(adj[u][i],u,cur,id);
		}
	}
}
int print(int u,int p,int par,int cur){
	int i,id;
//	ans+=c[cur][u];
	col[u]=cur;
	rep(i,3){
		if(i!=par&&i!=cur){
			id=i;
		}
	}
	rep(i,adj[u].size()){
		if(adj[u][i]!=p){
			print(adj[u][i],u,cur,id);
		}
	}
}
main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int t,t1;
	//cin>>t;
	t=1;
	t1=t;
	while(t--){
		int n,i,j,u,v,fl=0,root,minn=inf;
		minn*=inf;
		cin>>n;
		rep(i,3){
			rep(j,n){
				cin>>c[i][j];
			}
		}
		rep(i,n-1){
			cin>>u>>v;
			u--;
			v--;
			deg[u]++;
			deg[v]++;
			adj[u].pb(v);
			adj[v].pb(u);
			if(deg[u]>=3||deg[v]>=3){
				fl=1;
			}
		}
		if(fl){
			cout<<-1<<endl;
		}
		else{
			rep(i,n){
				if(deg[i]==1){
					root=i;
				}
			}
			rep(i,3){
				rep(j,3){
					if(i!=j){
						ans=c[i][root];
						dfs(adj[root][0],root,i,j);
						val[i][j]=ans;
						minn=min(minn,val[i][j]);
					}
				}
			}
			rep(i,3){
				rep(j,3){
					if(i!=j&&val[i][j]==minn){
						col[root]=i;
						print(adj[root][0],root,i,j);
						break;
					}
				}
			}
			cout<<minn<<endl;
			rep(i,n){
				cout<<col[i]+1<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
} 
	