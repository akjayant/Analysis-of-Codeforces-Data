#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
LL arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	LL x = 0, y = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	int i = 0;
	for (; i < n / 2; ++i)
		x += arr[i];
	for (; i < n; ++i)
		y += arr[i];
	cout << x * x + y * y << "\n";
}