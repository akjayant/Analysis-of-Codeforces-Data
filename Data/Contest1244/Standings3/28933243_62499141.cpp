#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
    int n,k;
    cin >> n >> k;

    set <int> s;
    map <int,int> m;

    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;

        s.insert(x);
        m[x]++;
    }

    while(k > 0 && s.size() > 1)
    {
        int x,y;
        x = *s.begin();
        y = *(++s.begin());

        int a,b;
        a = *s.rbegin();
        b = *(++s.rbegin());

        if(k < m[x] && k < m[a])
            break;
        else if(k >= m[x] && k < m[a])
        {
            if(k <= m[x]*(y-x))
            {
                int cnt = k/m[x];
                cout << a - x - cnt << endl;
                return 0;
            }
            else
            {
                m[y] += m[x];
                s.erase(x);
                k -= m[x]*(y-x);
            }
        }
        else if(k < m[x] && k >= m[a])
        {
            if(k <= m[a]*(a-b))
            {
                int cnt = k/m[a];
                cout << a - x - cnt << endl;
                return 0;
            }
            else
            {
                m[b] += m[a];
                s.erase(a);
                k -= m[a]*(a-b);
            }
        }
        else
        {
            if(m[x] > m[a])
            {
                if(k <= m[a]*(a-b))
                {
                    int cnt = k/m[a];
                    cout << a - x - cnt << endl;
                    return 0;
                }
                else
                {
                    m[b] += m[a];
                    s.erase(a);
                    k -= m[a]*(a-b);
                }
            }
            else
            {
                if(k <= m[x]*(y-x))
                {
                    int cnt = k/m[x];
                    cout << a - x - cnt << endl;
                    return 0;
                }
                else
                {
                    m[y] += m[x];
                    s.erase(x);
                    k -= m[x]*(y-x);
                }
            }
        }
    }

    cout << *s.rbegin() - *s.begin() << endl;
}