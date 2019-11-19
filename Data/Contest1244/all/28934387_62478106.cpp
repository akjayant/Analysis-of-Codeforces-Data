#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int T,n;
char s[N];
int main() {
	scanf("%d", &T);
	while (T--){
		scanf("%d%s", &n, s+1);
		int x=0, minx=n+1, maxx=0;
		for (int i=1;i<=n;++i){
			if (s[i]=='1') x++, minx=min(minx, i), maxx=max(maxx, i);
		}
		if (!x){
			printf("%d\n", n);
			continue;
		}
		int ans=max(maxx, n-minx+1);
		ans=max(ans,n-maxx+1), ans=max(ans, n-minx+1);
		ans*=2;
                ans=max(ans,n+x);
		printf("%d\n", ans);
	}
	return 0;
}
