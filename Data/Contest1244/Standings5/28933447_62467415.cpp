#include <bits/stdc++.h>
using namespace std;

int t;
int main()
{
    cin >> t;
    while(t--)
    {
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        int x = a % c == 0 ? a / c : a / c + 1;
        int y = b % d == 0 ? b / d: b / d + 1;
      //  cout << x  << " " << y << endl;
        if(x + y > k)
            cout << "-1" << endl;
        else 
        cout << x << " " << y << endl;
    }
    return 0;
}