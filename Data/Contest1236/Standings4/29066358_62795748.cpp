#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
const int INF = 0x3f3f3f3f;
int a[330][330];
int main(){
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				a[j][i]=++cnt;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=++cnt;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}