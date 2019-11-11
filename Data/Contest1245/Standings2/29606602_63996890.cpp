/** Simplicity is the final achievement **/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+55;

long long n, m;

long long arr[N];

int32_t main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    /** ONLY FOOLS RUSH IN **/
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a == 1 || b == 1 || __gcd(a, b) == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
    return 0;
}
