#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
ll dp[100100][4][4];
int n;
ll c[3][100100];
vector<int> v[100100];
int ans[100100];
int s;
ll go(int cr,int la,int le,int pa)
{
    ll &ret=dp[cr][la][le];
    if(ret!=-1)
        return ret;
    ret=1e18;
    int nx=0;
    for(int i=0;i<v[cr].size();i++)
    {
        if(v[cr][i]!=pa)
            nx=v[cr][i];
    }
    if(v[cr].size()==1&&pa!=0)
    {
        for(int i=0;i<3;i++)
        {
            if(i!=la&&i!=le)
               {ret=min(c[i][cr],ret);}
        }

        return ret;
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            if(i!=la&&i!=le)
            {
                ret=min(ret,c[i][cr]+go(nx,le,i,cr));
            }
        }
    }
    return ret;
}
void take(int cr,int la,int le,int pa)
{
    ll ret=dp[cr][la][le];
    int nx=0;
    for(int i=0;i<v[cr].size();i++)
    {
        if(v[cr][i]!=pa)
            nx=v[cr][i];
    }
    if(v[cr].size()==1&&pa!=0)
    {
        for(int i=0;i<3;i++)
        {
            if(i!=la&&i!=le&&ret==c[i][cr])
                {   ans[cr]=i+1;
                    //cout<<i+1;
                    return;
                }
        }

    }
    else
    {
        for(int i=0;i<3;i++)
        {
            if(i!=la&&i!=le&&ret==c[i][cr]+go(nx,le,i,cr))
            {   ans[cr]=i+1;
                //cout<<i+1<<' ';
                take(nx,le,i,cr);
                return;
            }
        }
    }

}
int main(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&c[i][j]);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>2)
        {
            cout<<-1;
            return 0;
        }
        if(v[i].size()==1)
        {
            s=i;
        }
    }
    //for()
    go(s,3,3,0);
    cout<<dp[s][3][3]<<endl;
    take(s,3,3,0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
    }
//
