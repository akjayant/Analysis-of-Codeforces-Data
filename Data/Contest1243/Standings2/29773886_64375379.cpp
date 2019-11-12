#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(int argc, char *argv[]) {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int ans = 0;
        for (int i=0;i<n;i++) {
            if (i + 1 <= a[i])
                ans = i + 1;
        }
        cout << ans << endl;
    }

    return 0;
}