/*   Abhijith  */
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define	endl '\n'
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
lld mo(lld x,lld n,lld m)
{
    lld result=1;
    while(n>0)
    {
        if(n%2==1)
            result=(result*x)%m;
        x=(x*x)%m;
        n=n/2;
    }
    return result;
}
int main()
{
     ios;
     lld n,k;
     cin>>n>>k;
     lld ans=mo(2,k,mod);
     ans=(ans-1+mod)%mod;
     ans=mo(ans,n,mod);
     cout<<ans<<endl;
    return 0;
}
