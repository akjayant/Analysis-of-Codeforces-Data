#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios::sync_with_stdio(false);
    int T;cin >> T;
    while (T--)
    {
        long long c1[2] = {0,0},c2[2] = {0,0};
        int n,tmp;
        cin >> n;
        for (int i = 1;i <= n;i++) cin >> tmp,c1[tmp & 1]++;
        cin >> n;
        for (int i = 1;i <= n;i++) cin >> tmp,c2[tmp & 1]++;
        cout << c1[0] * c2[0] + c1[1] * c2[1] << endl;
    }
    return 0;
}