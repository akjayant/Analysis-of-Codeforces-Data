#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 20101009;
const int maxn = 100 + 10;
char  s[maxn], t[maxn];
int w[30];
struct node {
	int l, r;
}q[maxn];
int main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		memset(w, 0, sizeof(w));
		int n;
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		for (int i = 1; i <= n; i++)
			w[s[i] - 'a']++, w[t[i] - 'a']++;
		int f = 1;
		for (int i = 0; i < 26; i++) {
			if (w[i] % 2)
				f = 0;
		}
		if (f == 0)
			printf("No\n");
		else {
			printf("Yes\n");
			int len = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] != t[i]) {
					int fl = 0;
					for (int j = i + 1; j <= n; j++) {
						if (t[j] == t[i]) {
							fl = j;
							break;
						}
					}
					if (fl) {
						swap(s[i], t[fl]);
						q[++len] = { i,fl };
					}
					else {
						for (int j = i + 1; j <= n; j++) {
							if (s[j] == t[i]) {
								fl = j;
								break;
							}
						}
						swap(s[fl], t[n]);
						q[++len] = { fl,n };
						swap(s[i], t[n]);
						q[++len] = { i,n };
					}
				}
			}
			printf("%d\n", len);
			for (int i = 1; i <= len; i++)
				printf("%d %d\n", q[i].l, q[i].r);
		}
	}

}