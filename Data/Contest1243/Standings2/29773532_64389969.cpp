#include <bits/stdc++.h>
#define fi first
#define se second
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

ll N;
int main()
{
	scanf("%I64d", &N);
	if (N==1ll) {
		puts("1");
		return 0;
	}
	ll i; int cnt=0; ll r=(ll)sqrt(N);
	ll mi;
	for (i=2; i<=r; i++) {
		if (N%i==0) {
			cnt++;
			while (N%i==0) N/=i;
			mi=i;
		}
	}
	if (cnt==0) {
		printf("%I64d\n", N);
	}
	else {
		if (N>1) cnt++;
		if (cnt==1) {
			printf("%I64d\n", mi);
		}
		else puts("1");
	}
	return 0;
}