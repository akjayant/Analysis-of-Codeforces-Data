#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
vector <long long> a;
vector <pair <long long, int> > b;

int main()
{
    long long n, k;
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    for(int i= 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
        b[i] = {a[i], 1};
    int l = 0;
    int r = n - 1;
    long long dist = b[n-1].first - b[0].first;
    while(dist > 0 && k > 0)
    {
        //cout << dist <<' ' << k <<endl;
        long long l_dist = b[l + 1].first - b[l].first;
        long long r_dist = b[r].first - b[r - 1].first;
        if(b[l].second >= b[r].second)
        {
            if(k >= r_dist * b[r].second)
            {
                b[r - 1].second += b[r].second;
                k -= r_dist * b[r].second;
                dist = b[r-1].first - b[l].first;
                r--;
            }
            else
            {
                long long p = k / (b[r].second);
                dist = dist - p;
                k = 0;
            }
        }
        else
        {
            if(k >= l_dist * b[l].second)
            {
                b[l + 1].second += b[l].second;
                k -= l_dist * b[l].second;
                dist = b[r].first - b[l + 1].first;
                l++;
            }
            else
            {
                long long p = k / (b[l].second);
                dist = dist - p;
                k = 0;
            }
        }
    }
    cout << dist;
}
