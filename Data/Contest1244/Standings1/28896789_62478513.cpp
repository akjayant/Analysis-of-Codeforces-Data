#include<bits/stdc++.h>
#define maxn 200005
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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n,p,w,d;
    cin>>n>>p>>w>>d;

    ll gcd=__gcd(w,d);

    if(p%gcd!=0)
    {
        cout<<"-1\n";
        return 0;
    }

    w/=gcd;
    d/=gcd;
    p/=gcd;

    ll inv_d=0;
    for(ll i=0;i<w;i++)
    {
        if((i*d)%w==1)
        {
            inv_d=i;
            break;
        }
    }

    ll inv_w=0;
    for(ll i=0;i<d;i++)
    {
        if((i*w)%d==1)
        {
            inv_w=i;
            break;
        }
    }


    ll r1=(inv_d*(p%w))%w;
    ll r2=(inv_w*(p%d))%d;

    p-=r1*d;
    p-=r2*w;

    if(p<0)
    {
        cout<<"-1\n";
        return 0;
    }


    ll sum=p/(w*d);

    ll minn=r1+r2+d*sum;

    if(minn<=n)
    {
        cout<<d*sum+r2<<" "<<r1<<" "<<n-minn<<"\n";
    }
    else
    {
        cout<<"-1\n";
    }

    return 0;
}
