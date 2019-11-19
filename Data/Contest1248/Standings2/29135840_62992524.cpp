#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;

int main()
{
   FAST/**/

   ll n,m;
   cin>>n>>m;
   
   ll fun[n+1][2][3];
   ll fun1[m+1][2][3];
   for(ll i=0;i<n+1;i++)
        for(ll j=0;j<2;j++)
            for(ll k=0;k<3;k++)
                fun[i][j][k] = 0;
   for(ll i=0;i<m+1;i++)
        for(ll j=0;j<2;j++)
            for(ll k=0;k<3;k++)
                fun1[i][j][k] = 0;                
   
   fun[0][0][0] = 1, fun[0][1][0] = 1;
   fun1[0][0][0] = 1, fun1[0][1][0] = 1;
   
   fun[1][0][1] = 1, fun[1][1][1] = 1;
   fun1[1][0][1] = 1, fun1[1][1][1] = 1;
   
   for(ll i=2;i<=n;i++)
   {
       for(ll j=0;j<2;j++)
       {
           for(ll k=1;k<3;k++)
           {
               if(k == 2)
                    fun[i][j][k]+=fun[i-1][j][k-1], fun[i][j][k]%=MOD;
               if(k == 1)
               {
                   fun[i][j][k]+=fun[i-1][1-j][1], fun[i][j][k]%=MOD;
                   if(i>2)
                        fun[i][j][k]+=fun[i-1][1-j][2], fun[i][j][k]%=MOD;
               }
           }
       }
   }
   
   for(ll i=2;i<=m;i++)
   {
       for(ll j=0;j<2;j++)
       {
           for(ll k=1;k<3;k++)
           {
               if(k == 2)
                    fun1[i][j][k]+=fun1[i-1][j][k-1], fun1[i][j][k]%=MOD;
               if(k == 1)
               {
                   fun1[i][j][k]+=fun1[i-1][1-j][1], fun1[i][j][k]%=MOD;
                   if(i>2)
                        fun1[i][j][k]+=fun1[i-1][1-j][2], fun1[i][j][k]%=MOD;
               }
           }
       }
   }
   
   ll ans = 0;
   for(ll i=0;i<2;i++)
   {
       for(ll j=1;j<3;j++)
       {
           ans+=fun[n][i][j]+fun1[m][i][j];
           ans%=MOD;
       }
   }
   
   ans-=2;
   ans%=MOD;
   if(ans<0)
        ans+=MOD;
   cout<<(ans);
   
   return 0;
}