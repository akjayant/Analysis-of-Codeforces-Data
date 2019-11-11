#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
int n,A,B,C;
char ch[105],ans[105];
int main(){
	reg int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&A,&B,&C);
		scanf("%s",ch+1);
		memset(ans,0,sizeof(ans));
		reg int tot=0;
		for(reg int i=1;i<=n;i++){
			if(ch[i]=='R'){if(B)B--,ans[i]='P',tot++;}
			if(ch[i]=='P'){if(C)C--,ans[i]='S',tot++;}
			if(ch[i]=='S'){if(A)A--,ans[i]='R',tot++;}
		}
		if(tot>=(n+1)/2){
			puts("YES");
			for(reg int i=1;i<=n;i++)
				if(!ans[i]){
					if(A)A--,ans[i]='R';
					else if(B)B--,ans[i]='P';
					else if(C)C--,ans[i]='S';
				}
			puts(ans+1);
		}
		else puts("NO");
	}
	return 0;
}