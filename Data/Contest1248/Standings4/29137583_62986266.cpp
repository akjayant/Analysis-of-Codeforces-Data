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

int a[N];
long long sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUGDE

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a+1, a+1+n, greater<int>());
    long long s = 0;
    for(int i = 1; i <= n/2+(n&1); i++){
        s += a[i];
    }

    long long res = s*s;
    s = sum - s;
    res += s*s;
    cout << res;
    return 0;
}
