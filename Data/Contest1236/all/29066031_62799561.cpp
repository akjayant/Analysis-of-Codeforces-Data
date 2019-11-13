#include<bits/stdc++.h>
using namespace std;
const int maxn=300+10;
void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int a[maxn][maxn];
int main(){
	int i,j,k,m,n;
	read(n);
	int cnt=0;
	for(register int i=1;i<=n;i++){
		if(i&1)
		for(register int j=1;j<=n;j++)
		a[j][i]=(++cnt);
		else 
			for(register int j=n;j>=1;j--)
				a[j][i]=++cnt;
	}
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
