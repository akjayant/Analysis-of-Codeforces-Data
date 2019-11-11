#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2005;

int n, A, B, C;
char s[N], ans[N];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d", &n, &A, &B, &C);
		scanf(" %s", s);
		
		int win = 0;
		for(int i = 0; i < n; i++) ans[i] = '#'; ans[n] = '\0';
		for(int i = 0; i < n; i++) {
			if(s[i] == 'S' && A) {
				A--;
				ans[i] = 'R';
				win++;
			}
			if(s[i] == 'R' && B) {
				B--;
				ans[i] = 'P';
				win++;
			}
			if(s[i] == 'P' && C) {
				C--;
				ans[i] = 'S';
				win++;
			}
		}
		for(int i = 0; i < n; i++) if(ans[i] == '#') {
			if(A) { A--; ans[i] = 'R'; }
			else if(B) { B--; ans[i] = 'P'; }
			else if(C) { C--; ans[i] = 'S'; }
		}
		if(win >= ceil((double)n / 2.))
			printf("YES\n%s\n", ans);
		else puts("NO");
	}
	return 0;
}