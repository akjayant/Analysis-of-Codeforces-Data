//I love Nanami ChiaKi
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=1e9+7;
//const int N=;
int f[307][307];
int main(){
	int n;
	scanf("%d",&n);
	int sum=1;
	for (int i=0;i<n;i++){
		if (i&1){
			for (int j=0;j<n;j++){
				f[j][i]=sum++;
			}			
		}
		else{
			for (int j=n-1;j>=0;j--){
				f[j][i]=sum++;
			}
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%d",f[i][j]);
			if (j==n-1) puts("");
			else printf(" ");
		}
	}
	return 0;
}
/*
input:
*/

