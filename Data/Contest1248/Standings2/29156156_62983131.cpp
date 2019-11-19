// in the name of holy satan
#include <bits/stdc++.h>
using namespace std;
const int mMain = 1e5 + 100;
typedef long long lint;

lint arr[mMain];

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;
    lint sum = 0;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    lint s = 0;
    for (int i = 0; i < n / 2; i++)
    {
        s += arr[i];
    }
    sum -= s;
    cout << s * s + sum * sum;
}