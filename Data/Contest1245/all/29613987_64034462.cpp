#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll n,res=LLONG_MAX, c[1000010], k[1000010], label[1000010], P[1000010];
pair<ll,ll> a[1000010];
vector<ll> v1;
vector<pair<ll,ll> > v2;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
int main()
{
  //  freopen("h.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    read(n);
    for(int i=1;i<=n;i++)
    {
        read(a[i].fi); read(a[i].se);
    }
    ll dd=LLONG_MAX,s;
    for(int i=1;i<=n;i++)
    {
        read(c[i]);
        if(c[i]<dd)
        {
            dd=c[i];
            s=i;
        }
    }

    for(int i=1;i<=n;i++)
        read(k[i]);
    while(1)
      {
        ll C = 0;
        priority_queue <pair<ll,pair<ll,ll> >, vector <pair<ll,pair<ll,ll> > >, greater <pair<ll,pair<ll,ll> > > > Q;
        for(int i=1;i<=n;i++)
            label[i]=LLONG_MAX;
        Q.push({c[s],{s,1}});
        label[s]=c[s];
        v1.clear();
        v2.clear();
        while (Q.size())
        {
            ll u = Q.top().se.fi, du = Q.top().fi, tt = Q.top().se.se;
            Q.pop();
            if (label[u]!=du)
                continue;
            C+=label[u];
            label[u]=0;
            if(tt==1)
                v1.push_back(u);
            else
                v2.push_back({u, P[u]});
            for(int v=1;v<=n;v++)
                if(label[v]>c[v])
                {
                    label[v]=c[v];
                    Q.push({label[v],{v, 1}});
                }
            for(int v=1;v<=n;v++)
                if(label[v]>(k[u]+k[v])*(abs(a[u].fi-a[v].fi)+abs(a[u].se-a[v].se)))
                {
                    label[v]=(k[u]+k[v])*(abs(a[u].fi-a[v].fi)+abs(a[u].se-a[v].se));
                    Q.push({label[v],{v, 2}});
                    P[v] = u;
                }
        }
        res=min(res,C);
        write(res);
        putchar('\n');
        write(v1.size()); putchar('\n');
        for(int j=0;j<v1.size();j++)
        {
            write(v1[j]); putchar(' ');
        }
        putchar('\n');
        write(v2.size()); putchar('\n');
        for(int j=0;j<v2.size();j++)
        {
            write(v2[j].fi);
            putchar(' ');
            write(v2[j].se);
            putchar('\n');
        }
        putchar('\n');
        return 0;
    }
    write(res);
}
