#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define int long long int
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()

const int N = 309;
const int mod = 1000000007;

int n;
deque<int> q[N];

void pre()
{
}

int32_t main()
{
	IOS;
	pre();
	cin >> n;
	int pos;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			pos = i * n + j;
			q[i].push_back(pos);
		}
	}
	for (int i = 0; i < n; i++)
	{
		bool is = true;
		for (int j = 0; j < n; j++)
		{
			if (is)
			{
				cout << q[j].front() << " ";
				q[j].pop_front();
			}
			else
			{
				cout << q[j].back() << " ";
				q[j].pop_back();
			}
			is = (!is);
		}
		cout<<endl;
	}
}