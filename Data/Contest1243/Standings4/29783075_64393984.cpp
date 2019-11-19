#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
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
  
  int n;
  cin>>n;
  
  int gcd = 0;

  int x = sqrt(n);
  
  vector<int> v;

  for(int i=2;i<=x;i++){
     if(n%i==0){
       v.pb(i),v.pb(n/i);  
       gcd = __gcd(i,gcd);
       gcd = __gcd(n/i,gcd);
     }
  }

  if(v.size()==0){
    cout<<n;
  }
  else{
    cout<<gcd;
  }
 
  return 0;
}