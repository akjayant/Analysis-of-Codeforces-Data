#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define DEBUG(X) { cout << #X << " = " << X << endl; }
#define PR(A, n) { cout << #A << " = "; FOR(_, 1, n) cout << A[_] << " "; cout << endl;}

bool f[1005];

int main() {
    int TC; scanf("%d", &TC);
    while (TC--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (__gcd(a, b) > 1) puts("Infinite");
            else puts("Finite");
    }
    return 0;
}

