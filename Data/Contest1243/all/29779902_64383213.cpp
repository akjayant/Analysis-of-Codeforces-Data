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
        ll n, cnt = 0, ans = 1;
        cin >> n;
        string s, t;
        string a = "", b = "";
        cin >> s >> t;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                a += s[i];
                b += t[i];
                cnt++;
            }
        }
        if(cnt > 2 || cnt == 1) ans = 0;
        if(cnt == 2)
        {
            if(a[0] != a[1] || b[1] != b[0]) ans = 0;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
