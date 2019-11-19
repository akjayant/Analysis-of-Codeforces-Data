#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define M 1000000007LL
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
    ll n, m;
    cin >> n >> m;
    ll l = max(n, m);
    ll f[l + 1];
    f[0] = 1;
    f[1] = 1;
    for (int i = 2;i <= l;i++)
        f[i] = (f[i - 1] + f[i - 2]) % M;
    cout << (2 * (f[m] + f[n] - 1 + M) % M) % M << "\n";
}