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

    for(int i=0;i<n;i++)
      if(s[i]!=t[i])
        pos.pb(i);
    

    if(pos.size()>2){
      cout<<"No\n";
      continue;
    }
    
    bool flag = 0;

    if(s==t)
      flag = 1;

    for(int i=0;i<pos.size();i++)
      for(int j=0;j<pos.size();j++){
         swap(s[pos[i]],t[pos[j]]);
         if(s==t)
           flag = 1;
         swap(s[pos[i]],t[pos[j]]);
      }  
   
    if(flag)
      cout<<"Yes\n";
    else 
      cout<<"No\n";  

  }

      
  

  return 0;
}