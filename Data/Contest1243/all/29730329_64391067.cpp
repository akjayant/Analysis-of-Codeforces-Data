#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	scanf("%lld", &n);
	long long mdc = 0;
	for (long long i=2; i*i<=n; i++){
		if(n%i == 0){
			mdc = __gcd(mdc, i);
			mdc = __gcd(mdc, n/i);
		}
	}
	if(mdc == 0) mdc = n;
	printf("%lld\n", mdc);
}
