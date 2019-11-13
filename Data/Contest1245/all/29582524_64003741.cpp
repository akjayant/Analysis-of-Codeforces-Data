#include<bits/stdc++.h>
#define int long long
#define ld long double
#define endl '\n'
const int mod=1e9+7;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define si(a) a.size()
#define pii pair<int,int>
using namespace std;
#if !defined(ONLINE_JUDGE)
#include "debugging.h"
#endif

int32_t main() {
   std::ios::sync_with_stdio(false);cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
      int r,p,s,n;  
      cin>>n>>r>>p>>s;
      char a[n+1];
      for(int i=1;i<=n;i++)cin>>a[i];
      char ans[n+1];
      for(int i=0;i<=n;i++)ans[i]='0';
      vector<int> play[3];
      for(int i=1;i<=n;i++)
      {
         if(a[i]=='R')
         play[0].pb(i);
         else if(a[i]=='P')
         play[1].pb(i);
         else play[2].pb(i);
      }
      int t=min(r,(int)play[2].size())+min(p,(int)play[0].size())+min(s,(int)play[1].size());
      int req=n/2+n%2;
      if(t>=req)
      {
         cout<<"YES\n";
         vector<char>rest;
         for(int i=0;i<3;i++)
         {
            if(i==0)
            {
               while(p && play[i].size())
               {
                  p--;
                  ans[ play[i].back() ]='P';
                  play[i].pop_back();
               }
               for(int i=0;i<p;i++)rest.pb('P');
            }
            else if(i==1)
            {
               while(s && play[i].size())
               {
                  s--;
                  ans[ play[i].back() ]='S';
                  play[i].pop_back();
               }
               for(int i=0;i<s;i++)rest.pb('S');
            }
            else
            {
               while(r && play[i].size())
               {
                  r--;
                  ans[ play[i].back() ]='R';
                  play[i].pop_back();
               }
               for(int i=0;i<r;i++)rest.pb('R');
            }
         }
         for(int i=1;i<=n;i++)
         {
            if(ans[i]=='0')
            {
               cout<<rest.back();rest.pop_back();
            }
            else
            cout<<ans[i];
         }
      }
      else
      {
         cout<<"NO";
      }
      cout<<endl;
   }
   return 0;
}