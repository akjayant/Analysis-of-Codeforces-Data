#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t , a , b , c , d , k , z1 , z2;
    cin >> t;
    while(t--){
        z1 = 0; z2 = 0;
        cin >> a >> b >> c >> d >> k;
        z1 = a / c;
        z2 = b / d;
        if((a % c > 0)) z1++;
        if((b % d > 0)) z2++;
        if(z1 + z2 > k) cout << -1 << endl;
            else cout << z1 << " " << z2 << endl;
    }
    return 0;
}
