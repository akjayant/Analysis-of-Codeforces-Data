// by : 信冯哥
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5+5;
const int mod = (int)1e9+7;

typedef long double dl;
typedef long long ll;
//#define int ll

#define orz cout<<endl
#define debug cout<<"-------------------"<<endl
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define sync ios::sync_with_stdio(false)

int n,m,k,l,s,t,r,T;
int a[maxn][2];
ll c[maxn];
ll kk[maxn];
ll ans;
struct st
{
    int from,to;
    ll cost;
};
vector<st>edge;

bool operator < (const st &x, const st &y)
{
    return x.cost<y.cost;
}
int fa[maxn];

int find(int x)
{
    if(fa[x]==x)
        return x;
    else return fa[x]=find(fa[x]);
}
vector<st>oup;
vector<int>opt;
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i][0]>>a[i][1];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        cin>>kk[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
        edge.push_back({i,j,(kk[i]+kk[j])*(abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]))});
    }

    for(int i=1;i<=n;i++)
    {
        edge.push_back({n+1,i,c[i]});
    }
    sort(edge.begin(),edge.end());

    for(int i=1;i<=n+1;i++)
        fa[i]=i;
    for(auto &i:edge)
    {
        int x=find(i.from);
        int y=find(i.to);
        if(x!=y) {
            fa[x] = y;
            ans+=i.cost;
            if(i.from==n+1)
                opt.push_back(i.to);
            else if(i.to==n+1)
                opt.push_back(i.from);
            else
            {
                oup.push_back(i);
            }
        }
    }
    cout<<ans<<endl;
    cout<<opt.size()<<endl;
    for(int i:opt)
        cout<<i<<" ";
    cout<<endl;
    cout<<oup.size()<<endl;
    for(auto &i:oup)
        cout<<i.from<<" "<<i.to<<endl;
    return 0;
}

