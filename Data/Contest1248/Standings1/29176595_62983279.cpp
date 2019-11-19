#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define int long long

using namespace std;

const int N = 300707;
int n;
int a[N];
signed main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("diameter.in", "r", stdin);
    //freopen("diameter.out", "w", stdout);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);

    int big = 0;
    for (int i = n; i > n / 2; i--){
        big += a[i];
    }
    //cout << big << endl;

    cout << (sum - big) * (sum - big) + big * big << endl;

    return 0;
}
