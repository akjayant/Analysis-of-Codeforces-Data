#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 1000000
#define N 300005

ll fastexpom(ll a,ll b,ll m)
{
  ll res=1;
      while(b>0)
      {
        if(b%2==1)
          res=(((res)%m)*((a)%m))%m;
        a=(((a)%m)*((a)%m))%m;
        b/=2;
      }
      return res;
}
int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
  	int n,m;
  	cin >> n >> m;
  	int bs = fastexpom(2,m,mod) - 1;
  	int ans = fastexpom(bs,n,mod);
  	cout << ans << endl;

    return 0;
}
 
 