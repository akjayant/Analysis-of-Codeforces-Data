/** 
Humans are suspicious and jealous creatures. When they see something perfect, they want to find a flaw.        
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int MAXN = 1e3 + 5;
int a[MAXN];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int tt = clock();
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);
        int ans = 0;
        for (int i = n; i >= 0; --i) {
            if (a[i] >= n + 1 - i) ans = max(ans, n + 1 - i);
        }
        cout << ans << '\n';
    }
    



    cerr << "TIME = " << (double) 1.0 * (clock() - tt) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}
