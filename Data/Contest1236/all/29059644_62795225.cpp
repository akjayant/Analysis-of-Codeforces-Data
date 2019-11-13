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
int tab[400][400];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i+=2){
        for(int j=1; j<=n; ++j){
            tab[i][j] = i*n + j;
        }
    }
    for (int i=1; i<n; i+=2){
        for(int j=1; j<=n; ++j){
            tab[i][j] = (i+1)*n - j + 1;
        }
    }

    for (int j=1; j<=n; ++j){
        for (int i=0; i<n; ++i){
            cout << tab[i][j] << ' ';
        } cout << endl;
    }

}
