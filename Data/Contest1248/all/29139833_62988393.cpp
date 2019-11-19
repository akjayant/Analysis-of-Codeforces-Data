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
const int maxn=510;
char s[maxn];
int N,sum[maxn];
int calc(){
	int mn=1<<30;
	for(int i=1;i<=N;i++){
		sum[i]=sum[i-1];
		if(s[i]=='(')sum[i]++;
		else sum[i]--;
		mn=min(mn,sum[i]);
	}
	if(sum[N])return 0;
	int S=0,res=0;
	for(int i=1;i<=N;i++){
		if(S>=-mn)
			res++;
		if(s[i]==')')S++;
		else S--;
	}
	return res;
}
int main(){
	//freopen("in","r",stdin);
	N=read();
	scanf("%s",s+1);
	int L=1,R=1,mx=0;
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++){
			swap(s[i],s[j]);
			int res=calc();
			if(res>mx)
				mx=res,L=i,R=j;
			swap(s[i],s[j]);
		}
	printf("%d\n%d %d\n",mx,L,R);
	return 0;
}
