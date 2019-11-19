#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e6;
signed main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        int g1 = (a - 1) / c + 1;
        int g2 = (b - 1) / d + 1;
        if(g1 + g2 <= k)
        {
            cout<<g1<<" "<<g2<<endl;
        }
        else
            cout<<-1<<endl;
    }
}