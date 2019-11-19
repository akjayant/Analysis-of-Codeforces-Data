#include <bits\stdc++.h>

#define sc second
#define fr first
#define mk make_pair
#define pb push_back

using namespace std;

const int N = (1e6 + 5);
const int inf = (1e9 + 7);

int t;
int a,b,c,d,k;

main () {
    cin >> t;

    for (int i = 1; i <= t; i ++) {
        cin >> a >> b >> c >> d >> k;

        int cur = (a + c - 1) / c;
        int cr = (b + d - 1) / d;

        if (cur + cr > k) puts("-1");
        else cout << cur << " " << cr << endl;
    }
}
