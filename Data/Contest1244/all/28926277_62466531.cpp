#include<bits/stdc++.h>
#define TASK "ABC"
#define BASIC \
		freopen(TASK".inp", "r", stdin); \
		freopen(TASK".out", "w", stdout);
#define BASE ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define maxn 200001

using namespace std;
typedef long long ll;

int main(){
    BASE
    int t;
    cin >> t;
    while (t--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ret = (a + c - 1) / c, res = (b + d - 1) / d;
        if (ret + res > k) cout << -1;
        else cout << ret << ' ' << k - ret;
        cout << '\n';
    }
    return 0;
}
