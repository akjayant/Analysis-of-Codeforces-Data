#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int vis[100][100];
int n, m;
int color[100][100];
bool chk()
{
    int ans = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            int cnt = 0;
            if (i) cnt += color[i-1][j] == color[i][j];
            if (j) cnt += color[i][j-1] == color[i][j];
            if (i < n-1) cnt += color[i+1][j] == color[i][j];
            if (j < m-1) cnt += color[i][j+1] == color[i][j];
            ans &= cnt <= 1;
        }
    return ans;
}
ll solve(int x, int y)
{
    if (x == n && y == 0)
    {
        return chk();
    }
    color[x][y] = 1;
    ll ans = 0;
    if (y == m-1)
        ans += solve(x+1, 0);
    else ans += solve(x, y+1);
    color[x][y] = 0;
    if (y == m-1)
        ans += solve(x+1, 0);
    else ans += solve(x, y+1);
    return ans;
}

ll fib[100100];
ll fib2[100100];
int md = 1e9 + 7;

int main(){
    fib[1] = 2;
    fib[2] = 4;
    fib2[1] = 2;
    fib2[2] = 2;
    for (int j = 3 ; j < 100100; ++j)
    {
        fib[j] = fib[j-1] + fib[j-2];
        if (fib[j] >= md)
            fib[j] -= md;
        fib2[j] = fib2[j-1] + fib2[j-2];
        if (fib2[j] >= md)
            fib2[j] -= md;
    }
    for (int j = 2; j < 100100 ; ++j)
    {
        fib2[j] += fib2[j-1];
        if (fib2[j] >= md)
            fib2[j] -= md;
    }
    while (cin >> n >> m )
    {
        if (n > m) swap(n, m);
        cout << (fib[m] + fib2[n-1])%md  << "\n" ;
//        for (int i = 1; i <= 6; ++i)
//            for (int j = 1; j <= 6; ++j)
//        {
//        memset(vis, 0, sizeof vis);
//            n = i; m = j;
//            cout << solve(0, 0) << " \n"[j==6];
//        }
//        cout << solve(0, 0) << endl;
    }

	return 0;
}
