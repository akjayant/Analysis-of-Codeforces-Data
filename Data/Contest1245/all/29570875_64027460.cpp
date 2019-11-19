#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
/*inline int lowbit(int x){return x&-x;}
long long calc(int x){
	int cnt=0,one=0,y=x,zero;
	while(y)y>>=1,cnt++;
	while(x)x-=lowbit(x),one++;
	zero=cnt-one;
	return 1LL<<zero;
}*/
int L[40],R[40],N,M;
long long f[40][2][2][2][2];
long long dfs(int x,bool f1,bool f2,bool f3,bool f4){
	//printf("%d %d %d\n",x,f1,f2);
	if(f[x][f1][f2][f3][f4]!=-1)return f[x][f1][f2][f3][f4];
	if(x==M+1)return f[x][f1][f2][f3][f4]=1;
	int la=0,lb=0,ha=1,hb=1;
	if(f1)la=L[x];
	if(f2)ha=R[x];
	if(f3)lb=L[x];
	if(f4)hb=R[x];
	f[x][f1][f2][f3][f4]=0;
	for(int i=la;i<=ha;i++)
		for(int j=lb;j<=hb;j++){
			if(i+j==2)continue;
			f[x][f1][f2][f3][f4]+=dfs(x+1,f1&&(i==L[x]),f2&&(i==R[x]),f3&&(j==L[x]),f4&&(j==R[x]));
		}
	return f[x][f1][f2][f3][f4];
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	for(int _=read();_;_--){
		int a=read(),b=read();
		N=M=0;
		while(a)
			L[++N]=a%2,a/=2;
		while(b)
			R[++M]=b%2,b/=2;
		reverse(L+1,L+1+N);
		reverse(R+1,R+1+M);
		for(int i=M;i>=1;i--)
			if(i>=M-N)
				L[i]=L[i-(M-N)];
			else
				L[i]=0;
		memset(f,-1,sizeof(f));
		printf("%I64d\n",dfs(1,1,1,1,1));
		/*for(int i=1;i<=M;i++)
			printf("%4I64d %4I64d %4I64d %4I64d\n",f[i][0][0],f[i][0][1],f[i][1][0],f[i][1][1]);*/
	}
	return 0;
}
