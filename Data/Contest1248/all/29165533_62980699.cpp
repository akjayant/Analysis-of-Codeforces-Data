#include <iostream>
#include <algorithm>

using namespace std;

int n, v[100005];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> v[i];

    sort(v + 1, v + n + 1);

    long long oy = 0LL, ox = 0LL;

    for(int i = 1; i <= n; i++)
    {
        if(i <= n / 2)
            oy += 1LL * v[i];
        else
            ox += 1LL * v[i];
    }

    cout << ox * ox + oy * oy;

    return 0;
}
