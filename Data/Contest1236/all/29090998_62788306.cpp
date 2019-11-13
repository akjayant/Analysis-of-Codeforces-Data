#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int t,a,b,c,F[105][105][105];
int read(){
	char c=getchar();int ans=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans;
}
int main(){
	t=read();
	for (register int i=0;i<=100;i++)
		for (register int j=0;j<=100;j++)
			for (register int k=0;k<=100;k++){
				if (i>=1&&j>=2) F[i][j][k]=max(F[i][j][k],F[i-1][j-2][k]+3);
				if (j>=1&&k>=2) F[i][j][k]=max(F[i][j][k],F[i][j-1][k-2]+3);
			}
	while (t--){
		a=read(),b=read(),c=read();
	    printf("%d\n",F[a][b][c]);
	}
	return 0;
}
