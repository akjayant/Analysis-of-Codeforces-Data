#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 20101009;
const int maxn = 1e4 + 10;
char  s[maxn], t[maxn];
int w[30];
int main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		memset(w, 0, sizeof(w));
		int n;
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		int a = 0, b = 0, f = 1;
		for (int i = 1; i <= n&&f; i++) {
			if (s[i] != t[i] && !a)
				a = i;
			else if (s[i] != t[i] && !b)
				b = i;
			else if (s[i] != t[i] && b)
				f = 0;
		}
		if (f == 0||(a&&b==0))
			printf("No\n");
		else {
			if (s[a]==s[b]&&t[a]==t[b])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}

}