#include<bits/stdc++.h>
#define M 1005
using namespace std;
int n;
char s[M];
int main(){
	for(int _=(scanf("%d",&_),_);_;_--){
		scanf("%d%s",&n,s+1);
		int l=0,r=0;
		for(int i=1;i<=n;i++)if(s[i]=='1'){l=i;break;}
		for(int i=n;i;i--)if(s[i]=='1'){r=i;break;}
		if(!l)printf("%d\n",n);
		else{
			printf("%d\n",2*n-min(l-1,n-r)*2);
		}
	}
	return 0;
}