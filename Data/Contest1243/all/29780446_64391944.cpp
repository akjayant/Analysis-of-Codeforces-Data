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
int cnt[N];
char f1[N] , f2[N];
vector < ii > ans;

main()
{

    //freopen("task.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        ans.clear();
        cin >> n;
        FOR(i , 1 , 256)
            cnt[i] = 0;
        FOR(i , 1 , n)
        {
            cin >> f1[i];
            cnt[f1[i]]++;
        }
        FOR(i , 1 , n)
        {
            cin >> f2[i];
            cnt[f2[i]]++;
        }
        FOR(i , 1 , 256)
            if(cnt[i] % 2 == 1)
            {
                cout << "No" << "\n";
                goto l1;
            }
        cout << "Yes" << "\n";
        FOR(i , 1 , n - 1)
        {
            int x = f1[i];
            bool ok = false;
            for(int j = i + 1 ; j <= n ; j++)
                if(f1[i] == f1[j])
                {
                    ans.pb(ii(j , i));
                    swap(f2[i] , f1[j]);
                    ok = true;
                    break;
                }
            if(!ok)
            {
                for(int j = i ; j <= n ; j++)
                    if(f1[i] == f2[j])
                {
                    ans.pb(ii(n , j));
                    ans.pb(ii(n , i));
                    swap(f2[j] , f1[n]);
                    swap(f1[n] , f2[i]);
                    break;
                }
            }
        }
        cout << ans.size() << "\n";
        REP(s , ans.size())
            cout << ans[s].fi << " " << ans[s].se << "\n";
        l1:;
    }
}

