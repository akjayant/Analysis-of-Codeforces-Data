#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
int t,n,pos1,pos2;
char s[maxn];
int main()
{
    cin>>t;
    while (t--)
    {
        cin>>n;
        cin>>s;
        pos1 = pos2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                pos1 = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                pos2 = i;
                break;
            }
        }
        if (pos1 == pos2)
        {
            if (pos1 == -1)cout<<n<<endl;
            else cout<<max(pos1 + 1, n - pos2) * 2<<endl;
        }
        else cout<<max(pos1 + (pos2 - pos1 + 1), n - pos2 - 1 + (pos2 - pos1 + 1)) * 2<<endl;
    }
    return 0;
}
