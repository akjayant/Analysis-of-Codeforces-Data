// ml:run = $bin < input
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    int len = max(n, m);
    vector<long long> v(len + 10, 0);
    v[1] = 1;
    v[2] = 2;
    for (int i = 3; i <= len; ++i)
        v[i] = (v[i-1] + v[i-2]) % 1000000007;
    long long res = ((v[n] + v[m] - 1) * 2);
    res %= 1000000007;
    cout << res << '\n';
}