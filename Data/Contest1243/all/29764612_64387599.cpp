#include <bits/stdc++.h>
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

vi pp(int n) {
	vi p;
	for(int i=2;i*i<=n;i++) {
		if(n % i) continue;
		while(n % i == 0) n /= i;
		p.PB(i);
	}
	if(n != 1) p.PB(n);
	return p;
}

signed main()
{
	
	int n;
	cin >> n;
	vi v = pp(n);
	if(v.size() == 1) cout << v[0] << endl;
	else cout << 1 << endl;
	
}

