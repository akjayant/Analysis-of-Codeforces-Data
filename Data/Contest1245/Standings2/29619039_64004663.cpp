#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back


#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long
#define eps 1e-8

const int N = 1e6 + 5;
const int VAL = log2(VAL) + 2;

int q , b , n;
char ans[N];
int a[N];
char f[N];

main()
{
    //freopen("task.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        FOR(i , 1 , 3)
            cin >> a[i];
        FOR(i , 1 , n)
            ans[i] = 0;
        int cnt = 0;
        int x = n / 2 + (n % 2 != 0);
        FOR(i , 1 , n)
        {
            cin >> f[i];
            if(f[i] == 'R' && a[2] >= 1)
            {
                cnt++;
                a[2]--;
                ans[i] = 'P';
            }
            else if(f[i] == 'P' && a[3] >= 1)
            {
                cnt++;
                a[3]--;
                ans[i] = 'S';
            }
            else if(f[i] == 'S' && a[1] >= 1)
            {
                cnt++;
                a[1]--;
                ans[i] = 'R';
            }
        }
        if(cnt >= x)
        {
            cout << "YES" << "\n";
            FOR(i , 1 , n)
            {
                if(ans[i] != 0)
                    cout << ans[i];
                else
                {
                    if(a[1] >= 1)
                    {
                        a[1]--;
                        cout << "R";
                    }
                    else if(a[2] >= 1)
                    {
                        a[2]--;
                        cout << "P";
                    }
                    else if(a[3] >= 1)
                    {
                        a[3]--;
                        cout << "S";
                    }
                }
            }
            cout << "\n";
        }
        else
            cout << "NO" << "\n";
    }
}
