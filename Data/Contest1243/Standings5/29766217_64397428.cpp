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
      vector<ll> index;
      for(int i=0;i<n;i++)
      {
         if(s[i]!=t[i])
         {
            index.PB(i);
            cnt++;
         }
      }

      if(cnt==2)
      {
         swap(s[index[0]],t[index[0]]);
         if(s==t)
         {
            cout<<"Yes"<<endl;
            continue;
         }
         swap(s[index[0]],t[index[0]]);

         swap(s[index[0]],t[index[1]]);
         if(s==t)
         {
            cout<<"Yes"<<endl;
            continue;
         }
         swap(s[index[0]],t[index[1]]);

         swap(s[index[1]],t[index[0]]);
         if(s==t)
         {
            cout<<"Yes"<<endl;
            continue;
         }
         swap(s[index[1]],t[index[0]]);

         swap(s[index[1]],t[index[1]]);
         if(s==t)
         {
            cout<<"Yes"<<endl;
            continue;
         }
         swap(s[index[1]],t[index[1]]);
         cout<<"No"<<endl;
         
      }
      else
      {
         cout<<"No"<<endl;
      }
   }
   return 0;
}