#include "bits/stdc++.h"
using namespace std;

int t, a, b, c, d, k;
int ansA, ansB;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		int ansA = 0, ansB;
		ansA = a/c + (a%c > 0);
		ansB = (b/d + (b%d > 0));
		if(ansA+ansB <= k){
			printf("%d %d\n", ansA, ansB);
		}else{
			printf("-1\n");
		}
	}
}