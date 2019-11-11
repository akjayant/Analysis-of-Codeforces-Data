#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>

#define rep(a,b,c) for(int a=b;a<c;a++)
#define i(a) scanf("%d",&a)
#define l(a) scanf("%lld",&a)
#define INF 1000000000
typedef long long ll;
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main(){
	int t;
	i(t);
	while (t--) {
		int a, b; i(a); i(b);
		if (gcd(a, b) == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
}