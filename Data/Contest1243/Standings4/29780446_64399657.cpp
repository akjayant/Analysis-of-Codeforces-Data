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
int n , res;

main()
{

    //freopen("task.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int res = n;
    FOR(i , 2 , sqrt(n))
        if(n % i == 0)
        {
            int j = n / i;
            res = __gcd(res , i);
            if(i != j)
                res = __gcd(res , j);
        }
    cout << res;
}

