/*
Code Author: ADITYA SHETH (^_^)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define endl "\n" 
#define int long long // remove when constraints are tight.
/*-------------------------------------------------------------------------------------------------------------------------------------*/

const int N=1e5+100;
int n;
int c[3][N];
vector<int> adj[N];

vector<int> cur;
vector<int> ans;
int mi=1e18;
void dfs(int node,int parent,int prev,int prev_prev)
{
	int col;
	for(int i=0;i<3;i++)
	{
		if(i!= prev && i!=prev_prev)
		{
			col=i;
			break;
		}
	}
	cur[node]=col;
	for(auto x: adj[node])
	{
		if(x!=parent)
		{
			dfs(x,node,col,prev);
		}
	}
}

void update()
{
	int sumcur=0;
	for(int i=1;i<=n;i++)
	{
		sumcur+=c[cur[i]][i];
	}
	if(sumcur<mi)
	{
		mi=sumcur;
		ans=cur;
	}
}
int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<3;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	int root=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(adj[i].size()>=3)
		{
			flag=0;
		}
		if(adj[i].size()==2)
		{
			root=i;
		}
	}
	if(!flag)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	cur.resize(n+1,0);
	ans.resize(n+1,10000000000);

	dfs(adj[root][0],root,0,1);
	dfs(adj[root][1],root,0,2);
	cur[root]=0;
	update();

	dfs(adj[root][0],root,0,2);
	dfs(adj[root][1],root,0,1);
	cur[root]=0;
	update();

	dfs(adj[root][0],root,1,0);
	dfs(adj[root][1],root,1,2);
	cur[root]=1;
	update();

	dfs(adj[root][0],root,1,2);
	dfs(adj[root][1],root,1,0);
	cur[root]=1;
	update();

	dfs(adj[root][0],root,2,1);
	dfs(adj[root][1],root,2,0);
	cur[root]=2;
	update();

	dfs(adj[root][0],root,2,0);
	dfs(adj[root][1],root,2,1);
	cur[root]=2;
	update();
	
	cout<<mi<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]+1<<" ";
	}
}
