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
   
   ll fib[100005];
   fib[0] = 0;
   fib[1] = 1;
   fib[2] = 2;
   for(ll i=3;i<100005;i++)
        fib[i] = fib[i-1] + fib[i-2], fib[i]%=MOD;
    
   string s;
   cin>>s;
   
   ll cnt = 0, curr = 'a';
   ll ans = 1;
   for(ll i=0;i<s.length();i++)
   {
       if(s[i]!=curr)
       {
           if(curr == 'm' || curr == 'w')
           {
               if(cnt<2)
               {
                   cout<<0;
                   return 0;
               }
           }
           if(curr == 'u'||curr == 'n')
           {
               ans*=fib[cnt], ans%=MOD;
           }
           curr = s[i];
           cnt = 1;
       }
       
       else cnt++;
   }
   if(curr == 'u'||curr == 'n')
                ans*=fib[cnt], ans%=MOD;
   
   if(curr == 'm' || curr == 'w')
           {
               if(cnt<2)
               {
                   cout<<0;
                   return 0;
               }
           }
   
   cout<<ans;                
   
   
   return 0;
}