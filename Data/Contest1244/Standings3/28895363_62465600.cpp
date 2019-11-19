#include<cstdio>

using namespace std;

int t, a, b, c, d, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int x = a / c;
		if(a % c)	x++;
		int y = b / d;
		if(b % d)	y++;
		if(x + y > k)
			puts("-1");
		else
			printf("%d %d\n", x, y);
	}
	return 0;
}
