#include<bits/stdc++.h>
using namespace std;
#define  N 105

char s[N],t[N];
int n,a,b,c,A,B,C;

int main(){
	int T;cin>>T;
	while(T--){
		memset(t,0,sizeof t);
		cin>>n>>a>>b>>c;
		scanf("%s",s+1);
		//n=strlen(s+1);
		A=B=C=0; 
		for(int i=1;i<=n;i++)
			if(s[i]=='P')A++;
			else if(s[i]=='S')B++;
			else if(s[i]=='R')C++;
		
		int tot=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='S' && a){
				tot++;a--;t[i]='R';
			}
			else if(s[i]=='R' && b){
				tot++;b--;t[i]='P';
			}
			else if(s[i]=='P' && c){
				tot++;c--;t[i]='S';
			}
		if(tot<n/2+(n%2)){
			puts("NO");continue;
		}
		
		puts("YES");
		for(int i=1;i<=n;i++)if(t[i]==0){
			if(a){
				t[i]='R';
				a--;
			}
			else if(b){
				t[i]='P';
				b--;
			}
			else if(c){
				t[i]='S';
				c--;
			}
		}
		printf("%s\n",t+1);
	}
}