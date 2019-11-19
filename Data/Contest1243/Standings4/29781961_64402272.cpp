#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 100;
int cnt[N];
int main()
{
	ll n, tmp;
	cin>>n;
	tmp = n;
	for(ll i = 2; i * i <= n; ++i){
		while(n % i == 0) {
			n /= i;
			cnt[i]++;
		}
	}
	if(n == tmp) cout<<n<<endl;
	else if(n == 1){
		ll tot = 0, f = 0;
		for(int i = 1; i <= N - 100; ++i){
			if(cnt[i]) {
				tot++;
				if(!f) f = i;
			}
		}
		if(tot >= 2) puts("1");
		else cout<<f<<endl;
	}
	else puts("1");
}