#include <bits/stdc++.h>

#define N 1000010 

using namespace std;

char s[N], t[N];

int main() {
	int T;
	cin >> T ;
	while (T -- ) {
		int n;
		scanf("%d%s%s", &n, s + 1, t + 1);
		int p1 = 0, p2 = 0;
		bool flag = false;
		for (int i = 1; i <= n; i ++ ) {
			if (s[i] != t[i]) {
				if (!p1) {
					p1 = i;
				}
				else if (!p2) {
					p2 = i;
				}
				else {
					flag = true;
					puts("No");
					break;
				}
			}
		}
		if (flag) {
			continue;
		}
		if (!p2) {
			puts("No");
		}
		else {
			if (s[p1] == s[p2] && t[p1] == t[p2]) {
				puts("Yes");
			}
			else {
				puts("No");
			}
		}
	}
	return 0;
}