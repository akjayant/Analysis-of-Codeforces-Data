#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=1e3+5;
#define LL long long
int T,n,Now;
char S[M];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&n,S+1);
		int Ans=n;
		for(int i=1; i<=n; ++i) {
			if(S[i]=='1')Ans=max(Ans,max(i,n-i+1)*2);
		}
		printf("%d\n",Ans);
	}
}