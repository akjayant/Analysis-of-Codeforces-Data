#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ss second
#define ff first
#define INF 1000000000000000001
#define PI 3.14159265358979323846L
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<int,int> > vii ;
typedef pair<ll,ll> pll ;

int main()
{
    fast;
    int _ = 1;
    cin >> _;
    while(_--)
    {
        int n = 0, x, ans = 0;
        cin >> n;
        ll cnt[n + 1] = {};
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            cnt[x]++;
        }
        for(int i = n - 1; i > 0; i--) cnt[i] += cnt[i + 1];
        for(int i = 1; i <= n; i++)
        {
            if(cnt[i] >= i) ans = i;
        }
        cout << ans << "\n";
    }
    return 0;
}
