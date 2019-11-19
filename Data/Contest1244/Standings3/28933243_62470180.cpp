#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ans = n;

        for(int i=1;i<=n;i++)
        {
            if(s[i-1] == '1')
            {
                ans = max(ans,2*i);
                ans = max(ans,2*(n-i+1));
            }
        }

        cout << ans << endl;
    }
}