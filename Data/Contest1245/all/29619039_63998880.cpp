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

int q , a , b;

main()
{
    //freopen("task.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        if(__gcd(a , b) > 1)
            cout << "Infinite" << "\n";
        else
            cout << "Finite" << "\n";
    }
}
