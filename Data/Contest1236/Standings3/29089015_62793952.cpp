#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define ll long long
#define N 330
using namespace std;
int n,a[N][N];
int main(){
//	freopen("a.in","r",stdin); 
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		if(i&1){
			for(int j=1;j<=n;++j) a[j][i]=(i-1)*n+j;
		}
		else{
			for(int j=1;j<=n;++j) a[j][i]=(i-1)*n+n-j+1;
		}
	}
	for(int i=1;i<=n;++i,printf("\n"))
	for(int j=1;j<=n;++j)
	printf("%d ",a[i][j]); 
	return 0;
}
