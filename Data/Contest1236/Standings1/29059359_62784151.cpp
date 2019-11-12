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


int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
  	int n;
  	cin >> n;
  	while(n--)
  	{
  		int a,b,c;
  		cin >> a >> b >> c;
  		int ans = 0;
  		int z = min(c / 2,b);
  		ans += 3*z;
  		b -= z;
  		z = min(a,b / 2);
  		ans += 3*z;
  		cout << ans << endl;
  	}

    return 0;
}
 
 