#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll = long long;
using pii = pair<int,int>;
int n;ll kk;
pii a[N];map<int,int> mp;
int main ()
{
    ios::sync_with_stdio(false);
    cin >> n >> kk;
    for (int i = 1;i <= n;i++)
    {
        int tmp;cin >> tmp;++mp[tmp];
    }
    int l = 1,r = 0;
    for (auto &i : mp) a[++r] = i;
    int lc = a[l].second,rc = a[r].second,
            lnum = a[l].first,rnum = a[r].first;
    while (l != r && kk)
    {
        if (lc < rc)
        {
            ll tmp = kk / lc;
            if (a[l].first + tmp >= a[l + 1].first)
            {
                tmp = a[l + 1].first - a[l].first;kk -= tmp * lc;
                ++l;lc += a[l].second;lnum = a[l].first;
            }
            else
            {
                lnum += tmp;break;
            }
        }
        else
        {
            ll tmp = kk / rc;
            if (a[r].first - tmp <= a[r - 1].first)
            {
                tmp = a[r].first - a[r - 1].first;kk -= tmp * rc;
                --r;rc += a[r].second;rnum = a[r].first;
            }
            else
            {
                rnum -= tmp;break;
            }
        }
    }
    cout << rnum - lnum << endl;
    return 0;
}