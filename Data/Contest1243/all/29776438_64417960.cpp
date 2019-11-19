#include <bits/stdc++.h>

using namespace std;
#define intMax 1e18
#define rep(i, a, b) for (long long i = a; i < b; i++)
#define repp(i, a, b) for (long long i = a; i >= b; i--)
#define be(a) (a.begin(), a.end())
#define rbe(p) (p.rbegin(), p.rend())
#define pb push_back

bool prime(long long a)
{
    for (long long i = 3; i <= sqrt(a); i += 2)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    vector<long long> A;
    rep(i, 2, sqrt(n) + 1)
    {
        while (n % i == 0)
        {
            n /= i;
            A.pb(i);
        }
    }
    if (n > 1)
    {
        A.pb(n);
    }
    if (A[0] == A[A.size() - 1])
    {
        cout << A[0];
    }
    else
    {
        cout << 1;
    }
}