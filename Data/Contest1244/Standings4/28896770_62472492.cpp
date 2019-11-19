#include<cstdio>
#include<algorithm>
using std::max;
char s[1005];
int main(){
	int ts;
	scanf("%d",&ts);
	while(ts--){
		int n,ans;
		scanf("%d%s",&n,s+1);ans=n;
		for(int i=1;i<=n;++i)
			if(s[i]=='1') ans=max(ans,2*(n-i+1));
		for(int i=n;i;--i)
			if(s[i]=='1') ans=max(ans,2*i);
		printf("%d\n",ans);
	}
	return 0;
}