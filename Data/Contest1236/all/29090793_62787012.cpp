#include <iostream>
using namespace std;
int main () {
    int t, a, b, c, ans;
    cin >> t;
    for (int i=0;i<t;i++) {
        cin >> a >> b >> c;
        if (2*b<=c) cout << b*3 << endl;
        else {
            ans=(c/2)*3;
            b-=c/2;
            if (a*2<=b) cout << ans+a*3 << endl;
            else cout << ans+(b/2)*3 << endl;
        }
    }
    return 0;
}
