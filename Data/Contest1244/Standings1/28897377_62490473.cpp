#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>c[100010];
ll res[100010];
ll vis[100010];
ll ma;
int vv[100010];
ll a[4][100010];
//void dfs(ll x,ll fa)
//{
//    for(auto it:c[x])
//    {
//        if(it==fa)continue;
//        vis[it]=6-vis[x]-vis[fa];
//        ma+=a[vis[it]][it];
//        dfs(it,x);
//    }
//}
ll zz[100010];
//bool cmp(int a,int b)
//{
//    return zz[a]<zz[b];
//}
int main()
{
    ll n,i,j,u,v,k;
    scanf("%lld",&n);
    for(i=1;i<=3;i++)
        for(j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);
    for(i=1;i<n;i++)
    {
        scanf("%lld%lld",&u,&v);
        c[u].push_back(v);
        c[v].push_back(u);
    }
    ll st;
    for(i=1;i<=n;i++)
    {
        if(c[i].size()==1)st=i;
        if(c[i].size()>2)
        {
            printf("-1\n");
            return 0;
        }
    }
    ll se=c[st][0];
    ll ans=1e18;
    ll sum=0;
    zz[++sum]=st;
    zz[++sum]=se;
//    cout<<st<<" "<<se<<endl;
    ll la=se;
    vv[st]=vv[se]=1;
    while(c[la].size()>1)
    {
//        cout<<1<<endl;
//        cout<<la<<" "<<c[la][0]<<" "<<c[la][1]<<endl;
        v=c[la][0];
        if(vv[v]==0)
        {
            vv[v]=1;
            zz[++sum]=v;
            la=v;
            continue;
        }
        v=c[la][1];
        vv[v]=1;
        zz[++sum]=v;
        la=v;
        continue;
    }
//    for(i=1;i<=sum;i++)cout<<zz[i]<<" ";cout<<endl;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(i==j)continue;
            vis[1]=i;
            vis[2]=j;
            ma=a[i][zz[1]]+a[j][zz[2]];
            for(k=3;k<=sum;k++)
            {
                vis[k]=6-vis[k-1]-vis[k-2];
                ma+=a[vis[k]][zz[k]];
            }
            if(ma<ans)
            {
                for(k=1;k<=n;k++)res[zz[k]]=vis[k];
                ans=ma;
            }
        }
    }
//    sort(res+1,res+1+n,cmp);
    printf("%lld\n",ans);
    for(i=1;i<=n;i++)printf("%lld ",res[i]);
}
