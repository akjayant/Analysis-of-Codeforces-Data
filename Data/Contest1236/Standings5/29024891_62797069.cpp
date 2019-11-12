#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int N=350;
int n;
int a[N][N];



int main(){
	scanf("%d",&n);
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				a[j][i]=cnt;
				cnt++;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=cnt;
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=1) printf(" ");
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 