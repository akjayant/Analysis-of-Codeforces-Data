#include <bits/stdc++.h>

using namespace std;
int a[1001];
int main()
{
    int k;
    cin >> k;
    while(k --)
    {
        char a1 , a2 , a3 , a4;
        int n , j = 0;
        cin >> n;
        string s1 , s2;
        cin >> s1 >> s2;
        if(s1 == s2)
        {
            cout << "Yes\n";
            continue;
        }
        int cnt = 0;
        for(int i = 0; i < n; i ++)
        {
            if(s1[i] == s2[i])
            {
                cnt ++;
            }
            else
            {
                if(j == 0)
                {
                    a1 = s1[i];
                    a2 = s2[i];
                    j ++;
                }
                else if(j == 1)
                {
                    a3 = s1[i];
                    a4 = s2[i];
                    j ++;
                }
            }
        }
        if(cnt < n - 2 || cnt == n - 1)
        {
            cout << "No\n";
            continue;
        }
        if(a1 == a3 && a2 == a4)
        {
            cout << "Yes\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
