#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int a[305][305],n,p;
int read(){
	char c=getchar();int ans=0;
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans;
}
int main(){
	n=read();
	for (register int j=1;j<=n;j++){
		if (j&1) for (register int i=1;i<=n;i++) a[i][j]=++p;
		else for (register int i=n;i>=1;i--) a[i][j]=++p;
	}
	for (register int i=1;i<=n;i++){
		for (register int j=1;j<=n;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
