#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
typedef long long ll;
const int N = 1000000;
ll read() {
	ll x = 0,f = 1;char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int a[N];
int main() {
	int n = read();
	for(int i = 1;i <= n;++i) a[i] = read();
	sort(a + 1,a + n + 1);
	int k = 1;
	ll cnt1 = 0,cnt2 = 0;
	for(;k <= n / 2;++k) {
		cnt1 += a[k];
	}
	for(;k <= n;++k) {
		cnt2 += a[k];
	}
	cout<<cnt1 * cnt1 + cnt2 * cnt2;
	return 0;
}
