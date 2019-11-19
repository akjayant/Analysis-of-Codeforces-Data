#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; i++)
        sum1 += a[i];
    for (int i = n / 2; i < n; i++)
        sum2 += a[i];
    cout << sum1 * sum1 + sum2 * sum2;
    return 0;
}
