#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6+10;
ll n;
ll p[maxn],c[maxn],cnt;
int main() {
	scanf("%lld",&n);
	for(ll i=2;i*i<=n;++i) {
		if(n%i==0) {
			++cnt;
			p[cnt]=i;
			while(n%i==0) {
				++c[cnt];
				n/=i;
			}
		}
	}
	if(n!=1) {
		++cnt;
		p[cnt]=n;
		c[cnt]=1;
	}
	if(cnt>1) {
		puts("1");
	}
	else {
		if(cnt==0) puts("1");
		else 
			printf("%lld\n",p[1]);
	}
	return 0;
}
