#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

long long GCD(long long m,long long n){
    if(n == 0) return m;
    else return GCD(n,m % n);
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(GCD(a, b) == 1){
            cout << "Finite" << endl;
        }else{
            cout << "Infinite" << endl;
        }
    }
    return 0;
}