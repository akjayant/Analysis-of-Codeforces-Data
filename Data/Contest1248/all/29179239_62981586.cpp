#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long x = 0;
    long long y = 0;
    for (long long i = 0; i < n / 2; i++) {
        x += arr[i];
    }
    for (long long i = n / 2; i < n; i++) {
        y += arr[i];
    }
    cout << x * x + y * y;
    return 0;
}
