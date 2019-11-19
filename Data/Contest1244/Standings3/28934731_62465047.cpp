/// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

int t, a, b, c, d, x, y, k;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> a >> b >> c >> d >> k;
        bool poss = 0;
        for (int x=0; x<101; ++x){
            for (int y=0; y<101; ++y){
                if (x+y <= k){
                    if (x*c >= a && y*d >= b){
                        poss = 1;
                        cout << x << ' ' << y << endl;
                        break;
                    }
                }
            }
            if (poss) break;
        }
        if (!poss) cout << -1 << endl;
    }


}
