#include<bits/stdc++.h>
using namespace std;
char s[200];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int n, a, b, c;
		char ans[200];
		memset(ans, '\0', sizeof ans);
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf("%s", s + 1);
		for(int i = 1; i <= n; ++i){
			if(s[i] == 'R') {
				if(b) ans[i] = 'P', b--; 
			}
			else if(s[i] == 'P') {
				if(c) ans[i] = 'S', c--;
			}
			else {
				if(a) ans[i] = 'R', a--;
			}
		}
		int t = 0;
		for(int i = 1; i <= n; ++i){
			if(ans[i] == '\0'){
				if(a) ans[i] = 'R', a--;
				else if(c) ans[i] = 'S', c--;
				else if(b) ans[i] = 'P', b--;
			} else t++;
		}
		if(t * 2 >= n) {
			puts("YES");
			ans[n + 1] = '\0';
			printf("%s\n", ans + 1);
		}
		else puts("NO");
	}
}