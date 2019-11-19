#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
int n,p[4002005],rk[4002005],dem,res,w[2005],k[2005],x[2005],y[2005];
pair<int,pair<int,int>> a[4002005];
vector <pair<int,int> > ans;
vector <pair<int,int> > ans1;
vector <int> ans2;
int FIND(int u)
{
    int v=p[u];
    while(v!=u)
    {
        u=v;
        v=p[u];
    }
    return u;
}
void Union(int u,int v)
{
    int x=FIND(u);
    int y=FIND(v);
    if(x==y)
        return;
    else
    {
        if(rk[x]>rk[y])
            p[y]=x;
        if(rk[x]<rk[y])
            p[x]=y;
        if(rk[x]==rk[y])
        {
            p[y]=x;
            rk[x]++;
            return ;
        }
    }
}
 main()
{
    //freopen("test.inp","r",stdin);
    //freopen(".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>x[i]>>y[i];
    int cs=0;
    for(int i=1; i<=n; i++)
        cin>>w[i];
    for(int i=1; i<=n; i++)
        cin>>k[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            if(i!=j)
            {
                cs++;
                a[cs].x=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
                a[cs].y.x=i;
                a[cs].y.y=j;
            }
        }
    for(int i=1; i<=n; i++)
    {
        cs++;
        a[cs].x=w[i];
        a[cs].y.x=n+1;
        a[cs].y.y=i;
    }
    sort(a+1,a+1+cs);
    for(int i=1; i<=n; i++)
        p[i]=i;
    for(int i=1; i<=n*n+n; i++)

        if(FIND(a[i].y.x)!=FIND(a[i].y.y))
        {
            Union(a[i].y.x,a[i].y.y);
            ans.push_back({a[i].y.x,a[i].y.y});
            res+=a[i].x;
        }
        cout<<res<<endl;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i].x==n+1)
           ans2.push_back(ans[i].y);
        else ans1.push_back({ans[i].x,ans[i].y});
    }
    cout<<ans2.size()<<endl;
    sort(ans2.begin(),ans2.end());
    for(int i=0;i<ans2.size();i++)
        cout<<ans2[i]<<" ";
    cout<<endl;
    cout<<ans1.size()<<endl;
    for(int i=0;i<ans1.size();i++)
        cout<<ans1[i].x<<" "<<ans1[i].y<<endl;





}
