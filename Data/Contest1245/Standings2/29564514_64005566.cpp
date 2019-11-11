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
const int mod=1e9+7;
char a[100010];
int f[100010],ans=1,p=0,n;
signed main()
{
	scanf("%s",a+1);n=strlen(a+1);
	f[1]=1;f[2]=2;
	for(int i=3;i<=100000;i++)f[i]=(f[i-1]+f[i-2])%mod;
	int flag=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='m'||a[i]=='w')flag=1;
	}if(flag){printf("0");return 0;}
	for(int i=1;i<=n;i++){
		if((a[i]=='n'||a[i]=='u')&&(a[i]==a[i-1]))p++;
		if((a[i]=='n'||a[i]=='u')&&(a[i]!=a[i-1])){
			if(a[i-1]=='n'||a[i-1]=='u'){
				ans=ans*f[p]%mod;p=1;
			}else p=1;		
		}
		if((a[i]!='n'&&a[i]!='u')&&(a[i-1]=='n'||a[i-1]=='u')){
			ans=ans*f[p]%mod;p=0;
		}
	}
	if(p)ans=ans*f[p]%mod;
	cout<<ans<<endl;
	return 0;
}
