#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long
#define bi __builtin_inf()
#define ll long long
#define mp make_pair
#define ss second
#define pb push_back
#define ff first
#define speed_cubing ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define um unordered_map
#define us unordered_set
#define bp __builtin_popcount
#define ld long double
#define pll pair<ll, ll>
#define PI 3.1415926535
const int N = 1e3 + 5;
const int mod = 1e9 + 7;


int32_t main()
{

  speed_cubing

  int q;
  cin>>q;

  while(q--){
   
    int n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    vector<int> pos;

    map<char,int> m;

    for(int i=0;i<n;i++){
      if(s[i]!=t[i])
        pos.pb(i);
      m[s[i]]++,m[t[i]]++;
    }    

    bool f = 0;

    for(auto x:m)
       if(x.ss%2==1)
         f = 1;

    if(f){
      cout<<"No\n";
      continue;
    }    

    cout<<"Yes\n";

    vector<pii> ans;
   
    vector<pair<int,char> > v1,v2;

    for(auto x:pos){
      v1.pb({x,s[x]});
      v2.pb({x,t[x]});
    }   

    // cout<<v1.size()<<endl;

    for(int i=0;i<(int)v1.size()-1;i++){
       
       bool flag = 0;

      //  cout<<v1[i].ss<<endl; 

       if(v1[i].ss==v2[i].ss)
         continue;
 
    
       for(int j=i+1;j<(int)v1.size();j++){
          if(v1[j].ss==v1[i].ss){
            flag = 1;
            ans.pb({v2[i].ff,v1[j].ff});
            swap(v2[i].ss,v1[j].ss);
            break;
          }
       }

       if(!flag){
         for(int j=i;j<(int)v2.size();j++){
           if(v2[j].ss==v1[i].ss){
              ans.pb({v2[j].ff,v1[i+1].ff});
              swap(v2[j].ss,v1[i+1].ss);
              ans.pb({v2[i].ff,v1[i+1].ff});
              swap(v2[i].ss,v1[i+1].ss);
              break;
           }
         }
        //  cout<<32<<endl;
       }

    }

    cout<<ans.size()<<'\n';

    for(auto x:ans)
      cout<<x.ss+1<<' '<<x.ff+1<<'\n';


  }

      
  

  return 0;
}