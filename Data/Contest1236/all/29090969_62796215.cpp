#include<bits/stdc++.h>
using namespace std;

int n,a[307][307],N;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i&1)a[j][i]=++N;
			else a[n-j+1][i]=++N;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}


