#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
ll a,b,c;
int main() {
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c;
        ll c1=c/2;
        if(b<=c1)
        {
            cout << 3*b << endl;
            continue;
        }
        if(b>c1)
        {
            b-=c1;
            ll b1=b/2;
            if(a<=b1)
            {
                cout << 3*c1+3*a << endl;
                continue;
            }
            if(a>b1)
            {
                cout << 3*c1+3*b1 << endl;
            }
        }
    }
    return 0;
}