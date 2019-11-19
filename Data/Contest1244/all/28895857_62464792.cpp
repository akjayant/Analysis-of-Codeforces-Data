#include <cstdio>
int main(){
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		int a, b, c, d, k;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		int t1 = a / c, t2 = b / d;
		if (a % c != 0){
			t1++;
		}
		if (b % d != 0){
			t2++;
		}
		if (t1 + t2 > k){
			printf("-1\n");
		}else{
			printf("%d %d\n", t1, t2);
		}
	}
}