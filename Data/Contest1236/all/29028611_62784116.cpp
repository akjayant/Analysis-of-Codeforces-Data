#include <cstdio>
using namespace std;

int Q, a, b, c;

int main () {
    scanf ("%d", &Q); while (Q--) {
    	scanf ("%d %d %d", &a, &b, &c);
    	int ans = 0;
    	while (b && c > 1) {
    		ans += 3;
    		--b;
    		c -= 2;
    	}
    	while (a && b > 1) {
    		ans += 3;
    		--a;
    		b -= 2;
    	}
    	printf ("%d\n", ans);
    }
	return 0;
}