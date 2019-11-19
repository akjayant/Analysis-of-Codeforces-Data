#include <cstdio>
#include <algorithm>
#include <iostream>
#define M 1000000007
using namespace std;
int n,m;
long long f[100050][2],ans;
int main(){
	scanf("%d%d",&n,&m);
	f[1][1]=2;
	for (int i=2;i<=max(n,m);i++){
		f[i][0]=f[i-1][1];
		f[i][1]=(f[i-1][1]+f[i-1][0])%M;
	}
	ans=(f[m][0]+f[m][1]-2+f[n][1]+f[n][0])%M;
	cout << ans << "\n";
	return 0;
}
