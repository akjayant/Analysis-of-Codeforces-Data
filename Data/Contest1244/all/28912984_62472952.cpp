#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        int n;
        cin >> n >> s;
        int p = 0, q = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')p++;
            else q++;
        }
        if(p==n)
        {
            cout << n << "\n";
            continue;
        }
        for(int i=0,j=n-1;i<=(n-1)/2;i++,j--)
        {
            if(s[i]=='1' || s[j]=='1')
            {
                cout << 2*(n-i) << "\n";
                break;
            }
        }
    }
    return 0;
}
