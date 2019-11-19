#include <bits/stdc++.h>
using namespace std;

long long n;
vector <long long> divPrimi;

void getDivPrimi(long long n)
{
    for (long long d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
            divPrimi.push_back(d);
        while (n % d == 0)
            n /= d;
    }
    if (n > 1)
        divPrimi.push_back(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    getDivPrimi(n);


    if (divPrimi.size() == 1) // un div prim
        cout << divPrimi[0];
    else
        cout << 1;

    return 0;
}