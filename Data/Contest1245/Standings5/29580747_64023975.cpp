#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm> 
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
long long fib[N];
string a;
long long mul(long long a, int b){
	a %= mod;
	long long ans = 0;
	while(b){
		if(b % 2) ans = (ans + a) % mod;
		b >>= 1;
		a = a + a;
		if(a >= mod) a -= mod; 
	}
	return ans;
}
int main(){
	int i;
	fib[0] = 1;
	fib[1] = 1;
	for(i = 2; i <= N - 4; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
		if(fib[i] >= mod){
			fib[i] -= mod;
		} 
	}
	cin >> a;
	int len = a.size();
	int cnt1 = 0, cnt2 = 0;
	long long ans = 1;
	for(i = 0; i < len; i++){
		if(a[i] == 'm'){
			printf("0\n");
			return 0;
		}
		if(a[i] == 'w'){
			printf("0\n");
			return 0;
		}
	}
	for(i = 0; i < len; i++){
		if(a[i] != 'n' && cnt1 > 0){
			ans = mul(ans, fib[cnt1]);
			cnt1 = 0;
		}
		if(a[i] != 'u' && cnt2 > 0){
			ans = mul(ans, fib[cnt2]);
			cnt2 = 0;
		}
		if(a[i] == 'n'){
			cnt1++;
			//printf("1: %d\n", cnt1);
		}
		if(a[i] == 'u'){
			cnt2++;
			//printf("2: %d\n", cnt2);
		}
	}
	if(cnt1 > 0){
		ans = mul(ans, fib[cnt1]);
	}
	if(cnt2 > 0){
		ans = mul(ans, fib[cnt2]);
	}
	cout << ans << "\n";
	return 0;
}