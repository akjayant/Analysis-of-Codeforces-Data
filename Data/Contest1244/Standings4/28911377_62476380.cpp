#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e6+10;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int a,b,c,d,k; cin >> a >> b >> c >> d >> k;
        int ans = (a+c-1)/c+(b+d-1)/d;
        if(ans <= k) {
            int u = (a+c-1)/c;
            cout << u << " " << k - u << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}