#include <bits/stdc++.h>

#define int long long
typedef long long ll;
using namespace std;

int cal(int a, int b) {
    if (a % b == 0)return a / b;
    return a / b + 1;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = cal(a, c);
        int y = cal(b, d);
        if(x+y>k)cout<<-1<<endl;
        else cout<<x<<" "<<y<<endl;
    }
}