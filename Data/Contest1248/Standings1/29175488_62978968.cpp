#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
typedef long long ll;

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

int main() {
	int T = read();
	while(T--) {
		int cnt[2];
		cnt[0] = cnt[1] = 0;
		int n = read();
		for(int i = 1;i <= n;++i) cnt[(read()) & 1]++;
		ll ans = 0;
//		printf("%d %d\n",cnt[0],cnt[1]);
		int m = read();
		for(int i = 1;i <= m;++i) 
			ans += cnt[(read()) & 1];
		cout<<ans<<endl;
	}
	return 0;
}
