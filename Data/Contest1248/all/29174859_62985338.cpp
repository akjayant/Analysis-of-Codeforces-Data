#include <iostream>

#include <algorithm> 

#include <vector> 

#include <cstdio>

using namespace std;

typedef long long ll;

#define wfor(i,j,k) for(i=j;i<k;++i)

#define mfor(i,j,k) for(i=j;i>=k;--i)

// void read(int &x) {

// 	char ch = getchar(); x = 0;

// 	for (; ch < '0' || ch > '9'; ch = getchar());

// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';

// }

const int maxn=1e5+5;

int num[maxn];

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

    int t;

    cin>>t;

    while(t--)

    {

        int n;

        cin>>n;

        int i;

        int odd=0;

        int even=0;

        wfor(i,0,n)

        {

            cin>>num[i];

            if(num[i]%2==0)

                even++;

            else

                odd++;

        }

        int m;

        cin>>m;

        ll ans=0;

        wfor(i,0,m)

        {

            int t;

            cin>>t;

            if(t%2!=0)

                ans+=odd;

            else

                ans+=even;

        }

        cout<<ans<<endl;

    }

    return 0;

}