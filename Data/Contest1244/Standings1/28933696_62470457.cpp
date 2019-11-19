#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    int t;
    int n;
    cin >> t;
    for(int u = 0; u < t; u++)
    {
        cin >> n;
        string s;
        cin >> s;
        long long r =-1;
        long long l =-1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1'){
                r = i;
                if(l == -1)
                    l = i;
            }
        }
        r = (int)s.size() - 1 - r;
        if(l == -1)
            cout << n << endl;
        else
            cout << 2*n - 2*min(l,r) << endl;
    }
}
