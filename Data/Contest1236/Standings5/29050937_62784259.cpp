// Thu Oct 17 19:04:34 IST 2019
#include<bits/stdc++.h>
using namespace std;

#if DEBUG && !ONLINE_JUDGE
    #include "/home/raghukul/Competitive/templates/debug.h"
#else
    #define debug(args...)
    #define DBG(x...)
#endif

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0),cout.precision(17);
    int t;
    cin >> t;
    while(t--) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	int d = min(c/2, b);
    	b -= d;
    	int ans = min(b/2, a)*3 + d*3;
    	cout << ans << endl;
    }
    return 0;
}
