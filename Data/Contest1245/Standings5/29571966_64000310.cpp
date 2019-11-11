#include <bits/stdc++.h>

#define endl '\n'
#define ll long long int
#define let(x, a) __typeof(a) x(a)
#define all(a) (a).begin(), (a).end()
#define present(c, x) ((c).find(x) != (c).end())
#define tr(v, it) for (let(it, v.begin()); it != v.end(); it++)
#define rtr(v, it) for (let(it, v.rbegin()); it != v.rend(); it++)

#define trace1(x)					cerr << #x << ": " << x << endl;
#define trace2(x, y)				cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)				cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)		cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)	cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

using namespace std;

ll mod=1e9+7;
vector<ll> f(100005,0);

ll foo(ll x) {
	return f[x];
}

int main() {
	ios::sync_with_stdio(false);
	f[0]=f[1]=1;
	for(ll i=2;i<=100000;i++) {
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	string s;
	cin>>s;
	ll ans=1;
	for(int i=0;i<s.length();i++) {
		if(s[i]=='w' || s[i]=='m') {
			cout<<"0"<<endl;
			return 0;
		} else if(s[i]=='u' || s[i]=='n') {
			int j=i;
			while(j<s.length() && s[j]==s[i]) {
				j++;
			}
			ll x=j-i;
			i=j-1;
			ans*=foo(x);
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}