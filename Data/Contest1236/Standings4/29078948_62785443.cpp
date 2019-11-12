#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x = min(b, c/2);
        b -= x;
        int y = min(a, b/2);
        cout << (x+y)*3 << endl;
    }
}
