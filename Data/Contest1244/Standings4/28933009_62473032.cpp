#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int t;
int n;
char s[2000];
int cango[2000];
int pre[2000]; 
int main(){
	scanf("%d",&t);
	while(t--){
		memset(cango,0,sizeof(cango));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		scanf("%s",s);
		for(int i=1;i<=n;i++){
			cango[i]=s[i-1]-'0';
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=max(ans,abs(i-j)+1);
				if(cango[j])ans=max(ans,abs(i-j)+1+max(n-j+1,j)); 
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}