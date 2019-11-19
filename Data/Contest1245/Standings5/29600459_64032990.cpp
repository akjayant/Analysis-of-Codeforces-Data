#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<long long, long long> ii;
typedef pair<long long, ii> iii;
vector<iii> edge;
long long n, m;
long long par[230997],x[2000000],y[2000000],c[2000000],k[2000000];
vector<long long > res;
vector<ii>kq;
long long anc(long long p){ if (par[p]==p) return p; else return par[p]=anc(par[p]); }
void join(long long p, long long q){ par[anc(p)]=anc(q); }
void build()
{
    for(long long i=1;i<=n;i++)
    edge.push_back(iii(c[i],ii(0,i)));
    for(long long i=1;i<n;i++)
        for(long long j=i+1;j<=n;j++)
            edge.push_back(iii(((k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))),ii(i,j)));
}
void solve()
{
    long long r=0;
    for (long long i=0; i<=n; i++) par[i]=i;
     sort(edge.begin(), edge.end());
    vector<iii>::iterator it;
    for (it=edge.begin(); it!=edge.end(); it++)
    {
        if (anc(it->Y.X) != anc(it->Y.Y))
        {
            long bx=it->Y.X,by=it->Y.Y;
            if(bx==0)
            res.push_back(by);
            else kq.push_back(ii(bx,by));
            join(it->Y.X, it->Y.Y);
            r += it->X;
        }
    }
    cout<<r<<"\n";
    cout<<(long)res.size()<<"\n";
    for(long long i=0;i<(long)res.size();i++)
        cout<<res[i]<<" ";
    cout<<"\n";
    cout<<(long)kq.size()<<"\n";
    for(long long i=0;i<(long)kq.size();i++)
        cout<<kq[i].X<<" "<<kq[i].Y<<"\n";
}
int main()
{
     ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(long long i=1;i<=n;i++)
        cin>>c[i];
    for(long long i=1;i<=n;i++)
        cin>>k[i];
    build();
    solve();
}
