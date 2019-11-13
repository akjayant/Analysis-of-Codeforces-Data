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

void solve()
{
	int a,b,c;
	cin >> a>>b>>c;
	int sum = 0;
	int lCount = min(c / 2, b);
	sum += lCount * 3;
	b -= lCount;
	lCount = min(a, b / 2);
	sum += lCount*3;
	cout << sum << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t=1;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}