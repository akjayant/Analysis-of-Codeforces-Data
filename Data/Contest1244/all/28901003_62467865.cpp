#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 1005;
const ll mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll q;
	cin >> q;
	while (q) {
        q --;
        int n;
        bool m[N] = {0};
        string s;
        cin >> n >> s;
        for (int i=0; i<s.size(); i++) {
            m[i+1] = s[i]-'0';
        }
        int mx = 0, mn = 0;
        for (int i=n; i>=1; i--) {
            if (m[i]) {
                mx = i;
                break;
            }
        }
        for (int i=1; i<=n; i++) {
            if (m[i]) {
                mn = i;
                break;
            }
        }
        if (!mx) cout << n << E;
        else {
            cout << max(mx*2, (n-mn+1)*2) << E;
        }
	}
    return 0;
}
