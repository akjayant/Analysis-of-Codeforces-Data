#include<iostream>
using namespace std;

long long binpow(long long n, long long k){
	if(k == 0) return 1;
	long long t = binpow(n, k / 2);
	if(k % 2 == 0){
		return t * t % 1000000007;
	} else {
		return t * t % 1000000007 * n % 1000000007;
	}
}

int main(){
	long long n, m;
	cin >> n >> m;
	long long res;
	res = binpow(2, m) - 1;
	res = res % 1000000007;
	long long ans = binpow(res, n) % 1000000007;
	cout << ans;
}