#include<bits/stdc++.h>
using namespace std;
int a,b;
int T;
int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&a,&b);
		if(gcd(a,b) == 1) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}
