/*enjoy karo yaar*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     F            first
#define     S            second

const int inf=1e18,M=1e9+7;
const int N=1e6+5;

vector<int> v(N+1,1),p;

void sieve()
{
    v[0]=v[1]=0;
    for(int i=2;i*i<=N;++i)
    {
        if(v[i])
        {
            for(int j=i*i;j<=N;j+=i)
                v[j]=0;
        }
    }

    for(int i=2;i<=N;++i)
    {
        if(v[i])
            p.pb(i);
    }
}

void solve()
{
    sieve();

    int n;
    cin>>n;

    if(n==1)
    {
        cout<<1;
        return;
    }

    int sz=p.size();
    int z=n,cnt=0,need;
    for(int i=0;i<sz && p[i]<n;++i)
    {
        //cout<<p[i]<<"\n";

        if(z%p[i]==0)
        {
            ++cnt;

            if(cnt==1)
                need=p[i];

            if(cnt==2)
            {
                cout<<1;
                return;
            }

            while(z%p[i]==0)
                z/=p[i];
        }

        if(z==1)
            break;
    }

    if(z>1)
        ++cnt;

    if(cnt==1)
    {
        if(z==n)
            cout<<n;
        else
            cout<<need;
    }
    else
        cout<<1;
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

