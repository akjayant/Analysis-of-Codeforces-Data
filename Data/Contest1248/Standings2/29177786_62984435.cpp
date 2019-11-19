#include<iostream>
#include<cstring>
using namespace std;

int t, n, m, a, b;
int main()
{
    cin >> t;
    for(int i = 1; i <= t; i ++)
    {
        cin >> n;
        long long c1[2] = {0}, c2[2] = {0};
        for(int j = 1; j <= n; j ++)
        {
            cin >> a;
            c1[a % 2] ++;
        }
        cin >> m;
        for(int j = 1; j <= m; j ++)
        {
            cin >> b;
            c2[b % 2] ++;
        }
        long long sum = c1[0] * c2[0] + c2[1] * c1[1];
        cout << sum << endl;
    }
}