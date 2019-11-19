/// ANTI_LIGHT

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define f first
#define s second
typedef pair<int,int> pii;
typedef pair<int,pii> pos;

const int maxn=2e3+100;
int x[maxn];
int y[maxn];
int k[maxn];
vector<pos>a;
vector<int>pw;
vector<pii>ed;
int num[maxn];
vector<int>ml[maxn];

void _merge(int u,int v)
{
    if(ml[u].size()<ml[v].size())
        swap(u,v);
    for(int i=0;i<ml[v].size();i++)
    {
        int tx=ml[v][i];
        num[tx]=u;
        ml[u].push_back(tx);
    }
}

main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(pos(temp,pii(0,i)));
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        num[i]=i;
        ml[i].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int wx=(max(x[i],x[j])-min(x[i],x[j]));
            int wy=(max(y[i],y[j])-min(y[i],y[j]));
            int weig=(wx+wy)*(k[i]+k[j]);
            a.push_back(pos(weig,pii(i,j)));
        }
    }

    ml[0].push_back(0);
    int ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {
        int w=a[i].f;
        int u=a[i].s.f;
        int v=a[i].s.s;

        if(num[u]==num[v])
            continue;

        ans+=w;

        if(u==0)
            pw.push_back(v);
        else
            ed.push_back(pii(u,v));
        _merge(num[u],num[v]);
    }

    cout<<ans<<endl;
    cout<<pw.size()<<endl;
    for(int i=0;i<pw.size();i++)
        cout<<pw[i]<<" ";
    cout<<endl;
    cout<<ed.size()<<endl;
    for(int i=0;i<ed.size();i++)
        cout<<ed[i].f<<" "<<ed[i].s<<endl;
    return 0;
}
