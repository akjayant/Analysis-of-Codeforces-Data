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

int main()
{
     ios;
     lld w;
     cin>>w;
     while(w--)
     {
         lld a,b,c;
         cin>>a>>b>>c;
         lld req=min(b,(c/2));
         b=b-req;
         c=c-req*2;
         lld req2=min(a,(b/2));
         lld ans=(req+req2)*3;
         cout<<ans<<endl;
     }
    return 0;
}
