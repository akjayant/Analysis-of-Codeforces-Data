#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
//coded by _Int_
inline void in(int &x){
    x=0;int s=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'&&(s=-1),c=getchar();
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
    x*=s;
}
int t,n,a,b,c;
char s[105],p[105];
int main(){
	in(t);
	while(t--){
		in(n);in(a);in(b);in(c);
		scanf("%s",s+1);memset(p,' ',sizeof(p));
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='R'){
				if(b)
					b--,p[i]='P',sum++;
			}
			if(s[i]=='P'){
				if(c)
					c--,p[i]='S',sum++;
			}
			if(s[i]=='S'){
				if(a)
					a--,p[i]='R',sum++;
			}
		}
		if(sum>=(n+1)/2){
			puts("YES");
			for(int i=1;i<=n;i++){
				if(p[i]!=' ')printf("%c",p[i]);
				else{
					if(a)a--,putchar('R');
					else if(b)b--,putchar('P');
					else if(c)c--,putchar('S');
				}
			}
			puts("");
		}
		else puts("NO");
	}
	return 0;
}
/*
R => rock
P => paper
S => scissor
*/ 
