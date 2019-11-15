#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;

int f(int a,int b)
{
    while(a!=0)
    {
        b%=a;
        swap(a,b);
    }
    return b;
}

int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        int a,b,c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        vector<bool> g(n,false);
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R' && b !=0)
            {
                b--;
                s[i] = 'P';
                g[i] = true;
            }
            else
            if(s[i] == 'P' && c !=0)
            {
                c--;
                s[i] = 'S';
                g[i] = true;
            }
            else
            if(s[i] == 'S' && a !=0)
            {
                a--;
                s[i] = 'R';
                g[i] = true;
            }
        }
        int r = 0;
        for(int i=0;i<n;i++)
        {
            if(!g[i])
            {
                if(a>0)
                {
                    s[i] = 'R';
                    a--;
                }
                else if(b > 0)
                {
                    s[i] = 'P';
                    b--;
                }
                else
                {
                    s[i] = 'S';
                    c--;
                }
            }
            else
            {
                r++;
            }
        }
     //   cout << ":" << s << '\n';
        if(r >= (n+1)/2)
        {
            cout << "Yes\n" << s << '\n';
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
