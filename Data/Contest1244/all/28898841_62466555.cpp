#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int a, b, c, d, i, k;
    for (i = 0; i < t; i ++)
    {
        cin >> a >> b >> c >> d >> k;
        int pen = a / c;
        if (a % c != 0)
            pen ++;
        int pencil = b / d;
        if (b % d != 0)
            pencil ++;
        if (pen + pencil > k)
            cout << "-1" << endl;
        else
            cout << pen << " " << pencil << endl;
    }
    return 0;
}
