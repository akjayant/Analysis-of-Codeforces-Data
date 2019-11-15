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
       
       if(pos1 == 0)
       {
           cout<<"No\n";
           continue;
       }
       
       cout<<"Yes"<<"\n";
       vector<pair<ll,ll>> hold;
       for(ll i=0;i<n;i++)
       {
           if(s[i] == t[i])
                continue;
           
           if(m1[s[i]]>m2[s[i]])
           {
               ll p1;
               for(ll j=i+1;j<n;j++)
                    if(s[j] == s[i])
                        p1 = j;
               
               m1[s[i]]--,m1[t[i]]++;
               m2[s[i]]++,m2[t[i]]--;
               swap(s[p1],t[i]);
               hold.pb(mp(p1+1,i+1));
           }
           
           else if(m2[t[i]]>m1[t[i]])
           {
               ll p1;
               for(ll j=i+1;j<n;j++)
                    if(t[j] == t[i])
                        p1 = j;
               
               m2[t[i]]--,m2[s[i]]++;
               m1[t[i]]++,m1[s[i]]--;
               swap(t[p1],s[i]);
               hold.pb(mp(i+1,p1+1));
           }
           
           else
           {
               ll p1;
               for(ll j=i+1;j<n;j++)
               {
                   if(t[j] == s[i])
                   {
                       p1 = j;
                       break;
                   }
               }
               
               hold.pb(mp(n,p1+1));
               hold.pb(mp(n,i+1));
               
               m1[s[n-1]]--,m1[t[p1]]++;
               m2[s[n-1]]++,m2[t[p1]]--;
               swap(s[n-1],t[p1]);
               m1[s[n-1]]--,m1[t[i]]++;
               m2[s[n-1]]++,m2[t[i]]--;
               swap(s[n-1],t[i]);
           }
       }
       
       cout<<hold.size()<<"\n";
       for(ll i=0;i<hold.size();i++)
            cout<<hold[i].first<<" "<<hold[i].second<<"\n";
       
       
   }
   
   return 0;
}