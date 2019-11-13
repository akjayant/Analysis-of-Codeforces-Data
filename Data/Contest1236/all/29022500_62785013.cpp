#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int i,j,t,ans,a,b,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&a,&b,&c);
		ans=0;
		for(i=0;i<=a;i++)
		for(j=0;j<=c/2;j++){
			if((i*2+j)<=b)
			ans=max(ans,(i+j)*3);
		}
		printf("%d\n",ans);
	}
	return 0;
}
