#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof((a)))

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int MN = 3e5 + 5;
const int P = 1e9 + 7;

int f[MN];
char s[MN];

inline void solve(){
	scanf("%s",s);
	int n=strlen(s);
	for_(i,0,n) if(s[i]=='m' || s[i]=='w') return puts("0"), void();
	ll ans=1;
	for_(i,0,n){
		if(s[i]=='u'){
			int cnt=0;
			while(i<n && s[i]=='u') ++i, ++cnt;
			(ans*=f[cnt])%=P;
		}else if(s[i]=='n'){
			int cnt=0;
			while(i<n && s[i]=='n') ++i, ++cnt;
			(ans*=f[cnt])%=P;
		}else ++i;
		--i;	//������for �� ++ 
	}
	printf("%lld\n",ans);
	
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
	f[1]=f[0]=1;
	for_(i,2,MN) f[i]=((ll)f[i-1]+f[i-2])%P;
//	for_(i,2,10000) printf("%d  ",f[i]);
//	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

