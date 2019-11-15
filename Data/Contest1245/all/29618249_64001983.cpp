#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define M 1000005
using namespace std;
int t,a,b,c,cnt[5],n;
char s[M],ans[M];
int read(){
    char c=getchar();int ans=0;
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
    return ans;
}
int gcd(int x,int y){return x%y?gcd(y,x%y):y;}
int main(){
	t=read();
	while (t--){
		n=read();cnt[1]=cnt[2]=cnt[3]=0;
		a=read(),b=read(),c=read();scanf("%s",s+1);
		for (register int i=1;i<=n;i++){
			if (s[i]=='R') cnt[1]++;
			if (s[i]=='P') cnt[2]++;
			if (s[i]=='S') cnt[3]++;
		}
		int maxn=min(a,cnt[3])+min(b,cnt[1])+min(c,cnt[2]);
		if (maxn<((n+1)>>1)){printf("NO\n");continue;}
		printf("YES\n");
		for (register int i=1;i<=n;i++) ans[i]='?';
		for (register int i=1;i<=n;i++){
			if (s[i]=='R'&&b) b--,ans[i]='P';
			if (s[i]=='P'&&c) c--,ans[i]='S';
			if (s[i]=='S'&&a) a--,ans[i]='R';
		}
		for (register int i=1;i<=n;i++){
			if (ans[i]!='?') continue;
			if (a) ans[i]='R',a--;
			else if (b) ans[i]='P',b--;
			else ans[i]='S',c--;
		}
		for (register int i=1;i<=n;i++) putchar(ans[i]);
		putchar('\n');
	}
	return 0;
}
