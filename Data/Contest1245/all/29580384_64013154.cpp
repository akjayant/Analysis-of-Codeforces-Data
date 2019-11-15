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
const int mod=1e9+7;
int n,feb[MAXN];
char s[MAXN];

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	feb[1]=1,feb[2]=2,feb[3]=3;
	for(int i=4;i<=n;i++) feb[i]=(feb[i-1]+feb[i-2])%mod;
	LL ans=1;
	int cnt=0;
	for(int i=1;i<=n;i++) if(s[i]=='w'||s[i]=='m') {printf("0\n");return 0;}
	for(int i=1,j;i<=n;i++){
		if(s[i]=='u'||s[i]=='n'){
			for(j=i;j<=n;j++) if(s[j]!=s[i]) break;
			ans=ans*feb[j-i]%mod;
			i=j-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}