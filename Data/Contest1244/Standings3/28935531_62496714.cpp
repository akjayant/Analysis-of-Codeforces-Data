#define Kafuu signed
#define Chino main

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <time.h>

#define maxn 100005
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
int a[maxn],b[maxn],tax[maxn],dis[maxn],n,len;
Kafuu Chino(){
	int n=read();
	long long k=read<long long>(),p;
	for(register int i=1;i<=n;++i)dis[i]=a[i]=read();
	sort(dis+1,dis+1+n);
	len=unique(dis+1,dis+1+n)-dis-1;
	if(len==1){puts("0");return 0;}
	for(register int i=1;i<=len;++i)b[i]=dis[i];
	for(register int i=1;i<=n;++i)++tax[lower_bound(dis+1,dis+1+len,a[i])-dis];
	int mi=tax[1],ma=tax[len],l=2,r=len-1;
	while(1){
		if(b[l-1]==b[r+1]){puts("0");return 0;}
		if(mi<ma) {
			p=1ll*mi*(b[l]-b[l-1]);
			if(p>k){printf("%I64d\n",b[r+1]-b[l-1]-k/mi);return 0;}
			mi+=tax[l++],k-=p;
		}
		else {
			p=1ll*ma*(b[r+1]-b[r]);
			if(p>k){printf("%I64d\n",b[r+1]-b[l-1]-k/ma);return 0;}
			ma+=tax[r--],k-=p;
		}
	}
}
