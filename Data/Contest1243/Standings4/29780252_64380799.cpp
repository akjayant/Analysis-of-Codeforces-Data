#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 1000000007
#define INF 1000000000
#define MX 300010
#define pi 2.0*acos(0.0)

typedef pair<int, int> PII;

int n;
int ara[1010], cnt[1010];

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    int tc;
    cin >> tc;
    FOR(tt, 1, tc)   {
        MEM(cnt, 0);

        cin >> n;
        FOR(i, 0, n - 1)   {
            cin >> ara[i];
            cnt[ ara[i] ]++;
        }

        int ans = 0;
        ROF(i, n, 1)   {
            cnt[i] += cnt[i + 1];
            if(cnt[i] >= i)    {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
