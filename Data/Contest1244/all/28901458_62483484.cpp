#include<bits/stdc++.h>
#pragma GCC optimize ("-ffloat-store")
#define ll long long
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define maxn 100003
#define pb push_back
#define X first
#define Y second
#define mod 1000000007
#define base 17
#define vc 1e18
using namespace std;
typedef pair<ll,ll> ii;
ll deg[maxn];
vector<ll> ke[maxn];
vector<ll> vertices;
ll n,u,v;
ll c[6][maxn];
ll f[maxn][4][4];
ii track[maxn][4][4];
ll color[maxn];
void dfs(ll x, ll par){
//	ll << x << " " << par << "\n";
	vertices.pb(x);
	for(ll &u:ke[x]){
		if(u==par) continue;
		dfs(u,x);
	}
}
main(){
//	ios_base::sync_with_stdio(0);
//	cin.tie(NULL);
//    ll.tie(NULL);   
    cin >> n;
    For(j,1,3)
    For(i,1,n){
    	cin >> c[j][i];
	}
	ll maxdeg = 0;
	For(i,1,n-1){
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		ke[u].pb(v);
		ke[v].pb(u);
		maxdeg  =max(maxdeg, deg[u]);
		maxdeg  =max(maxdeg, deg[v]);		
	}
	if(maxdeg>=3){
		cout << -1;
	}	else	{
		ll src = 0;
		For(i,1,n){
			if(deg[i]==1){
				src = i;
				break;
			}
		}
		vertices.pb(0);
		dfs(src,src);
//		for(ll &v:vertices){
//			ll << v << " ";
//		}
//		ll << "!";
		For(i,1,n+1){
			For(c1,1,3){
				For(c2,1,3){
					f[i][c1][c2] = vc;
				}
			}
		}
				
		For(i,0,n-1){
			For(c1,1,3){
				For(c2,1,3){
					if(c1==c2) continue;
					ll c3 = 6-c1-c2;
					if(f[vertices[i]][c1][c2]+c[c3][vertices[i+1]] < f[vertices[i+1]][c2][c3] ){						
						f[vertices[i+1]][c2][c3] = f[vertices[i]][c1][c2]+c[c3][vertices[i+1]];
						track[vertices[i+1]][c2][c3] = {c1,c2};
					}
				}
			}
		}
		ll ans = vc;
		ii state;
		For(c1,1,3){
			For(c2,1,3){
				if(c1==c2) continue;				
				if(ans > f[vertices[n]][c1][c2]){
					ans = f[vertices[n]][c1][c2];
					state = {c1,c2};
				}				
			}
		}
		cout << ans << "\n";
		int cur = n;
		do{
			color[vertices[cur]] = state.Y;
			cur --;
			state = track[cur][state.X][state.Y];
		}	while(cur>=1);
		For(i,1,n){
			cout << color[i] << " ";
		}
	}
}
