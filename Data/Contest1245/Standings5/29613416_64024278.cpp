#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int fa[110000];
struct node
{
    int from,to;ll len;
}s[2000*4000];
int getfa(int x)
{
    if(fa[x]==-1)return x;
    return fa[x]=getfa(fa[x]);
}
void un(int x,int y)
{
    x=getfa(x),y=getfa(y);
    if(x==y)return;
    fa[x]=y;
}
bool cmp(node x,node y){return x.len<y.len;}
int aa[2010],X[2010],Y[2020];
ll ass(ll x){return x>0?x:-x;}
vector<int>v1;
vector<pair<int,int> >v2;
main()
{
    //cout<<sizeof(s)/1048576;
    int n,i,j,k,x,y,z,m=1;ll ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&Y[i]);
    for(i=0;i<=n;i++)fa[i]=-1;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&s[m].len);
        s[m].from=0,s[m++].to=i;
    }
    for(i=1;i<=n;i++)scanf("%d",&aa[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            //scanf("%d",&s[m].len);
            s[m].len=1ll*(aa[i]+aa[j])*(ass(X[i]-X[j])+ass(Y[i]-Y[j]));
            if(i>=j)continue;
            s[m].from=i,s[m++].to=j;
        }
    }
    m--;
    sort(s+1,s+m+1,cmp);
    for(i=1;i<=m;i++)
    {
        x=s[i].from,y=s[i].to;
        ll z=s[i].len;
        if(getfa(x)==getfa(y))continue;
        un(x,y);
        if(x>y)swap(x,y);
        if(x==0)v1.push_back(y);
        else v2.push_back(make_pair(x,y));
        ans+=z;
    }
    printf("%I64d\n",ans);
    printf("%d\n",v1.size());
    for(int i=0;i<v1.size();i++)printf("%d ",v1[i]);
    cout<<endl;
    printf("%d\n",v2.size());
    for(int i=0;i<v2.size();i++)printf("%d %d\n",v2[i].first,v2[i].second);
}
