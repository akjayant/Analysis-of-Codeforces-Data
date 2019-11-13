#include<bits/stdc++.h>

using namespace std;

int main()  {
    int t;  cin >> t;

    while (t--) {
        int a;  cin >> a;
        int b;  cin >> b;
        if (__gcd(a,b) == 1)
            cout << "Finite\n";
        else
            cout << "Infinite\n";
    }
}
