#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int i;
    for (i = 0; i < t; i++) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;
        if (x + y > k) {
            cout << -1 << endl;
        }
        else {
            cout << x << " " << y << endl;
        }
    }
}
