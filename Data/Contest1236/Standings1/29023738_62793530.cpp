#include<cstdio>
int a[305][305];
int main(){
	int n,s=0;
	scanf("%d",&n); 
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) a[i][j]=++s;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			printf("%d ",a[j][j&1?i:n-i+1]);
		printf("\n");
	}
	return 0;
}