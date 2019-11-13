#include<cstdio>
#include<iostream>
using namespace std;
const int N=105;
char x[N];
int fl[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a,b,c;
		scanf("%d%d%d%d%s",&n,&a,&b,&c,x+1);
		for(int i=1;i<=n;i++)fl[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(x[i]=='R'&&b)ans++,b--,fl[i]=1;
			if(x[i]=='P'&&c)ans++,c--,fl[i]=1;
			if(x[i]=='S'&&a)ans++,a--,fl[i]=1;
		}
		if(ans>=(n+1)/2){
			puts("YES");
			for(int i=1;i<=n;i++){
				if(fl[i]&&x[i]=='R')putchar('P');
				else if(fl[i]&&x[i]=='P')putchar('S');
				else if(fl[i]&&x[i]=='S')putchar('R');
				else if(a)a--,putchar('R');
				else if(b)b--,putchar('P');
				else if(c)c--,putchar('S');
			}
			puts("");
		}
		else puts("NO");
	}
	return 0;
}
