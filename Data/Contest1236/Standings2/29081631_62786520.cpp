#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <set>
#include<stack>
#include <string>
#include <tuple>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

using ll = long long;
#define var auto
#define endl '\n'

const ll divi = 1000000007;

ll step(ll a, ll b)
{
	ll answer = 1;
	while (b != 0)
	{
		if (b % 2 == 1)
			answer = answer * a % divi;
		a = a * a % divi;
		b /= 2;
	}
	return answer;
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	cout << step((step(2, m) + divi - 1) % divi, n)<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	//cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}