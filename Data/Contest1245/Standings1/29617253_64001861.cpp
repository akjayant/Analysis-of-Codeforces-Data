#include<bits/stdc++.h>
using namespace std;
char st[1000005];
int ans[1000005];
int main() {
	int t;
	scanf("%d", &t);
	while(t --) {
		int a, b ,c, n, anss = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) ans[i] = 0;
		scanf("%d%d%d", &a, &b, &c);
		int aa = a, bb = b, cc = c;
		scanf("%s", st + 1);
		for(int i = 1; i <= n; i ++) {
			if(st[i] == 'R' && b) b --, anss ++, ans[i] = 2;
			if(st[i] == 'P' && c) c --, anss ++, ans[i] = 3;
			if(st[i] == 'S' && a) a --, anss ++, ans[i] = 1;
		}
		if(anss >= (n + 1) / 2) {
			printf("YES\n");
			for(int i = 1; i <= n; i ++) {
				if(! ans[i]) {
					if(a) printf("R"), a --;
					else 
					if(b) printf("P"), b --;
					else printf("S"), c --;
				} else {
					if(ans[i] == 1) printf("R");
					if(ans[i] == 2) printf("P");
					if(ans[i] == 3) printf("S");
				}
			}
		} else printf("NO");
		printf("\n");
	}
	return 0;
}

