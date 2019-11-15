//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int N=105;

int T;
int n,a,b,c,aa,bb,cc;
char s[N],t[N];

signed main(){
	rd(T);
	while(T--){
		rd(n);
		rd(a),rd(b),rd(c);
		scanf("%s",s+1);
		aa=0,bb=0,cc=0;
		rep(i,1,n){
			if(s[i]=='R')++aa;
			if(s[i]=='P')++bb;
			if(s[i]=='S')++cc;
		}
		if(min(a,cc)+min(b,aa)+min(c,bb)>=(n+1)/2){
			puts("YES");
			rep(i,1,n)t[i]=0;
			rep(i,1,n){
				if(s[i]=='R'){
					if(b)--b,t[i]='P';
				}
				if(s[i]=='P'){
					if(c)--c,t[i]='S';
				}
				if(s[i]=='S'){
					if(a)--a,t[i]='R';
				}
			}
			rep(i,1,n){
				if(t[i]==0){
					if(a)--a,t[i]='R';
					else if(b)--b,t[i]='P';
					else if(c)--c,t[i]='S';
				}
			}
			t[n+1]=0;
			puts(t+1);
		}else{
			puts("NO");
		}
	}
	return 0;
}