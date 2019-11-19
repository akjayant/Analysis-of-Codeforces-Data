#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}
const int MAXN=1011;
char str[MAXN];
void solve(){
	int len=read();
	scanf("%s",str+1);
	int maxn=len;
	for(int i=1;i<=len;i++){
		if(str[i]=='0') continue;
		maxn=max(maxn,max(2*i,2*(len-i+1)));
	}printf("%d\n",maxn);return;
}
int main(){
//	freopen("1.in","r",stdin);
	int T=read();
	while(T--) solve();
}
