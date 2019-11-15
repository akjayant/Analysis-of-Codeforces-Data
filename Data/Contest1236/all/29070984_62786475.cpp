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

int main() {
    int T; read(T);
	while(T--) {
		int a,b,c;
		read(a); read(b); read(c);
		int t = min(b,c/2); b -= t;
		printf("%d\n",(t+min(a,b/2))*3);
	} 
    return 0;
}
