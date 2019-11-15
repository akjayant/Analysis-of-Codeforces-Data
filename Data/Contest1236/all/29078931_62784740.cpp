#include <bits/stdc++.h>
using namespace std;
const int maxn=200050;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int a,b,c;
		scanf("%d%d%d", &a,&b,&c);
		int ans=0;
		for(int i = 0; i <= a && i*2 <= b; ++i) {
			ans = max(ans, i+min(b-i-i, c/2));
		}
		printf("%d\n", ans*3);
	}
	return 0;
}
