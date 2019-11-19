#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[5];
int main()
{
    int T;  cin >> T;
    while(T--)
    {
        for(int i = 0 ; i < 5 ; i++)    cin >> a[i];

        int x = (a[0] + a[2] - 1) / a[2];
        int y = (a[1] + a[3] - 1) / a[3];
        if(x + y > a[4]) cout << "-1\n";
        else          cout << x << ' ' << y << endl;
    }
    return 0;
}
