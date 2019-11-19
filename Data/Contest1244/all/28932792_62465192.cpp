#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
const int ms = 1e5 + 10;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ra = 0, rb = 0;
        ra += a / c;
        rb += b / d;
        ra += a % c != 0;
        rb += b % d != 0;
        if (ra + rb > k)
        {
            cout << -1 << "\n";

        }
        else
            cout << ra << " " << rb << "\n";
    }
    return 0;
}
