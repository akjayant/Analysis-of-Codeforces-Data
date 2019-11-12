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

    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];

    int ans = 0;

    sort(a,a+n,greater<int>());

    for(int i=0;i<n;i++){
      ans = max(ans,min((i+1),a[i]));
    }  

    cout<<ans<<'\n';

  }

      
  

  return 0;
}