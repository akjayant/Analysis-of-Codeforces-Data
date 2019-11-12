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
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define oo 1e15
#define eps 1e-8
#define pow poww
#define int long long

const int N = 1e3 + 5;
int n , q;
int a[N] , ans[N];

bool ok(int mid)
{
    int cnt = 0;
             FOR(i , 1 , n)
                if(a[i] >= mid)
                    cnt++;
    return cnt >= mid;
}

main()
{

    //freopen("task.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        FOR(i , 1 , n)
            cin >> a[i];
        int l = 1 , r = 1000 , res = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(ok(mid))
                res = mid , l = mid + 1;
            else
                r = mid - 1;
        }
        cout << res << "\n";
    }
}

