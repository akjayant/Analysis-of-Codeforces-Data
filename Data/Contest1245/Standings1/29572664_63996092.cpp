#include<stdio.h>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
int gcd(int p, int q) {
	while (p % q) { int t = p % q; p = q; q = t; }
	return q;
}
int main() {
	int i, j, k;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &i, &j);
		k = gcd(i, j);
		printf("%s\n", k == 1 ? "Finite" : "Infinite");
	}
}