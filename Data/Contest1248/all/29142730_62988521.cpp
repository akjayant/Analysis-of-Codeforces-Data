#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
int a[maxn];


int main(){
	scanf("%d", &n);
	for(register int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	int halfn = n / 2;
	long long res1 = 0;
	long long res2 = 0;
	for(register int i = 1; i <= halfn; i ++){
		res1 += 1LL * a[i];
	}

	for(register int i = halfn + 1; i <= n; i ++){
		res2 += 1LL * a[i];
	}
	printf("%lld\n", res1 * res1 + res2 * res2);
	



	return 0;
}