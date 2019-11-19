// ml:run = $bin < input
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    long long part = 0;
    for (int i = 0; i < n/2; ++i)
        part += v[i];
    long long res = part * part + (sum - part) * (sum - part);
    cout << res << '\n';
}

