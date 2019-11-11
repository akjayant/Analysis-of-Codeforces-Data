#include <cstdio>
#include <cstring>

#define R register
#define mod 1000000007
int N, a[100010], las, ans = 1;
char s[100010];

int main() {
	scanf("%s", s), N = strlen(s);
	a[0] = 1, a[1] = 1;
	for(R int i = 2; i <= N; ++i) a[i] = (a[i - 1] + a[i - 2]) % mod;
	for(R int i = 0; i < N; ++i) {
		if(s[i] == 'm' || s[i] == 'w') return puts("0"), 0;
		if(s[i] != s[las]) {
			if(s[las] == 'u' || s[las] == 'n') {
				ans = 1LL * ans * a[i - las] % mod;
			}
			las = i;
		}
	}
	if(s[las] == 'u' || s[las] == 'n') {
		ans = 1LL * ans * a[N - las] % mod;
	}
	return !printf("%d\n", ans);
}
