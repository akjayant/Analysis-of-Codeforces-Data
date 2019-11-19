#include<bits/stdc++.h>

#define file ""
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 2003

using namespace std;
int n, root[maxn], x[maxn], y[maxn], k[maxn], cnt;
long long ans;
vector <pair<int,int> > e;
vector <int> ve;
struct data
{
    long long w;
    int u, v;
}a[maxn*maxn];
bool cmp(data a, data b)
{
    return a.w < b.w;
}
int get(int u){return root[u]?root[u]=get(root[u]):u;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    f1 (i, n) cin >> x[i] >> y[i];
    f1 (i, n)
    {
        int x;
        cin >> x;
        a[++cnt]={x, n+1, i};
    }
    f1 (i, n) cin >> k[i];
    f1 (i, n) f1 (j, i-1)
    {
        long long val = 1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
        a[++cnt]={val, i, j};
    }
    sort (a+1, a+cnt+1, cmp);
    int dem=0;
    for (int i=1; i<=cnt; i++)
    {
        long long w=a[i].w;
        int u=a[i].u, v=a[i].v;
        int x=get(u), y=get(v);
        if (x!=y)
        {
            root[x]=y;
            if (v<u) swap(u, v);
            if (v==n+1) ve.push_back(u);
            else e.push_back({u,v});
            ans += w;
            dem++;
        }
        if (dem==n) break;
    }
    cout << ans; el;
    cout << ve.size(); el;
    for (auto x:ve) cout << x << ' ';
    cout << '\n';
    cout << e.size();
    cout << '\n';
    for (auto p:e) cout << p.first << ' ' << p.second << '\n';
    return 0;
}
