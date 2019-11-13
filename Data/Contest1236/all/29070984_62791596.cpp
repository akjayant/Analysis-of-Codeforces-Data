#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

void read(int &x) {
    char c;bool flag = 0;
    while((c=getchar())<'0'||c>'9') flag |= (c=='-');
    x=c-'0';while((c=getchar())>='0'&&c<='9') x = (x<<3)+(x<<1)+c-'0';
    flag?x=-x:x;
}

typedef long long LL;
const LL p = (LL)1e9+7;

LL qpow(LL a,LL b) {
	LL ans = 1;
	for ( ; b; b>>=1,a=(a*a)%p)
	  if (b&1) ans = (ans*a)%p;
	return ans;
}

int main() {
  //  int T; read(T);
//	while(T--) {
		int a,b;
		read(a); read(b);
		printf("%d\n",qpow(qpow(2,b)-1,a));
	//} 
    return 0;
}
