#include<cstdio>
#include<cstring>
const int N=105;
char s[N],tb[3]={'R','P','S'},ans[N];
int sl[3],dy[135];
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<3;++i) dy[tb[i]]=i;
	while(t--){
		memset(ans,0,sizeof(ans));
		int n,ws=0;
		scanf("%d",&n);
		for(int i=0;i<3;++i) scanf("%d",&sl[i]);
		scanf("%s",s);
		for(int i=0;i<n;++i){
			int tt=(dy[s[i]]+1)%3;
			if(sl[tt]) --sl[tt],ans[i]=tb[tt],++ws; 
		}
		for(int i=0;i<n;++i)
			if(!ans[i])
				for(int j=0;j<3;++j)
					if(sl[j]){
						ans[i]=tb[j],--sl[j];
						break;
					}
		if(ws>=(n+1)/2) printf("yes\n%s\n",ans);
		else printf("no\n");
	}
	return 0;
} 