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
char s[10100], t[10100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        cin >> n;
        cin >> s >> t; int diff = 0;
        for (int i=0; i<n; ++i){
            if (s[i] != t[i]) ++diff;
        }
        if (diff != 2) {
            cout << "No\n";
            continue;
        }
        else{
            vi zle;
            for (int i=0; i<n; ++i){
                if (s[i] != t[i]){
                    zle.PB(i);
                }
            }bool xd = 0;
            swap(s[zle[0]],t[zle[1]]);
            for (int i=0; i<n; ++i){
                if (s[i] != t[i]){

                    cout << "No\n";
                    xd = 1;
                    break;
                }
            }
            if (xd) continue;
            else cout << "Yes\n";
        }
    }



}
