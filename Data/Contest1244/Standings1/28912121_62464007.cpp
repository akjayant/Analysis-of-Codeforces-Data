# include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    cin >> t;

    while (t --){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int f, s;
        f = (a + c - 1) / c, s = (b + d - 1) / d;
        if (f + s <= k)
            cout << f << " " << s << endl;
        else
            cout << -1 << endl;
    }
}
