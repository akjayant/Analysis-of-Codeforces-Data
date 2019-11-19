#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[5];
int main()
{
    int T;  cin >> T;
    while(T--)
    {
        int n; string s;    cin >> n >> s;
        int first = - 1, last;
        for(int i = 0 ; i < n ; i++) if(s[i] == '1')
        {
            if(first == -1) first = i;
            last = i;
        }

        int ans = n;
        if(first != -1)
        {
            ans = max(ans , 2*(n-first));
            ans = max(ans , 2*(last + 1));
        }
        cout << ans << endl;
    }
    return 0;
}
