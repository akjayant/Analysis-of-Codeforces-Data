#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
int a[110],check[110];
char s[110];
int main(){
	int t=read();
	while(t--){
		memset(check,0,sizeof(check));
		n=read();
		for(register int i=1;i<=3;i++)a[i]=read();
		scanf("%s",s+1);
		int num=0;
		for(register int i=1;i<=n;i++){
			if(s[i]=='R'){
				if(a[2]){num++;a[2]--;check[i]=1;}
			}
			if(s[i]=='P'){
				if(a[3]){num++;a[3]--;check[i]=1;}
			}
			if(s[i]=='S'){
				if(a[1]){num++;a[1]--;check[i]=1;}
			}
		}
		if(num*2>=n){
			puts("YES");
			for(register int i=1;i<=n;i++){
				if(s[i]=='R'){
					if(check[i])printf("P");
					else if(a[1]){printf("R");a[1]--;}
					else {printf("S");a[3]--;}
				}
				if(s[i]=='P'){
					if(check[i])printf("S");
					else if(a[1]){printf("R");a[1]--;}
					else {printf("P");a[2]--;}
				}
				if(s[i]=='S'){
					if(check[i])printf("R");
					else if(a[2]){printf("P");a[2]--;}
					else {printf("S");a[3]--;}
				}
			}puts("");
		}
		else puts("NO");
	}
	return 0;
}