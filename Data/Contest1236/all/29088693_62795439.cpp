#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
const int maxn=305;
int a[maxn][maxn];
int n;

void solve(){
	scanf("%d",&n);
	int num=0;
	for(int j=1;j<=n;j++){
		if(j%2){
			for(int i=1;i<=n;i++)	a[i][j]=++num;
		}
		else{
			for(int i=n;i>=1;i--)	a[i][j]=++num;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	printf("%d ",a[i][j]);
		printf("\n");
	}
}
int main(){
	solve();
	return 0;
}