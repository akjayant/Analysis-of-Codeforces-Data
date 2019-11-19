#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define int long long

using namespace std;
const int N = 100777;
int a, b, c, d, k;

int dif(int a, int b){
    if (a % b == 0){
        return a/b;
    }
    else {
        return a/b + 1;
    }
}

signed main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("diameter.in", "r", stdin);
    //freopen("diameter.out", "w", stdout);
    int t;

    cin >> t;
    for (int i = 1; i <= t; i++){
        cin >> a >> b >> c >> d >> k;
        int a1 = dif(a, c);
        int a2 = dif(b, d);
        if (a1 + a2 <= k){
            cout << a1 << " " << a2 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}
