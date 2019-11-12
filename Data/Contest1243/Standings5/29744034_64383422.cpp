#include <bits/stdc++.h>
#define INF 1e18
#define M 1000000007
#define ll long long
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        bool ans = true;
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        if(s == t)
        {
            cout << "Yes" << endl;
        }
        else
        {
            int a = -1, b = -1;
            for(int i = 0; i < n; i++)
            {
                if(s[i] != t[i])
                {
                    if(a == -1)
                    {
                        a = i;
                    }
                    else
                    {
                        b = i;
                        break;
                    }
                }
            }
            if(b == -1)
            {
                cout << "No" << endl;
            }
            else
            {
                char c1 = t[b];
                char c2 = s[a];
                s[a] = c1;
                t[b] = c2;
                if(s == t)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }
    }
}