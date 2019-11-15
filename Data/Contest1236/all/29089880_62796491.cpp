#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
//coded by _Int_
int n,a[305][305],num;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i%2)
			for(int j=1;j<=n;j++)a[i][j]=++num;
		else
			for(int j=n;j>=1;j--)a[i][j]=++num;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",a[j][i]);
		puts("");
	}
	return 0;
}
