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

int main() {
	ios::sync_with_stdio(false);
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	ll k=p%w;
	ll W=p/w, D=0;
	unordered_map<ll,int> seen;
	for(int i=0;;i++) {
		if(k%d == 0) {
			D=k/d;
			break;
		}
		if(seen[k%d]) {
			W=n+1;
			break;
		}
		seen[k%d]=1;
		k+=w;
		W--;
	}
	if(W+D>n || W<0 || D<0) {
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<W<<" "<<D<<" "<<(n-W-D)<<endl;
	return 0;
}