#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,ans;
char s[111],res[111];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&a,&b,&c),scanf("%s",s+1),ans=0;
		for(int i=1;i<=n;i++)res[i]='A';
		for(int i=1;i<=n;i++){
			if(s[i]=='R'&&b)b--,ans++,res[i]='P';
			if(s[i]=='P'&&c)c--,ans++,res[i]='S';
			if(s[i]=='S'&&a)a--,ans++,res[i]='R';
		}
		for(int i=1;i<=n;i++)if(res[i]=='A'){
			if(a)res[i]='R',a--;
			else if(b)res[i]='P',b--;
			else res[i]='S',c--;
		}
		if(ans>=(n/2+n%2)){
			printf("YES\n");
			for(int i=1;i<=n;i++)printf("%c",res[i]);
			printf("\n");
		}
		else printf("NO\n");
	}
}