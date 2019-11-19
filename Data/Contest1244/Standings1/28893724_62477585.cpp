#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define int ll

#ifdef HNO2
#define IOS
#else
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#endif // HNO2

int n;
int a[maxn][4];
int indeg[maxn],x,y;
int xx[maxn];
vector<int> v;
vector<int> G[maxn];
int aa[3]={1,2,3};

void dfs(int now,int p)
{
    v.pb(now);
    for (int i:G[now])
    {
        if (i!=p) dfs(i,now);
    }
}

int32_t main()
{
    IOS
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i][1];
    for (int i=1;i<=n;i++) cin>>a[i][2];
    for (int i=1;i<=n;i++) cin>>a[i][3];
    for (int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
        indeg[x]++;
        indeg[y]++;
    }
    for (int i=1;i<=n;i++)
    {
        if (indeg[i]>=3) return cout<<-1<<endl,0;
    }
    int sta;
    for (int i=1;i<=n;i++)
        if (indeg[i]==1)
    {
        sta=i;
        break;
    }
    dfs(sta,-1);
    int ans=inff;
    int a1,a2,a3;
    do
    {
        int now=0;
        for (int i=1;i<=n;i++)
            now+=a[v[i-1]][aa[i%3]];
        if (now<ans)
        {
            ans=now;
            a1=aa[1],a2=aa[2],a3=aa[0];
        }
    }while (next_permutation(aa,aa+3));
    cout<<ans<<endl;
    for (int i=1;i<=n;i++)
        if (i%3==1) xx[v[i-1]]=a1;
        else if (i%3==2) xx[v[i-1]]=a2;
        else xx[v[i-1]]=a3;
    for (int i=1;i<=n;i++) cout<<xx[i]<<' ';
}

