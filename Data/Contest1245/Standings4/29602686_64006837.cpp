#include<bits/stdc++.h>
#define ll long long
using namespace std;
int xlh,t1,n,ans[1010],a[1010],b[1010],c[1010];
int pd(char ch){
	if(ch=='R')return 0;
	if(ch=='P')return 1;
	return 2;
}
char zh(int x){
	if(x==0)return 'R';
	if(x==1)return 'P';
	return 'S';
}
char s[1010];
int main(){
	int i,j,x;
	scanf("%d",&t1);
	while(t1--){
		scanf("%d",&n);
		for(i=0;i<3;i++)scanf("%d",&a[i]);
		scanf("%s",s+1);
		//n=strlen(s+1);
		b[0]=b[1]=b[2]=0;
		for(i=1;i<=n;i++)b[pd(s[i])]++;
		c[0]=min(a[0],b[2]);
		c[1]=min(a[1],b[0]);
		c[2]=min(a[2],b[1]);
		xlh=c[0]+c[1]+c[2];
		if(xlh<(n+1)/2){
			puts("NO");
			continue;
		}
		for(i=1;i<=n;i++){
			ans[i]=-1;
			x=pd(s[i]);
			if(x==0)x=1;
			 else if(x==1)x=2;
			  else x=0;
			if(c[x])ans[i]=x,c[x]--,a[x]--;
		}
		for(i=1;i<=n;i++)if(ans[i]==-1)
		 for(j=0;j<3;j++)if(a[j]){
		  ans[i]=j;a[j]--;break;}
		puts("YES");
		for(i=1;i<=n;i++)printf("%c",zh(ans[i]));puts("");
	}
}