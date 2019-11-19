#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define M 105
using namespace std;
double F[M][M];
int a[M][M];
pair <int,int> nxt[M][M];
int read(){
    char c=getchar();int ans=0;
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
    return ans;
}
double DFS(int x,int y){
	if (x==1&&y==1) return 0;
	if (F[x][y]>=0.0) return F[x][y];
	F[x][y]=0.0;int nowx=x,nowy=y,res=0;
	for (register int i=1;i<=6;i++){
		if (nowx==1&&nowy==1){res=7-i;break;}
		pair <int,int> now=nxt[nowx][nowy];
		nowx=now.first,nowy=now.second;
		if (a[nowx][nowy]) F[x][y]+=min(DFS(nowx,nowy),DFS(nowx-a[nowx][nowy],nowy));
		else F[x][y]+=DFS(nowx,nowy);
	}
	return F[x][y]=(F[x][y]+6)/(6-res);
}
int main(){
	for (register int i=1;i<=10;i++)
		for (register int j=1;j<=10;j++) F[i][j]=-1,a[i][j]=read();
	for (register int i=1;i<=10;i++)
		for (register int j=1;j<=10;j++){
			if (i&1){
				if (j>1) nxt[i][j]=make_pair(i,j-1);
				else nxt[i][j]=make_pair(i-1,1);
			}
			else {
				if (j==10) nxt[i][j]=make_pair(i-1,j);
				else nxt[i][j]=make_pair(i,j+1);
			}
		}
	printf("%.10lf",DFS(10,1));
	return 0;
}
	