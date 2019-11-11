#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int T,a[3];
int n;
char f[maxn];
char ans[maxn];
char M[300],tr[300];
int cnt;
int main() {
	M['R'] = 1,M['P'] = 2,M['S'] = 0;
	tr[0]='R',tr[1]='P',tr[2]='S';
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d",&n,a,a+1,a+2);
		scanf("%s",f+1);
		cnt = 0;
		for(int i=1;i<=n;++i) {
			if(a[M[f[i]]]) {
				--a[M[f[i]]];
				ans[i] = M[f[i]];
				++cnt;
			}
			else ans[i] = -1;
		}
		if(cnt >= (n-1)/2+1) {
			puts("YES");
			for(int i=1;i<=n;++i) {
				if(ans[i]==-1) {
					for(int k=0;k<3;++k) {
						if(a[k]) {
							ans[i] = k;
							--a[k];
							break;
						}
					}
				}
			}
			for(int i=1;i<=n;++i) putchar(tr[ans[i]]);
			puts("");
		}
		else puts("NO");
	}
	return 0;
}
