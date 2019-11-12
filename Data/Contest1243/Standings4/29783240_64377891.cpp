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
        string s, t;
        cin >> n >> s >> t;
        int ind[10], j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) ind[j++] = i;
            if (j == 3) break;
        }
        if (j != 2 || s[ind[0]] != s[ind[1]] || t[ind[0]] != t[ind[1]]) cout << "No\n";
        else cout << "Yes\n";
    }


    return 0;
}
