#include <bits/stdc++.h>
using namespace std;
const int yzh = 1e9+7;

int n, m;

int quick_pow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b&1) ans = 1ll*a*ans%yzh;
		b >>= 1, a = 1ll*a*a%yzh;	
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	m = quick_pow(2, m)-1;
	m = (m+yzh)%yzh;
	printf("%d\n", quick_pow(m, n)); 
	return 0;	
}
