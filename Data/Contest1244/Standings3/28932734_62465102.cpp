#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int pencils = 0;
        int pens = 0;

        while(a > 0){
            a -= c;
            pens++;
        }

        while(b > 0){
            b -= d;
            pencils++;
        }

        if(pens + pencils > k)
            cout << -1 << endl;
        else
            cout << pens << " " << pencils << endl;
    }
    return 0;
}
