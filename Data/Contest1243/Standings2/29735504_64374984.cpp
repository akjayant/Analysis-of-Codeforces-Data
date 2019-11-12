#include <bits/stdc++.h>
using namespace std;

#define N 1012

int ntest, n, a[N], ans;

int main()
{
	#define file "huy"
	//freopen (file ".inp", "r", stdin);
	//freopen (file ".out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> ntest;
	while (ntest--){
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort (a + 1, a + 1 + n);
        ans = 1;
        for (int i = n - 1; i >= 1; i--){
            int pos = (n - i + 1);
            ans = max(ans, min(pos, a[i]));
        }
        cout << ans << "\n";
	}

	return 0;
}

