#include <algorithm>
#include <cstdio>

int a, b;
int main() {
	for (scanf("%*d"); ~scanf("%d%d", &a, &b);)
		puts(std::__gcd(a, b) > 1 ? "Infinite" : "Finite");
}