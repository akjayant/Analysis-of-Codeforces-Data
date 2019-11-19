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
        int n;
        cin>>n;
        int j = 0;
        string s;
        cin>>s;
        for(int i = 0; i < n; i++)
        {
            bool z = s[i] - '0';
            if(z)
                j = max(j, max(n - i, i + 1));
        }
        cout<<max(j * 2, n)<<endl;
    }
}