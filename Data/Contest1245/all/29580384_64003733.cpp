#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=1e5+10;
int T,n,R,P,S;
char s[MAXN],ans[MAXN];

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main(){
	T=read();
	while(T--){
		n=read(),R=read(),P=read(),S=read();
		scanf("%s",s+1);
		memset(ans,0,(n+5)*sizeof(char));
		int cnt=0;
		for(int i=1;i<=n;i++) if(s[i]=='S'&&R) ans[i]='R',R--,cnt++;
		for(int i=1;i<=n;i++) if(s[i]=='R'&&P) ans[i]='P',P--,cnt++;
		for(int i=1;i<=n;i++) if(s[i]=='P'&&S) ans[i]='S',S--,cnt++;
		for(int i=1;i<=n;i++) 
			if(!ans[i]){
				if(R) ans[i]='R',R--;
				else if(P) ans[i]='P',P--;
				else if(S) ans[i]='S',S--;
			}
		if(cnt*2>=n) printf("YES\n%s\n",ans+1);
		else printf("NO\n");
	}
	return 0;
}