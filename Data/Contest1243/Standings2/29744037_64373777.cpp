#include <bits/stdc++.h>

using namespace std;

int q, i, n, sz;
int a[1010];

int main()
{
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(i=1; i<=n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        sz = 0;
        for(i=n; i>=1; i--)
        {
            sz ++;
            if(a[i] < sz) {sz --; break;}
        }
        cout << sz << '\n';
    }
    return 0;
}
