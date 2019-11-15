#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int a, b;
		scanf("%d%d", &a, &b);
		int t = __gcd(a, b);
		puts(t == 1 ? "Finite" : "Infinite");
	}
}