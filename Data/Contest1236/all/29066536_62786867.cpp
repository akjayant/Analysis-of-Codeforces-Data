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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int i,n,ans = 0,a,b,c;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        ans = 0;
        for (i = 0; i <= min(a, b / 2); i++)
            ans = max(ans, 3 * i + min(b - 2 * i, c / 2) * 3);
        cout << ans << '\n';
    }
    return 0;
}
