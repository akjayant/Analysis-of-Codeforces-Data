/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define pf          printf
#define sf          scanf
#define ff          first
#define ss          second
#define clr         clear()
#define sz          size()
#define pb          push_back
#define mk          make_pair
#define pi          acos(-1)
#define inf         100000000000000000
#define mod         1000000009
#define ull         unsigned long long int
#define f(i,k,n)    for(ll i=k;i<n;i++)
#define fr(i,n,k)   for(i=n;i>=k;i--)
#define ent(a)      scanf("%lld",&a)
#define ent2(a,b)   scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a)      memset(a,0,sizeof(a))
#define vec(v,s)    vector<ll>v[s]
#define arr(a,s)    ll a[s];
//#define check(n,pos) (n&(1<<pos))
//#define set(n,pos)  (n|(1<<pos))
//knight and king//
int dr[]= {2, 2, -2, -2, 1, -1, 1, -1};
int dc[]= {1,-1,  1, -1, 2,  2,-2, -2};
int dr1[]= {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dc1[]= {-1,0, 1,-1, 0, 1, -1, 0,   1};
int dr2[]= {0, 0, 1, -1};
int dc2[]= {1,-1, 0,  0};
////////////////////////////
#define ma 1000006
using namespace std;


ll a[ma],b[ma];
ll n;
ll low(ll x)
{
    ll lo=1,hi=n,mid,ans=0;

    while(lo<=hi)
    {
        ll mid=(lo+hi)>>1;
        if(a[mid]<x)
        {
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}

ll hig(ll x)
{
    ll lo=1,hi=n,mid,ans=n+1;
    while(lo<=hi)
    {
        ll mid=(lo+hi)>>1;
        if(a[mid]>x)
        {
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}

int main()
{
    ll k,i,j;
    while(cin>>n>>k)
    {
        for(i=1;i<=n;i++)cin>>a[i];



        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
        {
            b[i]=a[i]+b[i-1];
        }
        b[n+1]=b[n];
        ll max1=inf;

        for(i=1;i<=n;i++)
        {
            ll p=low(a[i]);
            ll k1=a[i]*p-b[p];
            if(k1>k)continue;
            ll baki=k-k1;
            ll lo=0,hi=1000000000,mid,ans;

            while(lo<=hi)
            {
                ll mid=(lo+hi)>>1;
                ll p=hig(a[i]+mid);
                if(p==n+1)
                {
                    hi=mid-1;
                    continue;
                }
                ll k2=b[n]-b[p-1]-((a[i]+mid)*(n-p+1));


                if(k2<=baki)
                {
                    ans=mid;
                    hi=mid-1;
                }
                else lo=mid+1;
            }
           // cout<<ans<<endl;
            max1=min(max1,ans);

        }



        for(i=n;i>=1;i--)
        {
            ll p=hig(a[i]);
            ll k1=0;
            if(p!=n+1)
             k1=b[n]-b[p-1]-a[i]*(n-p+1);
             if(k1>k)continue;
            ll baki=k-k1;

             ll lo=0,hi=a[i],mid,ans;

             while(lo<=hi)
             {
                 mid=(lo+hi)>>1;
                 ll p=low(a[i]-mid);
                 ll k2=p*(a[i]-mid)-b[p];
                 if(k2<=baki)
                 {
                     ans=mid;
                     hi=mid-1;
                 }
                 else lo=mid+1;
             }
             max1=min(max1,ans);

        }

        cout<<max1<<endl;



    }
    return 0;
}
