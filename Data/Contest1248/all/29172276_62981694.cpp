#include<set>
#include<map>
#include<stack>
#include<ctime>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
	bool f=0;int x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return !f?x:-x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
int a[MAXN+5];
LL s[MAXN+5];
int main(){
	int n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	printf("%lld\n",(s[n]-s[n/2])*(s[n]-s[n/2])+s[n/2]*s[n/2]);
	return 0;
}