#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int q;
    cin >> q;

    while(q--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int to1 = (a + c - 1) / c, to2 = (b + d - 1) / d;
        if(to1 + to2 <= k){
            cout << to1 << ' ' << to2 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}
