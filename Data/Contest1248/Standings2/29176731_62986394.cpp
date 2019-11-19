#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long LL;

int n;
LL a[maxn], x, y;

int main(){
	scanf("%d", &n);
	x = 0, y = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i){
		if(i <= n / 2) x += a[i];
		else y += a[i];
	}
	printf("%I64d\n", x * x + y * y);
	return 0;
}