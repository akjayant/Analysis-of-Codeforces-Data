#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;
        if(__gcd(a, b) == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }
}
