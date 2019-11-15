#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e6;
signed main() {
    int q;
    cin>>q;
    while(q--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int cnt = 0;
        while(c > 1 && b > 0)
        {
            c-=2, b--;
            cnt += 3;
        }
        while(a > 0 && b > 1)
        {
            b -= 2, a--;
            cnt += 3;
        }
        cout<<cnt<<endl;
    }
}