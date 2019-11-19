#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n;
int f[2020], x[2020],y[2020],c[2020],k[2020];
struct node
{
    int u,v;
    ll yen;
    bool operator<(const node b)const
    {
        return yen>b.yen;
    }
};
priority_queue<node> pq;
queue<node> p,q;
inline int ab(int x)
{
    return x<0?-x:x;
}
int getfather(int x)
{
    if(f[x]!=x)
        f[x]=getfather(f[x]);
    return f[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int i,j;
    cin>>n;
    int rt=n+1,cnt=1;
    for(i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(i=1;i<=n;i++)
        cin>>c[i],pq.push({i,n+1,c[i]}),f[i]=i;
    f[i]=i;
    for(i=1;i<=n;i++)
        cin>>k[i];
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            pq.push({i,j,1LL*(k[i]+k[j])*(ab(x[i]-x[j])+ab(y[i]-y[j]))});
    ll ans=0;
    while(!pq.empty())
    {
        node tmp=pq.top();
        pq.pop();
        int fu=getfather(tmp.u),fv=getfather(tmp.v);
        if(fu!=fv)
        {
            f[fu]=fv;
            ans+=tmp.yen;
            if(tmp.v==n+1)
                p.push(tmp);
            else
                q.push(tmp);
        }
    }
    cout<<ans<<endl;
    cout<<p.size()<<endl;
    while(!p.empty())
    {
        node tmp=p.front();
        p.pop();
        cout<<tmp.u<<' ';
    }
    cout<<endl<<q.size()<<endl;
    while(!q.empty())
    {
        node tmp=q.front();
        q.pop();
        cout<<tmp.u<<' '<<tmp.v<<endl;
    }
    return 0;
}
