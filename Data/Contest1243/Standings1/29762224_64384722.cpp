#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

ll T,cnt,n;
char used1[10010],used2[10010],s[10010],t[10010];

int main(){
	T=read();
	while(T--)
	{
		n=read();cnt=0;
		scanf("%s",s+1);
		scanf("%s",t+1);
		for(int i=1;i<=n;i++){
			if(s[i]!=t[i]){used1[++cnt]=s[i];used2[cnt]=t[i];}
		}
		if(cnt==0)printf("Yes\n");
		else if(cnt==2&&used1[1]==used1[2]&&used2[1]==used2[2])printf("Yes\n");
		else printf("No\n");
	}return 0;
}
