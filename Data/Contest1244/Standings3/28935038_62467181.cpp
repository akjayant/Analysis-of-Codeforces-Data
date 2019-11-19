#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

void solve()
{
	int a, b,c, d, k;
	cin >> a >> b >> c >> d >> k;

	int a1 = (a + c - 1) / c;
	int b1 = (b + d - 1) / d;

	if (a1 + b1 > k)
	{
		cout << -1 << endl;
		return;
	}

	cout << a1 << " " << b1 << endl;
}
int main()
{
	// freopen("in.txt","r", stdin);
	// ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
