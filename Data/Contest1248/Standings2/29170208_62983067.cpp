#define Kafuu signed
#define Chino main

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

#define maxn 10000005
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
Kafuu Chino(){
	int t=read();
	while(t--){
		long long ans=0;
		int n=read(),tax[2]={0},_tax[2]={0};
		for(register int i=1;i<=n;++i)++tax[read()&1];
		n=read();
		for(register int i=1;i<=n;++i)++_tax[read()&1];
		printf("%I64d\n",1ll*tax[0]*_tax[0]+1ll*tax[1]*_tax[1]);
	}
}
