#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <iomanip>
 
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define ppb pop_back
#define ft first
#define sd second
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define files read; write
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
const int Z = (int)3e3 + 228;
const int N = (int)2e5 + 228;
const int INF = (int)1e9 + 228;
const int MOD = (int)1e9 + 7;

int a[Z], cnt[Z];

int main()
{
	SWS;
	//files;
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i], cnt[a[i]]++;
		for (int i = 1000; i > 0; i--)
			cnt[i] += cnt[i + 1];
		//if (n == 3) cout << "KEK " << cnt[1] << endl;
		int l = 1, r = 1000;
		while (l < r)
		{
			int mid = (l + r + 1) / 2;
			if (cnt[mid] >= mid) l = mid;
			else r = mid - 1;
		}
		cout << l << "\n";
		for (int i = 1; i <= 1000; i++)
			cnt[i] = 0;
	}
	return 0; 
}