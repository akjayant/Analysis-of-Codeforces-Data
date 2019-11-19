#include <bits/stdc++.h>

using namespace std;

long long a[200000];

int main() {
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long l = 1, r = n, sum = 0, sumH = 0;
    for (int i = 1; i <= n / 2; i++) {
        sum += a[r];
        sumH += a[l];
        r--;
        l++;
    }
    if (n % 2 == 1) {
        sum += a[n / 2 + 1];
    }
    cout << sum * sum + sumH * sumH;
}
