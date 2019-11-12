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
int main()
{
     ios;
     lld TESTS,a,b,c,n,p,w,d,m,x,i,y,z;
     cin>>TESTS;
     while(TESTS--)
     {
         cin>>a>>b>>c;
         lld ans=0;
         while (b>=1&&c>=2){
            ans+=3;
            b--;
            c-=2;
         }
         //cout<<a<<" "<<b<"\n";
         while (a>=1&&b>=2){
            ans+=3;
            a--;
            b-=2;
         }
         cout<<ans<<"\n";
     }
    return 0;
}
