#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#define MAXN 500
using namespace std;
int a[MAXN][MAXN],cnt;
int main(){
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i%2==1){
			for(j=1;j<=n;j++)
			a[j][i]=++cnt;
		}
		else{
			for(j=n;j>=1;j--)
			a[j][i]=++cnt;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}


