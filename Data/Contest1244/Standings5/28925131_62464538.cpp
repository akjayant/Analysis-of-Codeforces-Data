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
	int t;
	cin >> t;
	while(t--)
	{
		ll a , b , c , d , x , y , k;
		cin >> a >> b >> c >> d >> k;

		ll p , q;

		p = (a + c - 1)/c;
		q = (b + d - 1)/d;

		if(p + q > k)
			cout << -1 << endl;
		else
			cout << p <<" " << q << endl;
	}
	return 0;
}