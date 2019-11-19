#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,p,w,d;
    cin >> n >> p >> w >> d;
    ll tmp = p % w;
    ll x,y,z;
    bool flag = false;
    for(y = 0;y <= w; ++y)
    {
        ll tw = y * d % w;
        if(tw == tmp)
        {
            x = (p - y * d) / w;
            z = n - x - y;
            if(x >= 0 && y >= 0 && z >= 0)
            {
                flag = true;
                break;
            }
        }
    }
    if(flag)
        cout << x << " " << y << " " << z << endl;
    else
    {
        cout << "-1" << endl;
    }
    
    return 0;
}