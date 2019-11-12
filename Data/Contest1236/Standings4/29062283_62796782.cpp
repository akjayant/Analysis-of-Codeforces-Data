#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int maxn=310;
int n,ans[maxn][maxn];
int main(){
	int t,i,j,k,a,b,c,cnt=0;
	cin>>n;
	for(i=1;i<=n;i++){
		if(i&1){
			for(j=1;j<=n;j++)
				ans[j][i]=++cnt;
		}
		else {
			for(j=n;j>=1;j--)
				ans[j][i]=++cnt;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf(j!=n?"%d ":"%d\n",ans[i][j]);
	}
	return 0;
}
/*
3
1 6 7
2 5 8
3 4 9 

1 4 7 
2 5 8 
3 6 9 
*/
