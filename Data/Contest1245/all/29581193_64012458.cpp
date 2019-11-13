#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch>'9' || ch<'0'){
		if (ch=='-') w=-1;
		ch=getchar();
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
const int N=205;
int c[N],cnt[N];
char s[N],ans[N];
int main(){
	int T=read();
	while (T--){
		int n=read();
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		c['R']=read(),c['P']=read(),c['S']=read();
		scanf("%s",s+1);
		for (int i=1;i<=n;++i)	
			++cnt[s[i]];
		if (min(c['R'],cnt['S'])+min(c['S'],cnt['P'])+min(c['P'],cnt['R'])>=((n+1)>>1)){
			puts("YES");
			for (int i=1;i<=n;++i){
				ans[i]=0;
				if (s[i]=='S' && c['R']) --c['R'],ans[i]='R';
				if (s[i]=='R' && c['P']) --c['P'],ans[i]='P';
				if (s[i]=='P' && c['S']) --c['S'],ans[i]='S';
			}
			for (int i=1;i<=n;++i){
				if (!ans[i]){
					if (c['R']) --c['R'],ans[i]='R';
					else if (c['P']) --c['P'],ans[i]='P';
					else if (c['S']) --c['S'],ans[i]='S';
				}
				putchar(ans[i]);	
			}
			puts("");
		}else puts("NO");
	}
    return 0;
}
