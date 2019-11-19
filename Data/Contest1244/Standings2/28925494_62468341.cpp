#include<bits/stdc++.h>
#define N 1005
#define Ms(a,b) memset(a,b,sizeof a)
#define db(x) cerr<<#x<<"="<<x<<endl;
#define db2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define db3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
using namespace std;
int T,n;
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		int ans=n;
		for(int i=1;i<=n;i++)if(s[i]=='1')ans=max(ans,max(i,n-i+1)*2);
		printf("%d\n",ans);
	}
	return 0;
}

