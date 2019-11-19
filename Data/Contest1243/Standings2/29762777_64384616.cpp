#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll MAXN = 2e3 + 10;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mo = 1e9+7;

string s,t;
int main()
{
    int q = 1;
    while(q--)
    {
        s = "C" ;
        ll n;
        scanf("%lld",&n);
        ll f1 = 0,f2 = 0;
        ll nn = n;
        for(ll i=2; i*i<=n; i++)
        {
            if(nn % i == 0)
            {
                f2 = i;
                f1 ++;
                while(nn % i == 0)
                    nn/=i;
            }
        }
        if(f1 == 1 && nn != 1)
            f1 ++;
        if(f1 == 0)
            printf("%lld",n);
        else if(f1 == 1)
            printf("%lld",f2);
        else
            printf("1");
    }
    return 0;
}
