#include<bits/stdc++.h>
#define maxn 2005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define plll pair<pll,pll>
#define INF 100000000000000000
#define node first
#define w second
using namespace std;


/*ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}*/

struct grad{
    ll x,y;
    ll k;
    ll c;
    int ind;
};

int n;
grad a[maxn];

bool cmp(grad levo,grad desno)
{
    return levo.c<desno.c;
}

ll sol=0;
bool bio[maxn];

vector<int>lit;
vector<int>stanice;
vector<pii>grane;

pll dis[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].c;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].k;
    }
    for(int i=1;i<=n;i++)
    {
        a[i].ind=i;
    }

    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)bio[i]=false;
    for(int i=1;i<=n;i++)
    {
        dis[i].w=INF;
        dis[i].node=-1;
    }

    while(lit.size()<n)
    {
        ll minn=INF;
        int prvi=-1,drugi=-1;

        for(int i=1;i<=n;i++)
        {
            if(!bio[i] && dis[i].w<minn)
            {
                prvi=i;
                drugi=dis[i].node;
                minn=dis[i].w;
            }
        }


        for(int i=1;i<=n;i++)
        {
            if(!bio[i])
            {
                if(a[i].c < minn)
                {
                    minn=a[i].c;
                    prvi=i;
                    drugi=-1;
                }
            }
        }


        bio[prvi]=true;
        lit.pb(prvi);
        sol+=minn;

        if(drugi==-1)
        {
            stanice.pb(prvi);
        }
        else
        {
            grane.pb({prvi,drugi});
        }


        for(int i=1;i<=n;i++)
        {
            if(!bio[i])
            {
                ll uk_k = a[i].k + a[prvi].k;
                ll rasss = abs(a[i].x-a[prvi].x) + abs(a[i].y - a[prvi].y);

                if(uk_k * rasss < dis[i].w)
                {
                    dis[i].w=uk_k * rasss;
                    dis[i].node=prvi;
                }
            }
        }
    }

    cout<<sol<<"\n";
    cout<<stanice.size()<<"\n";
    for(auto tre:stanice)cout<<a[tre].ind<<" ";cout<<"\n";
    cout<<grane.size()<<"\n";
    for(auto tre:grane)cout<<a[tre.first].ind<<" "<<a[tre.second].ind<<"\n";


    return 0;
}
