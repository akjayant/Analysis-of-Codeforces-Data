#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long
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
const int N = 1e5 + 2;
const int mod = 1e9 + 7;

int32_t main()
{
  speed_cubing
  
  int t;
  cin>>t;

  while(t--){
      
      int a,b,c,d,k;
      cin>>a>>b>>c>>d>>k;
      
      bool flag = 0;
      pii ans;

      for(int i=0;i<=k;i++){
         if(i*c>=a && (k-i)*d>=b){
            flag = 1;
            ans = {i,k-i};
            break;
         }
      }

      if(!flag)
        cout<<-1<<'\n';
      else
      {
        cout<<ans.ff<<' '<<ans.ss<<'\n';
      }
        

  }

  return 0;
}