#include <bits/stdc++.h>
using namespace std;

void run();

signed main(){
    cout.setf(ios::fixed);
    cout.precision(10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

void run(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1) {
            cout << "Finite";
        } else{
            cout << "Infinite";
        }
        cout << '\n';
    }
}




