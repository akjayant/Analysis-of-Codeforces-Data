#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int na = a / c + (a % c != 0);
        int nb = b / d + (b % d != 0);
        if(na + nb <= k){
            cout << na << " " << nb << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}
