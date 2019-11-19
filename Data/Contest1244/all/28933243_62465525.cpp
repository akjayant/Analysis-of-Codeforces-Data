#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;

        int cnt = (a+c-1)/c + (b+d-1)/d;

        if(cnt > k)
            cout << -1 << endl;
        else
            cout << (a+c-1)/c << " " << (b+d-1)/d << endl;
    }
}