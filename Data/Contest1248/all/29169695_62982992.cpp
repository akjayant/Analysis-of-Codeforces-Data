#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	
	int n,m,v,t;

	scanf("%d", &t);
	while(t--) {
		int c[2][2];
		memset(c,0,sizeof(c));
		scanf("%d", &n);
		for(int i=0;i<n;++i) {
			scanf("%d", &v);
			c[0][v&1]++;
		}
		scanf("%d", &n);
		for(int i=0;i<n;++i) {
			scanf("%d", &v);
			c[1][v&1]++;
		}
		printf("%I64d\n", 1LL*c[0][1]*c[1][1] + 1LL*c[0][0]*c[1][0]);
	}
	return 0;
}	