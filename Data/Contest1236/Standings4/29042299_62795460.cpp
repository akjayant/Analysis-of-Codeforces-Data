#include<bits/stdc++.h>
using namespace std;
int a[305][305];
int main(){
	int n;
	scanf("%d",&n);
	int tx=1,ty=1,cnt=n*n;
	while(cnt){
		a[tx][ty]=cnt--;
		if(ty&1){
			if(tx<n)tx++;
			else ty++;
		}
		else{
			if(tx>1)tx--;
			else ty++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%d ",a[i][j]);
		printf("\n");
	}
} 