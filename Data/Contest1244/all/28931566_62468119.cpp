#include<bits/stdc++.h>
#define rint register int
#define deb(x) cerr<<#x<<" = "<<(x)<<'\n';
//#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef long long ll;
using pii = pair <ll,int>;
int T, a, b, c, d, k; 

int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int x = a / c + (a % c > 0);
		int y = b / d + (b % d > 0);
		if(x + y > k) puts("-1");
		else printf("%d %d\n", x, y);
	}
}
