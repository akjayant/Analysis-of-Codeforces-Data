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
const int maxn=100010,MOD=int(1e9)+7;
int N,M,f[maxn];
int main(){
	//freopen("in","r",stdin);
	N=read(),M=read();
	f[1]=2,f[2]=4;
	for(int i=3;i<maxn;i++)
		f[i]=(f[i-2]+f[i-1])%MOD;
	int ans=(f[N]+f[M]-2)%MOD;
	if(ans<0)ans+=MOD;
	printf("%d\n",ans);
	return 0;
}

