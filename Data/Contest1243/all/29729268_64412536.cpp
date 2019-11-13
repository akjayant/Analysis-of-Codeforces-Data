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
char s[2000],t[2000];
int num[30];
int opt1[10010],opt2[10010],tot;
signed main()
{
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);scanf("%s",t+1);memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)num[s[i]-'a']++,num[t[i]-'a']++;tot=0;
		int Flag=1;for(int i=0;i<26;i++)if(num[i]%2!=0){if(Flag)cout<<"No"<<endl;Flag=0;}if(!Flag){continue;}
		for(int i=1;i<=n;i++){
			if(s[i]==t[i])continue;int flag=1;
			for(int j=i+1;j<=n;j++)
				if(t[i]==t[j]){
					opt1[++tot]=i;opt2[tot]=j;swap(s[i],t[j]);flag=0;break;
				}
			if(!flag)continue;
			for(int j=i+1;j<=n;j++)
				if(s[i]==s[j]){
					opt1[++tot]=j;opt2[tot]=i;swap(s[j],t[i]);flag=0;break;
				}
			if(!flag)continue;
			for(int j=i+1;j<=n;j++)
				if(s[i]==t[j]){
					opt1[++tot]=i+1;opt2[tot]=j;swap(s[i+1],t[j]);
					opt1[++tot]=i+1;opt2[tot]=i;swap(s[i+1],t[i]);flag=0;break;
				}
			if(!flag)continue;
			for(int j=i+1;j<=n;j++)
				if(t[i]==s[j]){
					opt1[++tot]=j;opt2[tot]=i+1;swap(s[j],t[i+1]);
					opt1[++tot]=i;opt2[tot]=i+1;swap(s[i],t[i+1]);flag=0;break;
				}
		}
		cout<<"Yes"<<endl;cout<<tot<<endl;
		for(int i=1;i<=tot;i++)cout<<opt1[i]<<" "<<opt2[i]<<endl;
	}
	return 0;
}