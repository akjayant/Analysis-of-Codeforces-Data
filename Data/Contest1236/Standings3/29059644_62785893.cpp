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

int t,a,b,c,temp,res;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int A, B, C;
        res = 0;
        for (int i=0; i<=a; ++i){
            A=a; B=b; C=c; temp = 0;
            for (int j=0; j<i; ++j){
                if (A<1 || B<2) break;
                A -= 1;
                B -= 2;
                temp += 3;
            }
            for (int j=0; j<=b; ++j){
                if (B<1 || C<2) break;
                B -= 1;
                C -= 2;
                temp += 3;
            }
            res = max(res,temp);
        }
        cout << res << endl;
    }

}
