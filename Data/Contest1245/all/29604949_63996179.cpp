#include <bits/stdc++.h>
using namespace std;
#define int long long

int evc(int a, int b){
    while (a != 0){
        b %= a;
        swap(a, b);
    }
    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        if (evc(a, b) > 1)
            cout << "Infinite\n";
        else
            cout << "Finite\n";
    }
    return 0;
}
