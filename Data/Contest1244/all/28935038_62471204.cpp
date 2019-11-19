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
	int n;
	string s;
	cin >> n >> s;
	int left = -1, right = -1;
	FOR(i, 0, n)
	{
		if (s[i] == '1')
		{
			right = i;
			if (left == -1) left = i;
		}
	}

	int ans = n;
	if (left != -1)
	{
		ans = max(ans, (n - left) * 2);
	}

	if (right != -1)
	{
		ans = max(ans, (right + 1) * 2);
	}

	cout << ans << endl;
}
int main()
{
	//freopen("in.txt","r", stdin);
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
