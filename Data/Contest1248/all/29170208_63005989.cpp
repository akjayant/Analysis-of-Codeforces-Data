#define Kafuu signed
#define Chino main

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

#define maxn 505
#define inf 0x3f3f3f3f
#define px putchar
#define pn px('\n')
#define ps px(' ')
#define pd puts("======================")
#define pj puts("++++++++++++++++++++++")

using namespace std;

inline int read(){
	int x=0,y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return y?-x:x;
}
template<typename T>
inline T read(){
	T x=0;
	int y=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return y?-x:x;
}
int n,suf[maxn],pre[maxn];
bool su[maxn],pr[maxn];
char s[maxn];
inline int check(){
	int ans=0,sum=0;
	for(register int i=1;i<=n;++i){
		pre[i]=pre[i-1]+(s[i]=='('?1:-1);
		if(s[i]=='(')++sum;
		else sum=max(sum-1,0);
		pr[i]=!sum;
	}
	sum=0;
	for(register int i=n;i;--i){
		suf[i]=suf[i+1]+(s[i]=='('?1:-1);
		if(s[i]==')')++sum;
		else sum=max(sum-1,0);
		su[i]=!sum;
	}
	for(register int i=1;i<=n;++i){
		if(pr[i]&&su[i+1]&&pre[i]==-suf[i+1])++ans;
		/* if(flag)printf("[%d,%d](%d,%d) ",pre[i],suf[i],pr[i],su[i]); */
	}
	return ans;
}
Kafuu Chino(){
	n=read();
	su[n+1]=1;
	scanf("%s",s+1);
	int ans=check(),x=1,y=1;
	/* printf("%d\n",ans); */
	for(register int i=1;i<=n;++i)
		for(register int j=i+1;j<=n;++j){
			if(s[i]==s[j])continue;
			swap(s[i],s[j]);
			/* if(i==7&&j==8)puts(s+1),flag=1; */
			int p=check();
			if(p>ans)ans=p,x=i,y=j;
			/* if(i==7&&j==8)flag=0; */
			swap(s[i],s[j]);
		}
	printf("%d\n%d %d\n",ans,x,y);
}
