#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k;
    int n, t, m;
    cin >> n;
    while(n--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if(__gcd(u, v) > 1) {
            puts("Infinite");
        }
        else {
            puts("Finite");
        }
    }
    return 0;
}
