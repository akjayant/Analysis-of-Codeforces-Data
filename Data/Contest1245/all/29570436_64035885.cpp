#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;
const double inf=1e9;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef pair<int,int> pii;
inline void chkmin(int &x,int y){
	x=min(x,y);
}
inline void chkmax(int &x,int y){
	x=max(x,y);
}
#define X first
#define Y second
int n,m;
int a[N][N],b[N][N];
double f[N*N][2];
int pwx[N*N],pwy[N*N];
int main(){
	n=10;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=n;j++) 
			a[i][j]=read();
	int num=0;
	for(int i=1;i<=n;i++){
		if(i&1) {
			for(int j=1;j<=n;j++) {
				b[i][j]=++num;
				pwx[num]=i,pwy[num]=j;
			}
		}else {
			for(int j=n;j>=1;j--) {
				b[i][j]=++num;pwx[num]=i,pwy[num]=j;
			}
		}
	}
	for(int i=2;i<=7;i++) f[b[n][i]][0]=6,f[b[n][i]][1]=inf;
	for(int i=num-7;i>=1;i--) {
		for(int j=1;j<=6;j++) f[i][0]+=min(f[i+j][1],f[i+j][0])/6.0;
		f[i][0]+=1;
		f[i][1]=inf;
		int x=pwx[i],y=pwy[i];
		if(a[x][y]) f[i][1]=f[b[x+a[x][y]][y]][0];
		//if(a[pwx[i]][pwy[i]]) f[i][1]=f[b[pwx[i]+a[pwx[i]][pwy[i]]][pwy[i]]][pwy[i]];
	}
	printf("%.10lf",min(f[1][0],f[1][1]));
	return 0;
} 