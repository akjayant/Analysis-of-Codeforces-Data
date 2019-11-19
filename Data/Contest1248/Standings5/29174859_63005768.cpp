#include <iostream>

#include <cstdio>

using namespace std;

typedef long long ll;

#define wfor(i,j,k) for(i=j;i<k;++i)

#define mfor(i,j,k) for(i=j;i>=k;--i)

// void read(ll &x) {

// 	char ch = getchar(); x = 0;

// 	for (; ch < '0' || ch > '9'; ch = getchar());

// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';

// }

const ll mod=1e9+7;

ll ksm(ll a,ll b)

{

    ll ans=1;

    while(b)

    {

        if(b&1)

            ans=ans*a%mod;

        a=a*a%mod;

        b>>=1;

    }

    return ans;

}

const int maxn=1e5+5;

ll num[maxn];

int main()

{

    std::ios::sync_with_stdio(false);

    #ifdef test

    freopen("F:\\Desktop\\question\\in.txt","r",stdin);

    #endif

    #ifdef ubuntu

    freopen("/home/time/debug/debug/in","r",stdin);

    freopen("/home/time/debug/debug/out","w",stdout);

    #endif

    ll n,m;

    cin>>n>>m;

    if(n==1&&m==1)

        cout<<2<<endl;

    else

    {

        num[1]=2;

        num[2]=4;

        int i;

        wfor(i,3,maxn)

        {

            num[i]=num[i-1]+num[i-2];

            num[i]%=mod;

        }

        cout<<(num[n]+num[m]-2)%mod<<endl;

    }

    return 0;

}