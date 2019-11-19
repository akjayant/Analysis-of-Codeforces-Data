/*

Nasha rozpovid pro yizhachka
Pro malenkogo necluhnanogo,

Yak spitkala malogo bida
Vzhe ne zhvavogo ne rumyanogo.

V temnim lisi bagato prygod
Ptahy, ravlyky, ckunsy, oleni,

Ta chomus potyagnulo yogo
Na dorizhenku acphaltovanu.


YYIIZZHHAACCHHOOKK!!
Pidnimus, pidberys!

YYIIZZHHAACCHHOOKK!!
Razom z namy posmihnys!

YYIIZZHHAACCHHOOKK!!
Navkrugy, ozernys!

YYIIZZHHAACCHHOOKK!!
YYIIZZHHAACCHHOOKK!!

*/

#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio();cin.tie();cout.tie();
#define ops cout<<"ops"<<endl;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pllll;
typedef string str;
typedef char cr;

const ll DIM=2e3+7;
const ll DIMM=4005007;
const ll INF=1e18+7;
const ll X=20;
const ll MODULO=1000000007;

ll n,n1;
ll x[DIM],y[DIM],k[DIM],b[DIM];
ll val,res;
vector<ll> e;
vector<pllll> ed;
struct z
{
    ll v1,v2,w;
} a[DIMM];

ll dist(ll v1,ll v2)
{
    return (k[v1]+k[v2])*(abs(x[v1]-x[v2])+abs(y[v1]-y[v2]));
}

bool cmp(z p1,z p2)
{
    return p1.w<p2.w;
}

ll fb(ll v)
{
    if(b[v]!=v)b[v]=fb(b[v]);
    return b[v];
}

bool join(ll v1,ll v2)
{
    ll vv1=fb(v1);
    ll vv2=fb(v2);
    if(vv1==vv2)return false;
    if(rand()%2==1)b[vv1]=vv2;
    else b[vv2]=vv1;
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    fast;
    //ll x1,y1,x2,y2;

    cin>>n1;
    for(int i=1; i<=n1; i++)cin>>x[i]>>y[i];

    for(int i=1; i<=n1; i++)
    {
        cin>>val;
        n++;
        a[n]= {i,(n1+1),val};
    }
    for(int i=1; i<=n1; i++)cin>>k[i];

    for(int i=1; i<=n1; i++)
    {
        for(int j=1; j<=n1; j++)
        {
            n++;
            a[n]= {i,j,dist(i,j)};
        }
    }

    for(int i=1; i<=(n1+1); i++)b[i]=i;

    sort(a+1,a+1+n,cmp);

    for(int i=1; i<=n; i++)
    {
        if(join(a[i].v1,a[i].v2))
        {
            res+=a[i].w;
            if(a[i].v2==(n1+1))e.push_back(a[i].v1);
            else ed.push_back({a[i].v1,a[i].v2});
        }
    }

    cout<<res<<endl;

    cout<<e.size()<<endl;
    for(auto p:e)cout<<p<<' ';
    cout<<endl;

    cout<<ed.size()<<endl;
    for(auto p:ed)cout<<p.first<<' '<<p.second<<endl;
    return 0;
}
