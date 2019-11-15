#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<queue>
#define smallMaxi 1001
#define bigMaxi 5000005
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
ll n,q,a,b;
string s,t;
int main()
{
   cin >> q;
   while(q--)
   {
      cin >> n;
      cin >> s >> t;
      
     
      ll cnt = 0;
      

      ll freq[26];
      for(int i=0;i<26;i++)
      {
         freq[i]=0;
      }
      vector<ll> idx;
      for(int i=0;i<n;i++)
      {
         if(s[i] != t[i])
         {
            ll first = s[i]-'a';
            ll second = t[i]-'a';
            idx.PB(i);
            freq[first]++;
            freq[second]++;
         }
      }
      ll possible = true;

      for(int i=0;i<26;i++)
      {
         if(freq[i]&1)
         {
            possible = false;
            break;
         }
      }

      if(!possible)
      {
         cout<<"No"<<endl;
         continue;
      }

      cout<<"Yes"<<endl;
      vector<pair<ll, ll> > ans;
      for(int i=0;i<idx.size()-1;i++)
      {
         bool found = false;
         for(int j=i+1;j<idx.size();j++)
         {
            if(s[idx[i]]==s[idx[j]])
            {
               found = true;
               swap(s[idx[j]],t[idx[i]]);
               ans.PB(MP(idx[j]+1,idx[i]+1));
               break;
            }
         }
         if(!found)
         {
            for(int j=i+1;j<idx.size();j++)
            {
               if(s[idx[i]]==t[idx[j]])
               {
                  found = true;
                  swap(s[idx[j]],t[idx[j]]);
                  ans.PB(MP(idx[j]+1,idx[j]+1));
                  swap(s[idx[j]],t[idx[i]]);
                  ans.PB(MP(idx[j]+1,idx[i]+1));
                  break;
               }
            }
         }
      }
      cout<<ans.size()<<endl;
      for(int i=0;i<ans.size();i++)
      {
         cout<<ans[i].first<<" "<<ans[i].second<<endl;
      }
      
   }
   return 0;
}