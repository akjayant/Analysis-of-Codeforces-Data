#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;

const int N = 10000 + 5;

int n;
char a[N], b[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];


    int vt = INF;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != b[i])
        {
            vt = i;
            break;
        }
    }
    if(vt == INF)
    {
        cout << "Yes" << '\n';
        return;
    }

    bool kt = false;
    for(int i = vt + 1; i <= n; i++)
    {
        if(a[i] == a[vt] && b[i] == b[vt])
        {
            kt = true;
            swap(a[vt], b[i]);
        }
    }

    if(kt == false)
    {
        cout << "No" << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(a[i] != b[i])
        {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

}

/**
TEST:


*/
