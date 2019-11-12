#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> graph;
typedef long long ll;

#define F first
#define S second

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int q;

    cin >> q;

    while (q--) {
    	int n;

    	cin >> n;

    	vi a(n);

    	for (int i = 0; i < n; ++i) cin >> a[i];

    	sort(a.begin(), a.end());

    	int ans = 1;
    	for (int i = 0; i < n; ++i)
    	{
    		if (a[i] >= n - i) {
    			ans = n - i;
    			break;
    		}
    	}

    	cout << ans << endl;
    }

    return 0;
}
