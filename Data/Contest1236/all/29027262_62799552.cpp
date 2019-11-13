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
     lld n;
     cin>>n;
     vector<vector<lld> > ans(n);
     lld req=(n+1)/2;
     rep(i,1,n*n)
     {
         if((i-1)/n<req)
         {
             ans[(i-1)%n].pb(i);
         }
         else
         {
             ans[(n-1-(i-1)%n)].pb(i);
         }
     }
     rep(i,0,n-1)
     {
         rep(j,0,n-1)
            cout<<ans[i][j]<<" ";
         cout<<endl;
     }
    return 0;
}
