#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int aa = a, bb = b, cc = c;
        int xx1 = min(a, b / 2);
        a -= xx1;
        b -= xx1 * 2;
        xx1 = xx1 * 3;
        xx1 = xx1 + min(b, c / 2) * 3;

        int xx2 = min(bb, cc / 2);
        bb -= xx2;
        cc -= xx2 * 2;
        xx2 = xx2 * 3;
        xx2 = xx2 + min(aa, bb / 2) * 3;

        cout << max(xx1, xx2) << endl;


    }

    return 0;
}
