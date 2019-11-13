// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

int n,a[305][305];

int main(){
	scanf("%d",&n);
	int cnt=n*n;
	for(int i=1;i<=n;i++){
		if(i&1)
			for(int j=1;j<=n;j++){
				a[i][j] = cnt--;
			}
		else
			for(int j=n;j>=1;j--){
				a[i][j] = cnt--;
			}
	}
	for(int j=1;j<=n;j++,puts(""))
		for(int i=1;i<=n;i++)printf("%d ",a[i][j]);

	return 0;
}
