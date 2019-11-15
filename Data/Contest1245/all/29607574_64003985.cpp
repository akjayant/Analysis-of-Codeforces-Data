#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
void in(int &x){
	char ch=getchar();int flag=0;x=0;
	while(ch<'0'||ch>'9')flag|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
int t,a,b,c,n; 
char s[N+10],ans[N+10];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	in(t);
	while(t--){
		scanf("%d \n %d %d %d",&n,&a,&b,&c);
		scanf("\n%s",s);
		int a1=0,b1=0,c1=0;//RPS  P-R-S-P b=>a=>c=>b
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='R')a1++;
			else if(s[i]=='P')b1++;
			else if(s[i]=='S')c1++;
		}
		int win=0;
		if(a>c1)win+=c1;
		else win+=a;
		if(b>a1)win+=a1;
		else win+=b;
		if(c>b1)win+=b1;
		else win+=c;
		if(2*win>=n){
			puts("YES");
			for(int i=0;i<=105;i++)ans[i]=' ';
			for(int i=0;i<strlen(s);i++){
				if(s[i]=='R'&&b!=0)b--,ans[i]='P';
				if(s[i]=='P'&&c!=0)c--,ans[i]='S';
				if(s[i]=='S'&&a!=0)a--,ans[i]='R';
			}
			for(int i=0;i<strlen(s);i++){
				if(ans[i]!='R'&&ans[i]!='P'&&ans[i]!='S'){
					if(a!=0)a--,ans[i]='R';
					else if(b!=0)b--,ans[i]='P';
					else ans[i]='S';
				}
			}
			printf("%s\n",ans);
		}
		else puts("NO");
	}
	return 0;
}


