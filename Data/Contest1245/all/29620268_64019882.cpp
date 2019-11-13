#include<bits/stdc++.h>
#define cp complex<double>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXINF=2147483647;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-6;

int read(){
	int s=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	s=s*f;
	return s;
}

ll readll(){
	ll s=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	s=s*f;
	return s;
}

int gcd(int x,int y){
	if (!y) return x;
	return gcd(y,x%y);
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T=read();
	while (T--){
		int a=read(),b=read();
		if (gcd(a,b)>1) printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}

