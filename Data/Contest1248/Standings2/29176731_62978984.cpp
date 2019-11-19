#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;

int n, m;
int p[maxn], q[maxn];

int main(){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		long long odd = 0, ans = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &p[i]);
			if(p[i] & 1) odd++;
		}
		scanf("%d", &m);
		for(int i = 1; i <= m; ++i){
			scanf("%d", &q[i]);
			if(q[i] & 1) ans += odd;
			else ans += (n - odd);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}