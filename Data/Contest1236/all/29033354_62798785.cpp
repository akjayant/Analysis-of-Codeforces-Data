#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=(int)3e2+5;
int ans[MAXN][MAXN];
int main(){
	int n;
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
		ans[i][1]=i;
	for(register int i=2;i<=n;i++)
		for(register int j=1;j<=n;j++)
			ans[j][i]=ans[n-j+1][i-1]+n;
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}

