#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, p, d, w;

int main()
{
    cin >> n >> p >> w >> d;
    ll tmp = p % w;
    ll y;
    ll x, z;
    bool f = false;
    for(y = 0; y <= w; y++){
        ll st = y * d % w;
        if(st == tmp){
            x = (p - y * d) / w;
            z = n - x - y;
            if(x >= 0 && y >= 0 && z >= 0){
                f = true;
                break;
            }
        }
    }
    if(f){
        cout << x << " " << y << " " << z << endl;
    }
    else{
        cout << -1 << endl;
    }
}
