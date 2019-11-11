#include <bits/stdc++.h>
#define int long long

using namespace std;


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;


    while(n --> 0) {
        int a, b;
        cin>>a>>b;
        if(__gcd(a, b) > 1)
            cout<<"Infinite\n";
        else
            cout<<"Finite\n";

    }
    return 0;
}