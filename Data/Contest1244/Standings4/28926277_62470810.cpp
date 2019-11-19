#include<bits/stdc++.h>
#define TASK "ABC"
#define BASIC \
		freopen(TASK".inp", "r", stdin); \
		freopen(TASK".out", "w", stdout);
#define BASE ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define maxn 2002

using namespace std;
typedef long long ll;

int n, t;
char a[maxn];

int main(){
    BASE
    cin >> t;
    while (t--){

        cin >> n;
        int ans = n;
        cin >> a;
        for (int i = 0; i < n; ++i)
            if (a[i] == '1')
            ans = max(ans, max(2 * n - 2 * i, i * 2 + 2));
        cout << ans << '\n';
    }
    return 0;
}
