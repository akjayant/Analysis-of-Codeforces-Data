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
int N,f[maxn];
char s[maxn];
int main(){
	//freopen("in","r",stdin);
	scanf("%s",s+1);
	N=strlen(s+1);
	f[0]=1;
	for(int i=1;i<=N;i++){
		f[i]=f[i-1];
		if(i>=2){
			if(s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n'))
				(f[i]+=f[i-2])%=MOD;
		}
		if(s[i]=='m'||s[i]=='w')
			return printf("0\n"),0;
	}
	printf("%d\n",f[N]);
	return 0;
}
