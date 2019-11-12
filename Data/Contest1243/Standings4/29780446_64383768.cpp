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
string s1 , s2;
vector < int > g[N];

main()
{

    //freopen("task.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        cin >> s1;
        cin >> s2;
        int y = 0;
        int x = 0;
        FOR(i , 1 , 256)
            g[i].clear();
        REP(i , s1.size())
            g[s1[i]].pb(i);
        REP(i , s2.size())
        {
            if(s1[i] != s2[i])
            {
                REP(s , g[s1[i]].size())
                {
                    int j = g[s1[i]][s];
                    if(i != j && s1[j] == s1[i] && s2[i] == s2[j])
                    {
                        swap(s1[i] , s2[j]);
                        goto l2;
                    }
                }
            }
        }
        l2:;
        REP(i , s2.size())
            if(s1[i] != s2[i])
            {
                cout << "NO" << "\n";
                goto l1;
            }
        cout << "YES" << "\n";
        l1:;
    }
}

