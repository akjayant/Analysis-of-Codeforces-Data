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

int t, n;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n;
        cin >> s;

        int L = 10000;
        for (int i=0; i<n; ++i){
            if (s[i] == '1'){
                L = i;
                break;
            }
        }
        int R = -1;
        for (int i=n-1; i>=0; --i){
            if (s[i] == '1'){
                R = i;
                break;
            }
        }
        if (L == 10000 && R == -1){
            cout << n << endl;
            continue;
        }
        else {
            cout << max(2*(n-L),2*(R+1)) << endl;
        }
    }


}
