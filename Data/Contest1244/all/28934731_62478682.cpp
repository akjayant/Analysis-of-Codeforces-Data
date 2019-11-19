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

ll n, p, w, d;

bool was[100100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> p >> w >> d;

    ll mod = p%w;
    if (mod == 0){
        if (p/w <= n){
            cout << p/w << ' ' << 0 << ' ' << n-(p/w) << endl;
        }
        else cout << -1 << endl;
    }
    else {
    ll ilosc_draw = 1;
        while (!was[( p - (ilosc_draw*d) ) % w] && ilosc_draw*d <= p){

            was[( p - (ilosc_draw*d) ) % w] = 1;

            if (( p - (ilosc_draw*d) ) % w == 0){
                ll ilosc_win = (( p - (ilosc_draw*d) ) / w);
                if (ilosc_draw + ilosc_win <= n){
                    cout << ilosc_win << ' ' << ilosc_draw << ' ' << n - ilosc_win - ilosc_draw << endl;
                    return 0;
                }
            }
            ++ilosc_draw;
        }
        cout << -1 << endl;
        return 0;
    }


}
