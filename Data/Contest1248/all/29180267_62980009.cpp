#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define ii pair<long long, long long>
#define MOD 998244353LL

int t, n, m;
int tmp;
int oddC, evenC;
int main()
{
    while(cin >> t)
    {
        while(t--)
        {
            cin >> n;
            oddC = evenC = 0;
            for(int i = 0; i < n; i++)
            {
                cin >> tmp;
                if(tmp % 2 == 0)
                    oddC++;
                else
                    evenC++;
            }
            cin >> m;
            ll res = 0;
            for(int i = 0; i < m; i++)
            {
                cin >> tmp;
                if(tmp % 2 == 0)
                    res += oddC;
                else
                    res += evenC;
            }

            cout << res << endl;
        }
    }
    return 0;
}
