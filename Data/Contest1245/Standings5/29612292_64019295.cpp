#include<bits/stdc++.h>
using namespace std;const int N=1e2+7;
char s[N],t[N];int n,i,j,a,b,c,A,B,C,T_T;
int main(){
	for(scanf("%d",&T_T);T_T--;){
		for(scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1),A=B=C=0,i=1;i<=n;++i){
			if(s[i]=='R')A++;
			if(s[i]=='P')B++;
			if(s[i]=='S')C++;
			t[i]=0;
		}t[n+1]=0;
		if(min(a,C)+min(b,A)+min(c,B)>=(n+1)/2){
			for(i=1,j=min(a,C),a-=j;i<=n&&j;++i)if(s[i]=='S')t[i]='R',j--;
			for(i=1,j=min(b,A),b-=j;i<=n&&j;++i)if(s[i]=='R')t[i]='P',j--;
			for(i=1,j=min(c,B),c-=j;i<=n&&j;++i)if(s[i]=='P')t[i]='S',j--;
			for(i=1;i<=n;++i)if(!t[i]){
				if(a)a--,t[i]='R';
				else if(b)b--,t[i]='P';
				else if(c)c--,t[i]='S';
			}
			printf("YES\n%s\n",t+1);
		}else puts("NO");
	}
}