#include <bits/stdc++.h>
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[1024];

int main()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int k;
	cin >> k;
	while(k--) {
		int n;
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		sort(a, a+n);
		int ans = 0;
		for(int i=0;i<n;i++)
			ans = max(ans, min(a[i], n-i));
		cout << ans << '\n';
	}
	
}
