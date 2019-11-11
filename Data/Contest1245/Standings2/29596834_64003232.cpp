#include<bits/stdc++.h>
typedef int LL;
const LL maxn=1e3+9;
#define pb push_back
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+c-'0'; c=getchar();
	}
	return x*f;
}
LL T;
std::vector<LL> sta[300];
char s[maxn],Ans[maxn];
int main(){
	T=Read();
	while(T--){
		LL n=Read(),a(Read()),b(Read()),c(Read());
		scanf(" %s",s+1);
		char S('S'),P('P'),R('R');
		sta[S].clear(); sta[P].clear(); sta[R].clear();
		for(LL i=1;i<=n;++i){
			sta[s[i]].pb(i);
		}
		LL s1(sta[S].size()),s2(sta[R].size()),s3(sta[P].size());
		LL ans(std::min(a,s1)+std::min(b,s2)+std::min(c,s3));
		if(ans>=(n+1)/2){
			puts("YES");
			for(LL i=1;i<=n;++i) Ans[i]=0;
			for(LL i=0,up=std::min(a,s1);i<up;++i){
				Ans[sta[S][i]]=R;
			}
			a-=std::min(a,s1);
			for(LL i=0,up=std::min(b,s2);i<up;++i){
				Ans[sta[R][i]]=P;
			}
			b-=std::min(b,s2);
			for(LL i=0,up=std::min(c,s3);i<up;++i){
				Ans[sta[P][i]]=S;
			}
			c-=std::min(c,s3);
			for(LL i=1;i<=n;++i){
				if(Ans[i]) printf("%c",Ans[i]);
				else{
					if(a) --a,printf("R");
					else if(b) --b,printf("P");
					else printf("S");
				}
			}
			puts("");
		}else puts("NO");
	}
}