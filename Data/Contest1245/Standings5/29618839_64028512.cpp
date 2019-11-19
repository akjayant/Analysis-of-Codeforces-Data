#include<bits/stdc++.h>
#define N 2000

using namespace std;

typedef struct pair<int,int> II;


int par[N+9];
long long minp[N+9];
int pminp[N+9];
II a[N+9];
long long k[N+9];

int findpar(int x)
{
    if(par[x]!=x)
    {
        return par[x]=findpar(par[x]);
    }
    return x;
}

struct edge
{
    int a;
    int b;
    long long c;
    bool operator<(const edge & rhs)const
    {
        return c>rhs.c;
    }
};

priority_queue<edge> q;
set<int> s;


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        scanf("%I64d",&minp[i]);
        ans+=minp[i];
        pminp[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&k[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            q.push({i,j,(k[i]+k[j])*(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second))});
        }
    }
    vector<II> vv;
    while(!q.empty())
    {
        edge x=q.top();
        q.pop();
        int X=findpar(x.a);
        int Y=findpar(x.b);
        if(X==Y)
        {
            continue;
        }
        if(minp[X]+minp[Y]>x.c+min(minp[X],minp[Y]))
        {
            ans+=x.c+min(minp[X],minp[Y])-minp[X]-minp[Y];
            if(minp[X]>minp[Y])
            {
                minp[X]=minp[Y];
                pminp[X]=pminp[Y];
            }
            vv.push_back(II(x.a,x.b));
            par[Y]=X;
        }
    }
    for(int i=1;i<=n;i++)
    {
        s.insert(pminp[findpar(i)]);
    }
    printf("%I64d\n",ans);
    printf("%d\n",s.size());
    for(auto v:s)
    {
        printf("%d ",v);
    }
    printf("\n");
    printf("%d\n",vv.size());
    for(auto v:vv)
    {
        printf("%d %d\n",v.first,v.second);
    }
}
