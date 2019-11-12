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

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        cin >> n;
        vi tab; int x;
        for (int i=0; i<n; ++i){
            cin >> x;
            tab.PB(x);
        } sort(ALL(tab));
        reverse(ALL(tab));
        int res = 0;
        for (int i=0; i<n; ++i){
            if (tab[i] >= i+1) res = i+1;
        }
            cout << res << endl;

    }



}
