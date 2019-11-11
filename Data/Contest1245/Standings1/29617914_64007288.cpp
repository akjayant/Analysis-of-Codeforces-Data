#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=1e5+10;

ll f[N];
string s;

int main() {
	ios::sync_with_stdio(0);
	f[0]=1; f[1]=1; f[2]=2; for (int i=3; i<N; ++i) f[i]=(f[i-1]+f[i-2])%mod;
	cin>>s; int cnt=0; char lst='@';
	ll ans=1;
	for (char x: s) {
		if (x=='w' || x=='m') {
			cout<<0<<endl;
			return 0;
		}
		else
		if (x=='u') {
			if (lst==x) {
				cnt++;
			}
			else {
				ans=(ans*f[cnt])%mod;
				cnt=1;
			}
			lst=x;
		}
		else
		if (x=='n') {
			if (lst==x) {
				cnt++;
			}
			else {
				ans=(ans*f[cnt])%mod;
				cnt=1;
			}
			lst=x;
		}
		else {
			if (lst!='@') {
				ans=(ans*f[cnt])%mod;
			}
			lst='@'; cnt=0;
		}
	}
	if (lst!='@') {
		ans=(ans*f[cnt])%mod;
	}
	cout<<ans<<endl;
	return 0;
}