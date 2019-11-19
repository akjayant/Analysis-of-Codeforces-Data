#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define frac pair<ll, ll>
#define t_trials for (cin >> _; _; _--)
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define N 200005
const ll inf = 1e9 + 7;
ll arr[N];
ll n, m, k, t, t1, t2, t3, t4, t5, t6, _;
ll removed_rows, removed_col;
string s;
bool cr[N], cc[N];
vector<ll> points_in_row[N];
vector<ll> points_in_col[N];
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    t = n * m - k;
    ll x = 1, y = 1, face = 1;
    ll min_visited_col = m + 1;
    ll max_visited_col = 0;
    ll min_visited_row = n + 1;
    ll max_visited_row = 0;
    rep(i, 0, k)
    {
        cin >> t1 >> t2;
        points_in_row[t1].push_back(t2);
        points_in_col[t2].push_back(t1);
    }
    ll ans = true;
    rep(i, 1, n + 1)
    {
        cr[i] = false;
        points_in_row[i].push_back(0);
        points_in_row[i].push_back(m + 1);
        sort(points_in_row[i].begin(), points_in_row[i].end());
    }
    rep(i, 1, m + 1)
    {
        cc[i] = false;
        points_in_col[i].push_back(0);
        points_in_col[i].push_back(n + 1);
        sort(points_in_col[i].begin(), points_in_col[i].end());
    }
    t1 = 1;
    while (1)
    {
        if (face & 1)
        {
            if (cr[x])
            {
                break;
            }
        }
        else
        {
            if (cc[y])
            {
                break;
            }
        }
        if (face == 1)
        {
            t2 = (*upper_bound(points_in_row[x].begin(), points_in_row[x].end(), y));
            t2 = min(min_visited_col, t2) - 1;
            t1 += (t2 - y);
            y = t2;
            cr[x] = true;
            // min_visited_row = min(min_visited_row, x);
            max_visited_row = max(max_visited_row, x);
        }
        if (face == 3)
        {
            t2 = (*(upper_bound(points_in_row[x].begin(), points_in_row[x].end(), y) - 1));
            t2 = max(max_visited_col, t2) + 1;
            t1 += (y - t2);
            y = t2;
            cr[x] = true;
            min_visited_row = min(min_visited_row, x);
            // max_visited_row = max(max_visited_row, x);
        }
        if (face == 2)
        {
            t2 = (*(upper_bound(points_in_col[y].begin(), points_in_col[y].end(), x)));
            t2 = min(min_visited_row, t2) - 1;
            t1 += (t2 - x);
            x = t2;
            cc[y] = true;
            min_visited_col = min(min_visited_col, y);
            // max_visited_col = max(max_visited_col, y);
        }
        if (face == 4)
        {
            t2 = (*(upper_bound(points_in_col[y].begin(), points_in_col[y].end(), x) - 1));
            t2 = max(max_visited_row,t2) + 1;
            t1 += (x - t2);
            x = t2;
            cc[y] = true;
            // min_visited_col = min(min_visited_col, y);
            max_visited_col = max(max_visited_col, y);
        }
        // cout << x << " " << y << " " << t1 << endl;
        face++;
        if (face == 5)
        {
            face = 1;
        }
    }

    if (t1 == t)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}