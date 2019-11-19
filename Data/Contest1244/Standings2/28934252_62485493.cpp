#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
vector<vector<ll> > a(100005);
ll n,c1[100005],c2[100005],c3[100005],ans[100005]={0};
void bfs(ll x)
{
	for(ll i=0;i<a[x].size();i++)
	{
	    if(ans[a[x][i]]==0)
	    {
	        if(ans[x]==3)
	        {
	            ans[a[x][i]]=1;
	            bfs(a[x][i]);
	        }
	        else
	        {
	            ans[a[x][i]]=ans[x]+1;
	            bfs(a[x][i]);
	        }
	    }
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll an,i,j,k,x,y,cal[3][3]={0},aa,ab,ac;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>c1[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>c2[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>c3[i];
	}
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	x=0;
	for(i=1;i<=n;i++)
	{
	    if(a[i].size()==1 && x==0)
	    {
	        x=i;
	    }
	    if(a[i].size()>=3)
	    {
	        cout<<-1;
	        return 0;
	    }
	}
	//cout<<x<<endl;
	ans[x]=1;
	bfs(x);
	for(i=1;i<=n;i++)
	{
		cal[ans[i]-1][0]+=c1[i];
		cal[ans[i]-1][1]+=c2[i];
		cal[ans[i]-1][2]+=c3[i];
	}
	an=cal[0][0]+cal[1][1]+cal[2][2];
	aa=0;
	ab=1;
	ac=2;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				if(i!=j && i!=k && j!=k)
				{
				    if(cal[0][i]+cal[1][j]+cal[2][k]<an)
				    {
					    an=cal[0][i]+cal[1][j]+cal[2][k];
					    aa=i;
					    ab=j;
					    ac=k;
				    }
				}
			}
		}
	}
	cout<<an<<endl;
	for(i=1;i<=n;i++)
	{
	    //cout<<ans[i]<<" ";
	    if(ans[i]==1)
	    {
	        cout<<aa+1<<" ";
	    }
	    else if(ans[i]==2)
	    {
	        cout<<ab+1<<" ";
	    }
	    else
	    {
	        cout<<ac+1<<" ";
	    }
	}
	return 0;
}