#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof((a)))

using namespace std;

typedef long long ll;
typedef double db;

const int MN = 3e5 + 5;
const int P = 998244353;

int rt[MN];
inline int get(int n){
	return rt[n]==n? n: rt[n]=get(rt[n]); 
}
inline void merge(int x,int y){
	if(get(x)!=get(y))
		rt[get(x)]=rt[get(y)];
}

inline void solve(int n){
//	int n; scanf("%d",&n);
//	for__(i,1,n) rt[i]=i;
//	for__(i,2,n) if(n%i==0) for__(k,1,i)
//		for(int j=i+k; j<=n; j+=i)
//			merge(j,k);
//	for__(i,1,n) printf("%d: %d\n",i,get(i)); puts("");
	
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
//	int _; scanf("%d",&_);// for__(i,1,_)
//		solve(i);
	ll n; scanf("%lld",&n);
	int ed=sqrt(n)+1;
	int cnt=0;
	ll prm=n;
	for__(i,2,ed)
		if(n%i==0){
			++cnt;
			prm=i;
			while(n%i==0) n/=i;
		}
	if(n>1) ++cnt;
	if(cnt==0) printf("%lld",n);
	else if(cnt==1) printf("%lld",prm);
	else puts("1"); 
	return 0;
}

