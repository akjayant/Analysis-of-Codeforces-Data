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

const int N=100005,P=1000000007;

int n,f[N];char s[N];

int solve(int len){
	return f[len];
}

signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n)if(s[i]=='w'||s[i]=='m'){
		puts("0");
		return 0;
	}
	f[0]=1,f[1]=1;
	rep(i,2,n)f[i]=(f[i-1]+f[i-2])%P;
	int ans=1;
	for(int i=1;i<=n;){
		if(s[i]=='u'){
			int j=i;
			while(j<=n&&s[j]=='u')++j;
			ans=1ll*ans*solve(j-i)%P;
			i=j;
		}else if(s[i]=='n'){
			int j=i;
			while(j<=n&&s[j]=='n')++j;
			ans=1ll*ans*solve(j-i)%P;
			i=j;
		}else{
			++i;
		}
	}
	pt(ans,'\n');
	return 0;
}