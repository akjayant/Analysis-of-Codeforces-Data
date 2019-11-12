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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;


int modularExponentiation(int x,int n,int M)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}

int32_t main()
{
   
  speed_cubing
  
  int n,m;
  cin>>n>>m;

  int ans = modularExponentiation(2,m,mod)-1;
   
  ans = modularExponentiation(ans,n,mod);

  if(ans<0)
    ans+=mod;

  cout<<ans;   

  return 0;

}