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
int T,a,b,c,win,n;char ans[110],s[110];
signed main()
{
	T=read();
	while(T--){
		n=read();a=read();b=read();c=read();
		win=ceil((double)n/2);int tot=0;
		scanf("%s",s+1);int len=strlen(s+1);
		for(int i=1;i<=len;i++)ans[i]='.';
		for(int i=1;i<=len;i++){
			if(s[i]=='R'&&b){
				b--;ans[i]='P';tot++;
			}
			if(s[i]=='P'&&c){
				c--;ans[i]='S';tot++;
			}
			if(s[i]=='S'&&a){
				a--;ans[i]='R';tot++;
			}
		}
		for(int i=1;i<=len;i++){
			if(ans[i]<='Z'&&ans[i]>='A')continue;
			if(a){
				ans[i]='R';a--;
			}
			else if(b){
				ans[i]='P';b--;
			}else{
				ans[i]='S';c--;
			}
		}
		if(tot>=win){
			printf("YES\n");
			for(int i=1;i<=n;i++)cout<<ans[i];cout<<endl;
		}
		else printf("NO\n");
	}
	return 0;
}
