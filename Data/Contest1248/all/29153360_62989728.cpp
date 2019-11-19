// CF B
// DeP
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 1e5+5;

int n;
int A[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", A+i);
    sort(A+1, A+1+n);
    int Mid = n / 2;
    LL Sum1 = 0, Sum2 = 0;
    for (int i = 1; i <= Mid; ++i) Sum1 += A[i];
    for (int i = Mid+1; i <= n; ++i) Sum2 += A[i];
    cout << Sum1 * Sum1 + Sum2 * Sum2 << endl;
    return 0;
}
