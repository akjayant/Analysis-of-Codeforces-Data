#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100003;

int n;
long long k, a[MAXN];
void read()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

long long prefix_sum[MAXN], suffix_sum[MAXN];
void solve()
{
    sort (a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
        prefix_sum[i] = prefix_sum[i-1] + a[i];

    for (int i = n; i >= 1; i--)
        suffix_sum[i] = suffix_sum[i+1] + a[i];

    long long ans = 1000000000000000;
    for (int i = 1; i <= n; i++)
    {
        long long left = k - (i * a[i] - prefix_sum[i]);

        if (left < 0)
            continue;

        long long low = a[i], high = 1000000000;

        while (low < high)
        {
            long long mid = (low + high) / 2;

            int idx = lower_bound(a + 1, a + n + 1, mid) - a;
            long long cost;

            if (idx == n + 1)
                cost = 0;

            else
                cost = suffix_sum[idx] - (n - idx + 1) * mid;

            if (cost <= left)
                high = mid;

            else
                low = mid + 1;
        }

        ans = min(ans, low - a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        long long left = k - (suffix_sum[i] - (n - i + 1) * a[i]);

        if (left < 0)
            continue;

        long long low = 1, high = a[i];

        while (low < high)
        {
            long long mid = (low + high + 1) / 2;

            int idx = upper_bound(a + 1, a + n + 1, mid) - a;
            idx--;

            long long cost;
            if (idx < 1)
                cost = 0;

            else
                cost = idx * mid - prefix_sum[idx];

            if (cost <= left)
                low = mid;

            else
                high = mid - 1;
        }
        ans = min(ans, a[i] - low);
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();
}

