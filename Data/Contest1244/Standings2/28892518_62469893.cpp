#define make_pair mp
#define emplace_back pb
#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
const int N = 1e5 + 5;
int t, n;
char s[N];
int main()
{
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		scanf("%s", s);
		int cnt = 0;
		int fir, las;
		for(int i=0;i<n;i++) if(s[i] == '1') {
			cnt++;
			las = i;
		}
		for(int i=n-1;i>=0;i--) if(s[i] == '1') fir = i;

		int ans;
		if(cnt == 0) ans = n;
		else {
			ans = max(2 * (n - fir), 2 * (las + 1));
			ans = max(ans, n + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
