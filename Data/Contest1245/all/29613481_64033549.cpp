#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>


using namespace std;

#define ll long long
struct Edge
{
    int u,v;
    ll w;
}edge[2010*2010];
struct Point
{
    int x,y;
    int c,k;
}pn[2100];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int fa[2100];
int findfa(int a)
{
    if(fa[a] == a) return a;
    return fa[a] = findfa(fa[a]);
}
int ok[2010];
void swap(int &a,int &b)
{
    int t = a;
    a = b;
    b = t;
}


int main()
{
    int n;
    cin>>n;
    int i,j,k;
    for(i = 0;i<n;i++)
    {
        cin>>pn[i].x>>pn[i].y;
    }
    for(i = 0;i<n;i++)
        cin>>pn[i].c;
    for(i = 0;i<n;i++)
        cin>>pn[i].k;
    int id = 0;
    for(i = 0;i<n;i++)
    {
        for(j = i+1;j<n;j++)
        {
            edge[id].u = i;
            edge[id].v = j;
            edge[id].w = ((ll)(abs(pn[i].x-pn[j].x)+abs(pn[i].y-pn[j].y)))*((ll)(pn[i].k+pn[j].k));
            id++;
        }
    }
    int m = id;
    id = 0;
    sort(edge,edge+m,cmp);
    ll cost = 0;
    for(i = 0;i<n;i++)
        fa[i] = i,cost += pn[i].c;
    for(i = 0;i<m;i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        ll w = edge[i].w;
        int fu = findfa(u),fv = findfa(v);
        if(fu == fv) continue;
        if(pn[fu].c >pn[fv].c) swap(u,v),swap(fu,fv);
        ll tmp = pn[fv].c-w;
        if(tmp>0)
        {
            ok[id++] = i;
            cost -= tmp;
            fa[fv] = fu;
        }
    }
    cout<<cost<<endl;
    cout<<n-id<<endl;
    bool bl = 1;
    for(i = 0;i<n;i++)
    {
        if(fa[i] == i)
        {
            if(bl) cout<<i+1,bl = 0;
            else cout<<" "<<i+1;
        }
    }
    cout<<endl;
    cout<<id<<endl;
    for(i = 0;i<id;i++)
    {
        int x = ok[i];
        cout<<edge[x].u+1<<" "<<edge[x].v+1<<endl;
    }
    return 0;


}
