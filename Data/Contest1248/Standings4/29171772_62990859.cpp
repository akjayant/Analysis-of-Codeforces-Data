#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a[N];

int main(){
    cin >> n;
    long long d1 = 0, d2 = 0, sum = 0 ;
    for(int i = 0; i < n; i++)
        scanf("%d", a + i), sum +=a[i];

    sort(a, a + n);
    for(int i = 0; i < n / 2; i++)
        d1 += a[i];
    d2 = sum - d1;
    cout << d1 * d1 + d2*d2;
}