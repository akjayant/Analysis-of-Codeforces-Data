#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    int t,a,b,c,d,k;
    cin >> t;
    for(int u = 0; u < t; u++)
    {
        cin >> a >> b >> c >> d >> k;
        long long h = (a + c -1)/c;
        long long y = (b + d- 1 )/d;
        if(h + y > k)
            cout << -1 << endl;
        else
            cout << h << ' ' << y << endl;
    }
}
