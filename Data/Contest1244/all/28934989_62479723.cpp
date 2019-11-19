#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
const int maxn = 1e3+10;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
char c[maxn];
int main(){
	int t=read();
	while(t--){
		n=read();
		scanf("%s",c+1);
		int ans=0;
		for(register int i=1;i<=n;i++){
			if(c[i]=='1')ans=max(ans,max(2*i,2*(n-i+1)));
			else ans=max(ans,max(i,n-i+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}