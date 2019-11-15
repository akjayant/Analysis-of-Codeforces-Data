/** Simplicity is the final achievement **/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+55;
const long long MD = 1e9+7;

long long t, n, m;

long long arr[N];

int32_t main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    /** ONLY FOOLS RUSH IN **/

    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr+n);
        long long ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, min(arr[i], (n-i)));
        cout << ans << "\n";
    }


    return 0;
}
