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
int x[2007],y[2007];
int c[2007],d[2007];
int p[2007];

int Find(int X)
{
    return p[X]==X ? X : p[X]=Find(p[X]);
}

void Union(int X,int Y)
{
    p[Find(X)]=Find(Y);
}

vector<pair<int,pii> > v;
vector<pii> aans;

int32_t main()
{
    IOS
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) cin>>d[i];
    for (int i=0;i<=n;i++)
    {
        p[i]=i;
    }
    for (int i=1;i<=n;i++)
    {
        v.pb(mkp(c[i],mkp(0,i)));
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<i;j++)
    {
        v.pb(mkp((d[i]+d[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),mkp(i,j)));
    }
    sort(all(v));
    int ans=0;
    for (auto i:v)
    {
        if (Find(i.S.F)!=Find(i.S.S))
        {
            aans.pb(i.S);
            ans+=i.F;
            Union(i.S.F,i.S.S);
        }
    }
    cout<<ans<<endl;
    int t=0;
    vector<pii> tmp;
    for (pii i:aans)
    {
        if (i.F==0) t++,tmp.pb(i);
    }
    cout<<t<<endl;
    for (pii i:tmp) cout<<i.S<<' ';
    cout<<endl;
    cout<<n-t<<endl;
    for (pii i:aans)
    {
        if (i.F!=0) cout<<i.F<<' '<<i.S<<endl;
    }
}

