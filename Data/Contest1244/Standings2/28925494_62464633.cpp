#include<bits/stdc++.h>
#define Ms(a,b) memset(a,b,sizeof a)
#define db(x) cerr<<#x<<"="<<x<<endl;
#define db2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define db3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;
using namespace std;
int T,a,b,c,d,k;
void solve() {
	for(int i=0; i<=k; i++) {
		if(c*i>=a&&(k-i)*d>=b) {
			printf("%d %d\n",i,k-i);
			return;
		}
	}
	puts("-1");	
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		solve();
	}
	return 0;
}
