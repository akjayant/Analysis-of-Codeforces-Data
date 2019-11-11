#include<bits/stdc++.h>

using namespace std;

const int N=200;

int t,a,b,c,aa,bb,cc,m,n;

char s[N],ans[N];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m=(n+1)>>1;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s+1);
		aa=bb=cc=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='R'){
				++aa;
			}
			else if(s[i]=='P'){
				++bb;
			}
			else{
				++cc;
			}
		}
		if(min(a,cc)+min(b,aa)+min(c,bb)<m){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++){
			ans[i]=0;
			if(s[i]=='R'&&b>0){
				--b;ans[i]='P';
			}
			else if(s[i]=='P'&&c>0){
				--c;ans[i]='S';
			}
			else if(s[i]=='S'&&a>0){
				--a;ans[i]='R';
			}
		}
		for(int i=1;i<=n;i++){
			if(!ans[i]){
				if(a>0){
					--a;ans[i]='R';
				}
				else if(b>0){
					--b;ans[i]='P';
				}
				else{
					--c;ans[i]='S';
				}
			}
		}
		ans[n+1]=0;
		printf("%s\n",ans+1);
	}
	return 0;
}