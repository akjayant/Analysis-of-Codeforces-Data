#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int ans[400][400];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int i,n,x,y,j;
    cin >> n;
    x = 1; y = 1;
    bool d = true;
    for (i = 1; i <= n * n; i++)
    {
        ans[x][y] = i;
        if (d && x == n)
        {
            y++;
            d = false;
        }
        else
            if (!d && x == 1)
            {
                y++;
                d = true;
            }
            else
                if (d)
                    x++;
                else
                    x--;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}

