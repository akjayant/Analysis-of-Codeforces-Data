#include<bits/stdc++.h>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pr pair<int,int>
#define pll pair<long long,long long>
#define ll long long
#define v vector
#define all(a) a.begin(),a.end()
#define ina(a,i,n) for(i=0;i<n;i++)cin>>a[i]
#define mmst(a) memset(a,0,sizeof(a))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define pi 3.14159265358979
int color[3][100005];
v<v<int> > graph(100006);

int perm[6][3] = {
	{0,1,2},
	{0,2,1},
	{1,0,2},
	{1,2,0},
	{2,0,1},
	{2,1,0}
};

bool vis[100005];
ll ans = 0;
void dfs(int s, int ind, int c) {
	vis[s] = 1;
	ans += color[perm[ind][c]][s];
	c++;
	c%=3;
	for(int i=0;i<graph[s].size();i++) {
		if(!vis[graph[s][i]]) {
			dfs(graph[s][i], ind, c);
		}
	}
}

int node[100005];

void dfs2(int s, int ind, int c) {
	vis[s] = 1;
	node[s] = perm[ind][c] + 1;
	c++;
	c%=3;
	for(int i=0;i<graph[s].size();i++) {
		if(!vis[graph[s][i]]) {
			dfs2(graph[s][i], ind, c);
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif
    int i,j,k,n,t;
    cin>>n;
    for(int i=0;i<3;i++) {
    	for(j=0;j<n;j++) {
    		cin>>color[i][j];
    	}
    }

    for(int i=0;i<n-1;i++) {
    	int x,y;
    	cin>>x>>y;
    	x--;
    	y--;
    	graph[x].pb(y);
    	graph[y].pb(x);
    }

    for(int i=0;i<n;i++) {
    	if(graph[i].size() > 2) {
    		cout<<-1;
    		return 0;
    	}
    }
    int root;
    for(int i=0;i<n;i++) {
    	if(graph[i].size() == 1)
    		root = i;
    }
    ll fans = LLONG_MAX;

    int findex = 0;
    for(i=0;i<6;i++) {
    	ans = 0;
    	memset(vis, false, sizeof(vis));
    	dfs(root, i, 0);
    	if(ans < fans) {
    		fans = ans;
    		findex = i;
    	}
    }

    memset(vis, false, sizeof(vis));
    dfs2(root, findex, 0);
    cout<<fans<<endl;
    for(i =0;i<n;i++) {
    	cout<<node[i]<<" ";
    }
  	return 0;
}
