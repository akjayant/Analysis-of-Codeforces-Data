#include<bits/stdc++.h>
using namespace std;
typedef double D;
int i,j,a[12][12];
D f[12][12];
void go(int &xx,int &yy,int k){
	for (;k--;){
		if (xx&1){
			yy--;
			if (!yy) xx--,yy++;
		}else{
			yy++;
			if (yy>10) xx--,yy--;
		}
	}
}
D dfs(int x,int y){
	if (f[x][y]!=-1) return f[x][y];
	D t=0;int cnt=0;
	for (int i=1;i<=6;i++){
		int xx=x,yy=y;go(xx,yy,i);
		if (xx<=0) cnt++;
		else{
			D ff=dfs(xx,yy);
			if (!a[xx][yy]) t+=ff;
			else t+=min(ff,dfs(xx-a[xx][yy],yy));
		}
	}
	t=(t+6)/(6-cnt);
	return f[x][y]=t;
}
int main(){
	for (i=1;i<=10;i++)
		for (j=1;j<=10;j++) scanf("%d",&a[i][j]),f[i][j]=-1;
	f[1][1]=0;
	printf("%.9lf",dfs(10,1));
}