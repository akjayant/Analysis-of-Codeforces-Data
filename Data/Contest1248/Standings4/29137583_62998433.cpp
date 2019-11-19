/****************************/
/** Author : thantrongtri3 **/
/****************************/
#include <bits/stdc++.h>

using namespace std;

#define fuv(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define name ""

typedef pair<int, int> pii;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int INF = 1e9;
const int MOD = 1e9+7;
const int N = 1e5+10;

long long s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUGDE

    int n, m;
    cin >> n >> m;
    s[1] = 2;
    s[2] = 4;
    for(int i = 3; i <= max(m, n); i++){
        s[i] = s[i-1] + s[i-2];
        s[i] %= MOD;
    }



    long long res = s[n] + s[m];
    res -= 2;
    res += MOD;
    cout << res % MOD;
    return 0;
}
