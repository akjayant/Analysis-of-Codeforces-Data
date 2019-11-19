#include<cstdio>
using namespace std;

int main() {
	long long n;
	long long m;
	scanf("%lld", &n);
	m=n;
	long long ans=0;
	for (long long i=2;i*i<=m;i++) {
		if (m%i==0) {
			while (m%i==0) {
				m=m/i;
			}
			if (m!=1 && m!=ans) {
				ans=1;
				break;
			} else {
				ans=i;
				break;
			}
		}
	}
	if (ans==0) {
		ans=n;
	}
	printf("%lld\n", ans);
}
