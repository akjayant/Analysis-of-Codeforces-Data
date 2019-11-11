//#pragma GCC optimize(3)
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
typedef long long LL;
using namespace std;
#define MAXN 500005
#define eps (1e-11)
#define lyh 19260817
#define njj 19491001
const double pi = acos(-1.0);
#define P pair<int,int>
//#define int LL

char s[MAXN];
char ans[MAXN];
int a, b, c;

void pp(int i) {
	if (a != 0) {
		printf("R");
		a--;
	}
	else if (b != 0) {
		printf("P");
		b--;
	}
	else if (c != 0) {
		printf("S");
		c--;
	}
}

signed main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		scanf("%d%d%d", &a, &b, &c);
		scanf("%s", s);
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R') {
				if (b) {
					b--;
					count++;
					ans[i] = 'P';
				}
				else {
					ans[i] = '*';
				}
			}
			else if (s[i] == 'P') {
				if (c) {
					c--;
					count++;
					ans[i] = 'S';
				}
				else {
					ans[i] = '*';
				}
			}
			else if (s[i] == 'S') {
				if (a) {
					a--;
					count++;
					ans[i] = 'R';
				}
				else ans[i] = '*';
			}
		}
		ans[n] = '\0';
		if (count < (n + 1) / 2) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
			for (int i = 0; i < n; i++) {
				if (ans[i] != '*')printf("%c", ans[i]);
				else {
					pp(i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}