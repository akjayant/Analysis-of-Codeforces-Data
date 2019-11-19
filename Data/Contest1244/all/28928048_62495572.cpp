#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double
#define f(i,x,n) for(int i=x;i<n;i++)
#define int long long
#define mod 1000000007
#define endl "\n"
#define MAXN 300001 
const int INF = 1e18;
void fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
int n,c[4][100005];
vector<int>vc[100005];
int vst[100005];
vector<int>vv;
int dfs(int x)
{
	vv.pb(x);
	vst[x]=1;
	for(auto i:vc[x])
	{
		if(vst[i]==0)
		{
			dfs(i);
		}
	}
}
int32_t main() 
{
	fastio();
	cin>>n;
	f(i,1,n+1)
	cin>>c[1][i];
	f(i,1,n+1)
	cin>>c[2][i];
	f(i,1,n+1)
	cin>>c[3][i];
	f(i,0,n-1)
	{
		int a,b;
		cin>>a>>b;
		vc[a].pb(b);
		vc[b].pb(a);
	}
	int st=0;
	f(i,1,n+1)
	{
		if(vc[i].size()>=3)
		{
			cout<<-1;
			return 0;
		}
		if(vc[i].size()==1)
			st=i;
	}
	if(st==0)
		st=1;
	int mn=INF,x,y,z;
	dfs(st);
	f(i,1,4)
	{
		f(j,1,4)
		{
			f(k,1,4)
			{
				int ct=0;
				if(i!=j&&i!=k&&j!=k)
				{
					f(l,0,vv.size())
					{
						if(l%3==0)
						{
							ct+=c[i][vv[l]];
						}
						else if(l%3==1)
						{
							ct+=c[j][vv[l]];
						}
						else
						{
							ct+=c[k][vv[l]];
						}
					}
					if(ct<mn)
					{
						mn=ct;
						x=i;
						y=j;
						z=k;
					}
				}
			}
		}
	}
	int ans[n+1];
	memset(ans,0,sizeof(ans));
	f(i,0,vv.size())
	{
		if(i%3==0)
		{
			ans[vv[i]]=x;
		}
		else if(i%3==1)
		{
			ans[vv[i]]=y;
		}
		else
		{
			ans[vv[i]]=z;
		}
	}
	cout<<mn<<endl;
	f(i,1,n+1)
	cout<<ans[i]<<" ";
}