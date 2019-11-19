#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int read(){
	int f=0,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
char S[MAXN+5];
int main(){
	int T=read();
	while(T--){
		int n=read(),lst=1,ans=0,L=n+1,R=-1;
		scanf("%s",S+1);
		for(int i=1;i<=n;i++)
			if(S[i]=='1')
				ans+=i-lst+1,lst=i;
		for(int i=1;i<=n;i++)
			if(S[i]=='1')
				L=min(L,i),R=max(R,i);
		printf("%d\n",max(ans+n-lst+1,max(2*R,2*(n-L+1))));
	}
	return 0;
}
