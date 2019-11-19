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

map<LL, LL> M;

int main()
{
	// freopen("in.txt","r", stdin);
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	LL k;
	cin >> n >> k;

	FOR(i, 0, n)
	{
		int a;
		cin >> a;
		M[a]++;
	}

	while (1)
	{
		if (SZ(M) == 1) break;

		auto mn = M.begin();
		auto mx = M.end();
		mx--;

//		cout << mn -> first << ": " << mn -> second << endl;
//		cout << mx -> first << ": " << mx -> second << endl;
//		cout << k << endl;
//		cout << "------------------------------------" << endl;

		if (mn -> second < mx -> second)
		{
			auto it = M.begin();
			it++;
			LL cnt = 0;
			if ((it -> first - mn -> first) * mn -> second > k)
			{
				cnt = k / mn -> second;
			}
			else
			{
				cnt = it -> first - mn -> first;
			}

			if (cnt == 0) break;
			LL newK = mn -> first + cnt;
			LL newVal =  mn -> second;
			M.erase(mn);
			M[newK] += newVal;
			k -= cnt * newVal;
		}else
		{
			auto it = mx;
			it--;
			LL cnt = 0;
			if ((mx -> first - it -> first) * mx -> second > k)
			{
				cnt = k / mx -> second;
				//cout << "!" << cnt << endl;
			}else
			{
				cnt = (mx -> first - it -> first);
			}

			if (cnt == 0) break;
			LL newK = mx -> first - cnt;
			LL newVal =  mx -> second;
			M.erase(mx);
			M[newK] += newVal;
			k -= cnt * newVal;
		}
	}

	auto mn = M.begin();
	auto mx = M.end();
	mx--;
	cout << mx -> first - mn -> first << endl;
	return 0;
}
