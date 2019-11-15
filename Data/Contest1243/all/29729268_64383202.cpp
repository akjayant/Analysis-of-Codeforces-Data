#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define int LL
#define INF 2147483647
#define LLINF 9223372036854775807
#define LL long long
#define xyx AKIOI
#define Dilute AKIOI
#define Chtholly_Tree AKIOI
#define time_interspace AKIOI
#define memset0 AKIOI
#define Isonan AKIOI
#define Sooke AKIOI
#define yeID AKIOI
#define _szh_ AKIOI
#define scimoon AKIOI
#define xay5421 AKIOI
#define dzh caibi
using namespace std;
int inline read(){
    int num=0,neg=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
    while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
    return num*neg;
}
int T,n;
char s[10010],t[10010];
signed main()
{
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);scanf("%s",t+1);
		int flag=1;
		for(int i=1;i<=n;i++)if(s[i]!=t[i])flag=0;
		if(flag){cout<<"Yes"<<endl;continue;}
		else{
			int tot=0,a[10010];
			for(int i=1;i<=n;i++)
				if(s[i]!=t[i]){
					a[++tot]=i;
				}
			if(tot>2||tot==1){cout<<"No"<<endl;continue;}
			else{
				swap(s[a[1]],t[a[2]]);
				int flag=1;for(int i=1;i<=n;i++)if(s[i]!=t[i])flag=0;
				if(flag){cout<<"Yes"<<endl;}else cout<<"No"<<endl;
			}
		}
	}
	return 0;
}
