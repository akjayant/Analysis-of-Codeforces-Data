#include<stdio.h>
using namespace std;
int sh[100005],ch[100005];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,m,a1=0,a2=0;scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&sh[i]);
			if(sh[i]&1)a1++;
			else a2++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&ch[i]);
			if(ch[i]&1)ans+=a1;
			else ans+=a2;
		}
		printf("%I64d\n",ans);
	}
}
