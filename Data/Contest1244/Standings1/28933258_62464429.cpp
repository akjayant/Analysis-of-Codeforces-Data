#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int pen = (a-1) / c + 1;
        int cil = (b-1) / d + 1;
        if(pen + cil <= k)
            cout << pen << " " << cil;
        else
            cout << -1;
        cout << endl;
    }
    return 0;
}
