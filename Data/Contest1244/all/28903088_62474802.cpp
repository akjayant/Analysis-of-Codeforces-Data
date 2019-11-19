#include<bits/stdc++.h>
using namespace std;
char str[1002];
int n;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",str+1);
		int len=0;
		for(int i=1;i<=n;i++)if(str[i]=='1')len=max(len,max(i,n-i+1));
		printf("%d\n",max(n,len*2));
	}
	return 0;
}