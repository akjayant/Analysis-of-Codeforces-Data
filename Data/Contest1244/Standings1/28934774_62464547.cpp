#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN.txt", "r", stdin);
    //freopen("OUT.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;
        if(x + y > k){
            cout << "-1\n";
        }
        else {
            cout << x << " " << y << "\n";
        }
    }


    return 0;
}
