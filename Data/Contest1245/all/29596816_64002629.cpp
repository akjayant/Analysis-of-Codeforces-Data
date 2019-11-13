#include<bits/stdc++.h>
#define rep(q,a,b) for(int q=a,q##_end_=b;q<=q##_end_;++q)
#define dep(q,a,b) for(int q=a,q##_end_=b;q>=q##_end_;--q)
#define mem(a,b) memset(a,b,sizeof a )
using namespace std;
void in(int &r){
	static char c;
	r=0;
	bool flag=0;
	while(c=getchar(),!isdigit(c))if(c=='-')flag=1;
	do r=(r<<1)+(r<<3)+(c^48);
	while(c=getchar(),isdigit(c));
	if(flag)r=-r;
}
char as[105],sd[105];
int main(){
	int T,n,a,b,c;
	in(T);
	while(T--){
		in(n);
		in(a),in(b),in(c);
		scanf("%s",as+1);
		int a1=0,b1=0,c1=0;
		rep(q,1,n){
			if(as[q]=='R')++a1;
			else if(as[q]=='P')++b1;
			else ++c1;
		}
		int ans=0;
		ans+=min(a,c1)+min(b,a1)+min(c,b1);
		if(ans>=(n+1)/2){
			puts("YES");
			rep(q,1,n)sd[q]=0;
			int ct=min(a,c1);
			a-=ct;
			rep(q,1,n)if(as[q]=='S'&&ct)sd[q]='R',--ct;
			ct=min(b,a1);
			b-=ct;
			rep(q,1,n)if(as[q]=='R'&&ct)sd[q]='P',--ct;
			ct=min(c,b1);
			c-=ct;
			rep(q,1,n)if(as[q]=='P'&&ct)sd[q]='S',--ct;
			rep(q,1,n)if(sd[q]==0){
				if(a)sd[q]='R',--a;
				else if(b)sd[q]='P',--b;
				else sd[q]='S',--c;
			}
			rep(q,1,n)putchar(sd[q]);
			putchar('\n');
		}else puts("NO");
	}
	return 0;
}