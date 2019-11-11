#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
	int a,b;
	int t; scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		if(gcd(a,b)==1) printf("Finite\n");
		else printf("Infinite\n");
	}
}