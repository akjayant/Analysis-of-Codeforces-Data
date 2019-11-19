#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n,q,oddl=0,evenl=0,oddr=0,evenr=0;
        cin >> n;
        for (int i = 1; i<=n; i++)
        {
            int p;
            cin >> p;
            if (p%2)
                oddl++;
            else
                evenl++;
        }
        cin >> q;
        for (int i = 1; i<=q; i++)
        {
            int p;
            cin >> p;
            if (p%2)
                oddr++;
            else
                evenr++;
        }
        cout << oddl*oddr+evenl*evenr << "\n";
    }
}
