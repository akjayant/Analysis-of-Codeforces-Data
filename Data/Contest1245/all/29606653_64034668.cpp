#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[37][2][2];
int a[37],b[37];
ll solve(int x,int y){
//	printf("%d %d !\n",x,y);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int len=0;
	while(x){
		a[++len]=x%2;
		x/=2;
	}
	len=0;
	while(y){
		b[++len]=y%2;
		y/=2;
	}
//	for(int i=30;i>0;--i)printf("%d",a[i]);puts("");
//	for(int i=30;i>0;--i)printf("%d",b[i]);puts("");
	memset(f,0,sizeof(f));
	f[31][1][1]=1;
	for(int i=30;i>0;--i){
		if(a[i]==0&&b[i]==0){
			f[i][1][1]=f[i+1][1][1];
			f[i][0][1]=2*f[i+1][0][1];
			f[i][1][0]=2*f[i+1][1][0];
			f[i][0][0]=3*f[i+1][0][0];
		}
		if(a[i]==0&&b[i]==1){
			f[i][1][1]=f[i+1][1][1];
			f[i][0][1]=f[i+1][0][1];
			f[i][1][0]=2*f[i+1][1][0]+f[i+1][1][1];
			f[i][0][0]=3*f[i+1][0][0]+2*f[i+1][0][1];
		}
		if(a[i]==1&&b[i]==0){
			f[i][1][1]=f[i+1][1][1];
			f[i][1][0]+=f[i+1][1][0];
			f[i][0][1]=2*f[i+1][0][1]+f[i+1][1][1];
			f[i][0][0]=3*f[i+1][0][0]+2*f[i+1][1][0];
		}
		if(a[i]==1&&b[i]==1){
			f[i][1][0]=f[i+1][1][1]+f[i+1][1][0];
			f[i][0][1]=f[i+1][1][1]+f[i+1][0][1];
			f[i][0][0]=f[i+1][1][1]+2*f[i+1][0][1]+2*f[i+1][1][0]+3*f[i+1][0][0];
		}
	}
	return f[1][0][0]+f[1][0][1]+f[1][1][0]+f[1][1][1];
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%I64d\n",solve(r,r)-solve(l-1,r)-solve(r,l-1)+solve(l-1,l-1));
	}
	return 0;
}
/*
3
1 4
323 323
1 1000000

1
1 4
*/
