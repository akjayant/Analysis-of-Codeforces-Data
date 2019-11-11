#include<cstdio>
char s[1000],ans[1000];
int T,n,a,b,c,win;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",s);win=n;
		for(int i=0;i<n;i++){
			if(b>0&&s[i]=='R') b--,ans[i]='P';
			else if(c>0&&s[i]=='P') c--,ans[i]='S';
			else if(a>0&&s[i]=='S') a--,ans[i]='R';
			else win--;
		}
		//printf("%d\n",win);
		if(win<n-win) {puts("NO");for(int i=0;i<=n;i++) ans[i]=0;continue;}
		for(int i=0;i<n;i++){
			if(!ans[i]){
				if(a>0) a--,ans[i]='R';
				else if(c>0) c--,ans[i]='S';
				else if(b>0) b--,ans[i]='P';
			}
		}
		puts("YES");ans[n]='\0';
		printf("%s\n",ans);
		for(int i=0;i<=n;i++) ans[i]=0;
	}
}