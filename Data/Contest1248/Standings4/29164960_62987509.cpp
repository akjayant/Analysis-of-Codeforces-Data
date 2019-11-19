#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define M 1000000007
#define pi 3.141592653589793
#define pb push_back
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define tc int t;cin>>t;while(t--)
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int>>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    fastio;
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0;i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    if (n == 1)
        cout << a[0] * a[0] << "\n";
    else if (n % 2 == 0) {
        ll x = 0;
        for (int i = 0;i < n/2;i++)
            x += a[i];
        ll y = 0;
        for (int i = n/2;i < n;i++)
            y += a[i];
        cout << x * x + y * y << "\n";
    }
    else {
        ll x = 0;
        for (int i = 0;i < n/2;i++)
            x += a[i];
        ll y = 0;
        for (int i = n/2;i < n;i++)
            y += a[i];
        ll p = x * x + y * y;
        x += a[n/2];
        y -= a[n/2];
        ll q = x * x + y * y;
        cout << max(p, q) << "\n";
    }
}