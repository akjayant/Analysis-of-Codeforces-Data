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
int n,p,w,d;

int32_t main()
{
  speed_cubing
  
  cin>>n>>p>>w>>d;

  int x = p/w;

  vector<int> ans;

  for(int i=x;i>=0 && i>=x-N;i--){
     
      int temp = p-i*w;

      if(temp%d==0){
         int y = temp/d;
         if(n-(i+y)>=0){
            ans = {i,y,n-(i+y)};
            break;
         }
         else 
           break;
      }

  }

  if(ans.size()){
    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2];
  }
  else 
    cout<<-1;

  return 0;
}