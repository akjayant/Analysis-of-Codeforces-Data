#include<cstdio>
#include<algorithm>
using namespace std;
char S[1005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",S+1);
		int lst=-1,nxt=-1;
		for(int i=1;i<=n;i++){
			if(S[i]!='1')continue;
			if(lst==-1)lst=i;
			nxt=i;
		}
		if(lst==-1){printf("%d\n",n);continue;}
		if(lst==nxt){
			printf("%d\n",max(max(lst,n-lst+1)*2,n+1));
		}else{
			int ans=max(2*nxt,2*(n-lst+1));
			ans=max(ans,n+2);
			ans=max(ans,(nxt-lst+1)*2+lst-1);
			printf("%d\n",ans);
		}
	}
	return 0;
}