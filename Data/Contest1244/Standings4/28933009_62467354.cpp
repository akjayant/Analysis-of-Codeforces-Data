#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int t;
int a,b,c,d,k;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int x=ceil(1.0*a/(1.0*c));
		int y=ceil(1.0*b/(1.0*d));
		if(x+y>k){
			printf("-1\n");
			continue;
		}
		printf("%d %d\n",x,y);
	} 
	return 0;
} 