#include<bits/stdc++.h>
using namespace std;

const int maxn=103;
char s[maxn];
int n,a,b,c,_a,_b,_c,T_T,sum;

int main(){
	scanf("%d",&T_T);
	while(T_T--){
		scanf("%d",&n);
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s+1);
		sum=0;
		_a=0,_b=0,_c=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='R')++_a;
			if(s[i]=='P')++_b;
			if(s[i]=='S')++_c;
		}
		sum+=min(a,_c)+min(b,_a)+min(c,_b);
		if(sum>=(n+1)/2){
			puts("YES");
			int la=a-min(a,_c),lb=b-min(b,_a),lc=c-min(c,_b);
			for(int i=1;i<=n;++i){
				if(s[i]=='R'){
					if(b){
						--b;putchar('P');
					}else{
						if(la)putchar('R'),--la;
						else if(lc)putchar('S'),--lc;
					}
				}
				if(s[i]=='P'){
					if(c){
						--c;putchar('S');
					}else{
						if(lb)putchar('P'),--lb;
						else if(la)putchar('R'),--la;
					}
				}
				if(s[i]=='S'){
					if(a){
						--a;putchar('R');
					}else{
						if(lc)putchar('S'),--lc;
						else if(lb)putchar('P'),--lb;
					}
				}
			}
			puts("");
		}
		else puts("NO");
	}
	return 0;
}
