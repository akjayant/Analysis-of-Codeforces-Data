#include<bits/stdc++.h>
#define maxn 100005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
#define pb push_back
using namespace std;


ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}

int n;
ll k;
ll a[maxn];

ll sum[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);

    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }

    /*ll sol=a[n]-a[1];
    for(ll br=1;2*br<=n;br++)
    {
        ll levo=br*a[br]-sum[br];
        ll desno=br*a[n-br+1]- (sum[n]-sum[n-br]);

        ll jos,dis;
        if(br==n-br+1)
        {
            jos=0;
            dis=0;
        }
        if(br+1==n-br+1)
        {
            jos=a[br+1]-a[br];
            dis=a[br+1]-a[br];
        }
        else
        {
            jos=(a[br+1]-a[br])+(a[n-br+1] - a[n-br]);
            dis=a[n-br+1]-a[br];
        }

        ll tre=levo+desno;
        if(tre>k)break;

        ll ost=k-tre;
        ll moze_jos_da_se_doda=min(ost/br,jos);

        dis-=moze_jos_da_se_doda;

        sol=min(sol,dis);
    }*/

    ll minn=k+1;
    for(ll i=1;i<=n;i++)
    {
        ll tre=(i*a[i]-sum[i])+ ((sum[n]-sum[i])-(n-i)*a[i]);
        minn=min(minn,tre);
    }

    if(minn<=k)
    {
        cout<<"0\n";
        return 0;
    }

    ll sol=a[n]-a[1];
    for(ll br=1;2*br<=n;br++)
    {
        ll tre=(br*a[br]-sum[br])+((sum[n]-sum[n-br])-br*a[n-br+1]);

        if(tre>k)continue;

        ll ost=k-tre;

        ll jos;
        ll dis;
        if(br+1==n-br+1)
        {
            jos=a[br+1]-a[br];
            dis=a[br+1]-a[br];
        }
        else
        {
            jos=a[br+1]-a[br] + a[n-br+1]-a[n-br];
            dis=a[n-br+1]-a[br];
        }

        ll moze_jos=min(ost/br,jos);
        dis=max(dis-moze_jos,0LL);
        sol=min(dis,sol);
    }

    cout<<sol<<endl;
    return 0;
}
