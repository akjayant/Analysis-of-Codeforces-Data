//mridul1809
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define s(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define p(x) printf("%d ",x)
#define pl(x) printf("%lld ",x)
#define pd(x) printf("%lf ",x)
#define ps(x) printf(x)
#define pend printf("\n")
#define nm 100005
int main()
{
	ll n;
	ll i;
	cin >> n;
	ll ans = n;
	for(i=2;i*i <= n ;i++)
		if(n%i == 0)
			ans = __gcd(ans , i) , ans = __gcd(ans , (n/i));

	cout << ans << endl;
	return 0;
}