#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5; 
#define pb pop_back
#define ps push_back
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f; 
}
inline void chkmin(int &x,int y){if(y<x) x=y;}
inline void chkmax(int &x,int y){if(y>x) x=y;}
int a[505][505];
int main(){
	int n=read();
	int num=n*n;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--)
				a[i][j]=num,num--;
		}else for(int j=1;j<=n;j++) a[i][j]=num,num--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[j][i]);
		}
		puts("");
	}
	return 0;
}