#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v[100000];
ll ans;
int n;
ll c[100009][3];
int pat[3];
ll dfs(int x,int par,int lev)
{
    ll sum=c[x][pat[lev%3]];
    lev++;;
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        if(y==par)continue;
        sum+=dfs(y,x,lev);
    }
    return sum;
}
int out[100009];
void df(int x,int par,int lev)
{
    out[x]=lev%3;
    lev++;
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        if(y==par)continue;
        df(y,x,lev);
    }
    lev--;
}
int org[3];
int main()
{
    cin>>n;
    for(int j=0;j<3;j++)
    {
        for(int i=0;i<n;i++)
        {
            cin>>c[i][j];
        }
    }
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int root;
    for(int i=0;i<n;i++)
    {
        if(v[i].size()>=3)
        {
            cout<<-1;
            return 0;
        }
        if(v[i].size()==1)root=i;
    }
    ans=1e18;
    for(int i=0;i<3;i++)
    {
        pat[0]=i;
        for(int j=0;j<3;j++)
        {
            if(j==i)continue;
            pat[1]=j;
            for(int k=0;k<3;k++)
            {
                if(k==j)continue;
                if(k==i)continue;
                pat[2]=k;
                ll x=dfs(root,-1,0);
                if(ans>=x)
                {
                    ans=x;
                    for(int l=0;l<3;l++)org[l]=pat[l];
                }
            }
        }
    }
     cout<<ans<<"\n";
     df(root,-1,0);
    for(int i=0;i<n;i++)cout<<org[out[i]]+1<<" ";
}
