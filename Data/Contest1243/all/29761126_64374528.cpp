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
#define nm 1005
int a[nm];
int main()
{
	int k,n,i,ans,temp;
	s(k);
	while(k--)
	{
		s(n);
		ans = -1;
		for(i=0;i<n;i++)
			s(a[i]);

		sort(a , a+n);

		for(i=0;i<n;i++)
			ans = max(ans , min(a[i]  ,  n - i));

		cout << ans << endl;
	}
	return 0;
}