#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
   FAST/**/
   
   ll t;
   cin>>t;
   
   while(t--)
   {
       ll n;
       string s,t;
       cin>>n>>s>>t;
       
       bool pos = 0;
       unordered_map<char,ll> m1,m2;
       for(ll i=0;i<n;i++)
            m1[s[i]]++;
       for(ll j=0;j<n;j++)
            m2[t[j]]++;
       
       bool pos1 = 1;
       for(char c = 'a';c<='z';c++)
       {
           if((m1[c]+m2[c])%2!=0)
                pos1 = 0; 
       }
       
       if(s == t)
       {
           cout<<"Yes\n";
           continue;
       }
       //ll cnt = 0;
       ll p1 = -1, p2 = -1;
       for(ll i=0;i<n;i++)
       {
           if(s[i] == t[i])
                continue;
           if(p1 == -1)
                p1 = i;
           else if(p2 == -1)
                p2 = i;
       }
       
       swap(s[p1],t[p2]);
       if(s == t)
       {
           cout<<"Yes\n";
           continue;
       }
       else cout<<"No\n";        
   }
   
   return 0;
}