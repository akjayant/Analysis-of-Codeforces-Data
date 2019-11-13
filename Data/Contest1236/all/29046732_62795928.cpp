#include<bits/stdc++.h>
using namespace std;
int n;
int a[500][500];
int main()
{
	scanf("%d",&n);
	int pd=0;
	int cnt=0;
	for(int j=1;j<=n;j++){
		if(!pd){
			for(int i=1;i<=n;i++){
				a[i][j]=++cnt;
			}
			pd=1-pd;
		}
		else{
			for(int i=n;i>=1;i--){
				a[i][j]=++cnt;
			}
			pd=1-pd;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}