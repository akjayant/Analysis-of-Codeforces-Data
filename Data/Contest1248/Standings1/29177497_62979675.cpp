#include<cstdio>
#include<algorithm>
using namespace std;

int t;

int main(){
	scanf("%d", &t);
	for(int l = 1; l <= t; l++){
		int pn = 0, pp = 0, qn = 0, qp = 0, n, m;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);
			if(x%2 == 0) pp++;
			else pn++;
		}
		scanf("%d", &m);
		for(int i = 1; i <= m; i++){
			int x;
			scanf("%d", &x);
			if(x%2 == 0) qp++;
			else qn++;
		}
		long long score = (long long)pp*(long long)qp + (long long)pn*(long long)qn;
		printf("%I64d\n", score);
	}
	return 0;
}