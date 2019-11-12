#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
lld fastpower(lld x, unsigned lld y, lld p)
{
    lld res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
int main()
{
     ios;
     lld TESTS,a,b,c,n,p,w,d,m,x,i,y,z;
     TESTS=1;
     while(TESTS--)
     {
         cin>>n>>m;
         lld use=(fastpower(2,m,mod)-1+mod)%mod;
         lld ans=fastpower(use,n,mod);
         cout<<ans;
     }
    return 0;
}
