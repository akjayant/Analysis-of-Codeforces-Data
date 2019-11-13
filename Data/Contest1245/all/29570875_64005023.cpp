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
const int maxn=110;
int N,a,b,c;
char ans[maxn],s[maxn];
int main(){
	//freopen("in","r",stdin);
	for(int _=read();_;_--){
		N=read();
		a=read(),b=read(),c=read();
		for(int i=1;i<=N;i++)
			s[i]=one();
		memset(ans,'-',sizeof(ans));
		int win=0;
		for(int i=1;i<=N;i++)
			if(s[i]=='R'){
				if(b)b--,win++,ans[i]='P';
			}
			else if(s[i]=='P'){
				if(c)c--,win++,ans[i]='S';
			}
			else{//S
				if(a)a--,win++,ans[i]='R';
			}
		if(win>=(N+1)/2){
			puts("YES");
			for(int i=1;i<=N;i++)
				if(ans[i]!='-')
					printf("%c",ans[i]);
				else{
					if(a)printf("R"),a--;
					else if(b)printf("P"),b--;
					else printf("S"),c--;
				}
			puts("");
		}
		else
			puts("NO");
	}
	return 0;
}
