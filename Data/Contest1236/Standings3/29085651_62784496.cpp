#include<bits/stdc++.h>

using namespace std;

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;  cin >> t;

    while (t--) {
        int a;  cin >> a;
        int b;  cin >> b;
        int c;  cin >> c;
        int y = min(c / 2,b);   b -= y;
        int x = min(b / 2,a);
        cout << 3 * (x + y) << "\n";
    }
;}